# Hax Lean Backend — Missing Lemmas & Gaps

> **Context:** Discovered while writing formal correctness proofs for the Plonky3 FRI kernel
> (`compute_log_arity_for_round`) using the Hax-extracted Lean 4 model.
> Each item below is a concrete blocker or friction point encountered during proof development.

---

## 1. No `@[simp]` Discriminator Lemmas for `RustM` Constructors

**Problem:** `RustM` is an inductive type with three constructors (`ok | fail | div`), but it lacks
no-confusion `@[simp]` lemmas. When a branch is structurally impossible — e.g., the hypothesis
`h : x = .fail e` combined with `h_result : .fail e = .ok r` — calling `simp only [h] at h_result`
makes no progress. The proof must fall back to full `simp` (slow, opaque) or manual `contradiction`.

**Missing:**

```lean
@[simp] theorem RustM.ok_ne_fail : (.ok a) ≠ (.fail e)
@[simp] theorem RustM.ok_ne_div  : (.ok a) ≠ .div
@[simp] theorem RustM.fail_ne_ok : (.fail e) ≠ (.ok a)
@[simp] theorem RustM.div_ne_ok  : .div ≠ (.ok a)
```

**Suggested fix:** Add a `@[simp]` discriminator simp set for `RustM`, analogous to how Lean's
standard library handles `Option.some_ne_none`.

---

## 2. No Characterisation Lemmas for Checked Arithmetic (`-?`, `+?`, `*?`)

**Problem:** The checked subtraction operator `-?` (and its siblings `+?`, `*?`) is not `@[simp]`
and provides no `iff` lemma connecting its `RustM` result to natural-number arithmetic. Proofs
must do a raw `cases h : (a -? b)` and reason about the resulting value without any algebraic
support.

**Missing:**

```lean
theorem USize64.checked_sub_ok :
    a -? b = .ok r ↔ b.toNat ≤ a.toNat ∧ r.toNat = a.toNat - b.toNat

theorem USize64.checked_sub_fail :
    a -? b = .fail _ ↔ a.toNat < b.toNat

-- Analogous lemmas needed for +? and *?
theorem USize64.checked_add_ok  : ...
theorem USize64.checked_mul_ok  : ...
```

**Suggested fix:** Add `_ok_iff` / `_fail_iff` characterisation lemmas for all checked arithmetic
operators, marked `@[simp]`.

---

## 3. Bool `if`-then-else vs. `ite` Mismatch in Generated Code

**Problem:** Hax emits `if (b : Bool) then x else y`, which Lean 4 desugars to `Bool.casesOn b y x`
— **not** `ite` (the Prop-valued if-then-else). The standard tactic `split_ifs` only handles `ite`,
so it silently fails on Hax-generated code. Proof scripts must instead use:

```lean
cases h : (decide (condition)) with
| true  => ...
| false => ...
```

This is a non-obvious footgun: `split_ifs` appears to do nothing and leaves the goal unchanged,
with no error or warning.

**Suggested fix:** Either generate Prop-guarded `ite` from boolean conditions in the Lean backend,
or provide a `split_bools` tactic (or document that `split_ifs` does not apply and show the
correct workaround).

---

## 4. No Bridge Lemma for `Machine_int.lt` → Prop

**Problem:** `Rust_primitives.Hax.Machine_int.lt x y` is defined as `pure (decide (x < y))` and
is `@[simp]`. After unfolding, the goal contains `decide (x < y) : Bool` embedded in expressions.
There is no one-step lemma to restate this as a Prop-valued fact; proofs must manually apply
`of_decide_eq_true` or `of_decide_eq_false` after an explicit `cases` split.

**Missing:**

```lean
theorem Machine_int.lt_ok_true  : Machine_int.lt a b = .ok true  ↔ a < b
theorem Machine_int.lt_ok_false : Machine_int.lt a b = .ok false ↔ ¬ (a < b)
```

**Suggested fix:** Add the two `iff` bridge lemmas above, marked `@[simp]`, so that after
unfolding `Machine_int.lt` the boolean evidence is automatically converted to a Prop.

---

## 5. No `omega` / `norm_cast` Integration for `USize64`

**Problem:** The `omega` tactic operates on `Nat` and `Int`. `USize64` values require manual
`.toNat` projections and explicit use of `USize64.le_iff_toNat_le` (and similar lemmas) at every
arithmetic step. This makes even simple linear arithmetic goals verbose and fragile.

**Missing:** `@[norm_cast]` or `@[push_cast]` attributes on `USize64` coercion lemmas, so that:

```lean
-- Goal: a.toNat ≤ b.toNat
-- Currently requires: exact USize64.le_iff_toNat_le.mp h
-- With norm_cast: exact_mod_cast h   (or omega closes it directly)
```

**Suggested fix:** Annotate `USize64.le_iff_toNat_le`, `USize64.lt_iff_toNat_lt`, and the
`toNat_*` arithmetic lemmas with `@[norm_cast]` / `@[push_cast]`, enabling `omega` to close
`USize64` arithmetic goals automatically.

---

## 6. `Core_models.Option` Constructor Order Reversed vs. Stdlib

**Problem:** `Core_models.Option.Option` is an inductive with `Some` as constructor 0 and `None`
as constructor 1 — the **opposite** of Lean's standard `Option` (`none` first, `some` second).
This silently breaks the idiomatic `rcases h with _ | ⟨v⟩` pattern (which assumes None-first
ordering), causing proofs to work on the wrong branch with no type error.

**Suggested fix:** Add a documentation note in the generated file header (or in the Hax Lean
backend documentation) warning that `Core_models.Option` constructor order differs from
`Lean.Option`, and show the correct `rcases` pattern:

```lean
-- Correct for Core_models.Option (Some=0, None=1):
rcases h with ⟨v⟩ | _   -- Some case first, None case second
```

---

## Summary

| # | Gap | Severity | Suggested Fix |
|---|-----|----------|---------------|
| 1 | `RustM` no-confusion `@[simp]` lemmas | **High** | Add discriminator simp set |
| 2 | Checked-arith (`-?`/`+?`/`*?`) `iff` lemmas | **High** | Add `_ok_iff` / `_fail_iff` lemmas |
| 3 | Bool `if` vs. `ite` in generated code | **High** | Generate `ite` or add `split_bools` tactic |
| 4 | `Machine_int.lt` → Prop bridge lemmas | **Medium** | Add `lt_ok_true` / `lt_ok_false` |
| 5 | `USize64` `omega` / `norm_cast` support | **Medium** | Add `@[norm_cast]` on coercion lemmas |
| 6 | `Core_models.Option` constructor order | **Low** | Documentation / warning in generated header |
