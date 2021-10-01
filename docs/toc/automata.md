# Automata Theory

A study of
* The theory of formal languages
* The mathematical modeling of systems
* The computability of a problem/function
* What is a computer

### Alphabets (Σ)

A finite set of symbols.

### Strings

A finite sequence of symbols from an alphabet.

* Empty string: ε
* Concatination: ω=abd, α=ce, ωα=abdce
* Exponentiation: ω=abd, ω^3=abdabdabd, ω^0=ε
* Reversal: ω=abd, ω^R = dba
* Σ^k = set of all k-length strings formed by the
* symbols in Σ
* Σ^1 != Σ
* Kleene Closure: Σ* = Σ^0 ∪ Σ^1 ∪ Σ^2 ∪… = ∪^k≥0 Σ^k
* Σ+ = Σ* - ε

### Languages

A set of strings over an alphabet. φ != {ε}.

### Finite Automata / Finite State Machines

**Deterministic Finite Automata**

(Q, Σ, δ, q0, F)

* Q: finite set of states
* Σ:finite input alphabet
* δ: transition function (Q × Σ -> Q)
* q0: initial state (only 1)
* F: set of final states (0 or more)
* one transition only for each input symbol from each state.

### Transition Table

### Transition Diagram

### Languages Accepted by DFAs

The language contains L(M) all input strings accepted by L.

* There exist languages which are not Regular: There is no DFA that accepts such a language.

### Nondeterministic Finite Accepter (NFA)

* The lambda symbol never appears on the input tape
* NFAs are interesting because we can express languages easier than DFAs
* NFAs accept the Regular Languages

### Equivalence

M1 = M2 iff L(M1) = L(M2)

### NFA to DFA

