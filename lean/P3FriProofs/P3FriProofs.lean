-- P3 FRI Proofs: Connecting extracted Rust code to ArkLib specifications
import Hax
-- there are some name conflicts between ArkLib and Hax (for example both define ToNat).
-- to solve such conflicts we should import specific modulees of ArkLib (instead of import ArkLib)
import ArkLib.ProofSystem.Fri.Spec.SingleRound
import ArkLib.ProofSystem.Fri.Spec.General
import ArkLib.Data.Polynomial.SplitFold
import ArkLib.ProofSystem.Fri.Domain

-- Import the extracted p3_fri_kernel from the rust project
-- extracted is a symlink
-- import «/home/natalie/p3-hax-lean-fri-pipeline/rust/p3_fri_kernel/proofs/lean/extraction/p3_fri_kernel»
import p3_fri_kernel

namespace P3FriProofs

/-!
# Connecting P3 FRI Implementation to ArkLib Specifications

## Key ArkLib Components

From `ArkLib.ProofSystem.Fri.Spec.SingleRound`:
- `s : Fin (k + 1) → ℕ+` - folding degree for each round
- `evalDomain D x s` - evaluation domain
- Domain size constraint: `(2 ^ (∑ i, (s i).1)) * d ≤ 2 ^ n`

From `ArkLib.Data.Polynomial.SplitFold`:
- `splitNth f n i` - splits polynomial into n components
- `foldNth n f α` - folds using powers of α

## Connection

`compute_log_arity_for_round` computes `log₂(arity)` where `arity = 2^s` in ArkLib.
-/

-- Helper: Convert between log-space (Rust) and actual values (ArkLib)
def log_to_arity (log_arity : Nat) : Nat := 2 ^ log_arity

end P3FriProofs
