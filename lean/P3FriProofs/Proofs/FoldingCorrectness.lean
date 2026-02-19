-- Correctness proofs connecting the P3 FRI Rust implementation to ArkLib
-- Preconditions mirror the original Plonky3 debug_assert! macros:
--   debug_assert!(log_current_height > log_final_height)
--   debug_assert!(log_current_height > next_log_height)  [when Some]

import Hax
import ArkLib.ProofSystem.Fri.Spec.SingleRound
import ArkLib.ProofSystem.Fri.Spec.General
import ArkLib.Data.Polynomial.SplitFold
import ArkLib.ProofSystem.Fri.Domain
import p3_fri_kernel

namespace P3FriProofs

open Polynomial

/-!
# FRI Folding Correctness

## ArkLib context

`ArkLib.ProofSystem.Fri.Spec.SingleRound` models one FRI round with:
- `s : Fin (k+1) → ℕ+` — folding degree per round (our `result` is one value of `s`)
- Domain size constraint: `(2^(∑ i, (s i).1)) * d ≤ 2^n`

`ArkLib.Data.Polynomial.SplitFold` provides:
- `splitNth f n i` — n-way split of polynomial f
- `foldNth n f α`  — fold with powers of α (core FRI step)

## Connection

`compute_log_arity_for_round` returns `log₂(arity)` = `s i` for one round.
It enforces: result ≤ log_current − log_final  AND  result ≤ max_log_arity.
-/

/-! ## Helpers -/

-- Convert log-arity to actual arity value
def log_to_arity (log_arity : Nat) : Nat := 2 ^ log_arity

-- Domain height after folding by log_arity
def domain_height_after_fold (current_height fold_amount : Nat) : Nat :=
  current_height - fold_amount

/-! ## Folding degree connection -/

-- Warming-up version (without ℕ+):
-- The result of compute_log_arity_for_round is some natural number.
-- Full version needs max_log_arity > 0 to obtain result > 0 and wrap it as ℕ+.
theorem compute_log_arity_gives_folding_degree
  (log_current_height : USize64)
  (next_input_log_height : Core_models.Option.Option USize64)
  (log_final_height : USize64)
  (max_log_arity : USize64)
  (result : USize64)
  (_h_gt      : log_current_height.toNat > log_final_height.toNat)
  (_h_result  : P3_fri_kernel.compute_log_arity_for_round
                  log_current_height next_input_log_height
                  log_final_height max_log_arity = .ok result)
  -- Warming-up: just ∃ s : Nat; full version would use ℕ+ + h_max_pos > 0
  : ∃ s : Nat, s = result.toNat :=
  ⟨result.toNat, rfl⟩

/-! ## Domain size constraints -/

-- Result ≤ distance to final height (None case)
-- Reflects debug_assert!(log_current_height > log_final_height)
theorem arity_respects_target_distance
  (log_current_height : USize64)
  (log_final_height : USize64)
  (max_log_arity : USize64)
  (result : USize64)
  (h_gt : log_current_height.toNat > log_final_height.toNat)
  (h_result : P3_fri_kernel.compute_log_arity_for_round
                log_current_height Core_models.Option.Option.None
                log_final_height max_log_arity = .ok result)
  : result.toNat ≤ log_current_height.toNat - log_final_height.toNat := by
  sorry

-- Result ≤ max_log_arity (always; reflects final min-with-cap)
theorem arity_respects_max_bound
  (log_current_height : USize64)
  (next_input_log_height : Core_models.Option.Option USize64)
  (log_final_height : USize64)
  (max_log_arity : USize64)
  (result : USize64)
  (h_gt : log_current_height.toNat > log_final_height.toNat)
  (h_result : P3_fri_kernel.compute_log_arity_for_round
                log_current_height next_input_log_height
                log_final_height max_log_arity = .ok result)
  : result.toNat ≤ max_log_arity.toNat := by
  sorry

-- Result ≤ distance to next input (Some case)
-- Reflects debug_assert!(log_current_height > next_log_height)
theorem arity_respects_next_input
  (log_current_height : USize64)
  (next_log_height : USize64)
  (log_final_height : USize64)
  (max_log_arity : USize64)
  (result : USize64)
  (h_gt_final : log_current_height.toNat > log_final_height.toNat)
  (h_gt_next  : log_current_height.toNat > next_log_height.toNat)
  (h_result : P3_fri_kernel.compute_log_arity_for_round
                log_current_height (Core_models.Option.Option.Some next_log_height)
                log_final_height max_log_arity = .ok result)
  : result.toNat ≤ log_current_height.toNat - next_log_height.toNat := by
  sorry

/-! ## Domain reduction -/

-- After folding, the domain height stays ≥ log_final_height
-- (we never fold past the target)
theorem folding_respects_final_height
  (log_current_height : USize64)
  (log_final_height : USize64)
  (max_log_arity : USize64)
  (result : USize64)
  (h_gt : log_current_height.toNat > log_final_height.toNat)
  (h_result : P3_fri_kernel.compute_log_arity_for_round
                log_current_height Core_models.Option.Option.None
                log_final_height max_log_arity = .ok result)
  : domain_height_after_fold log_current_height.toNat result.toNat
      ≥ log_final_height.toNat := by
  -- follows from arity_respects_target_distance: result ≤ current - final
  sorry

/-! ## Multi-round consistency -/

-- Two consecutive rounds together stay within total allowed folds.
-- Reflects that both calls satisfy their respective debug_asserts.
theorem round_consistency_preserved
  (round1_arity round2_arity : USize64)
  (initial_height intermediate_height final_height : USize64)
  (max_arity : USize64)
  (h_gt1 : initial_height.toNat > final_height.toNat)
  (h_gt2 : intermediate_height.toNat > final_height.toNat)
  (h_gt_int : initial_height.toNat > intermediate_height.toNat)
  (h1 : P3_fri_kernel.compute_log_arity_for_round
          initial_height
          (Core_models.Option.Option.Some intermediate_height)
          final_height max_arity = .ok round1_arity)
  (h2 : P3_fri_kernel.compute_log_arity_for_round
          intermediate_height Core_models.Option.Option.None
          final_height max_arity = .ok round2_arity)
  : round1_arity.toNat + round2_arity.toNat
      ≤ initial_height.toNat - final_height.toNat := by
  sorry

/-! ## Concrete example -/

-- height 10 → final 3, no next, large cap: result = 7 = 10 - 3
-- log_to_arity 7 = 128 is the actual arity used in FRI
example :
  ∃ result,
    P3_fri_kernel.compute_log_arity_for_round
      ⟨10⟩ Core_models.Option.Option.None ⟨3⟩ ⟨100⟩ = .ok result
    ∧ result.toNat = 7
    ∧ log_to_arity 7 = 128 := by
  sorry

end P3FriProofs
