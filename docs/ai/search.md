# Search

### Why?

* To achieve goals or to maximize our utility we need to predict what the result of our actions in the future will be.
* There are many sequences of actions, each with their own utility.
* We want to find, or search for, the best one.

### Problem

* initial state
* actions: set of possible actions in current state x.
* transition model: Result(x,a) = state that follows from applying action
* goal test
* path cost (additive)
* A solution is a sequence of steps / path

### Trees

* Exploration of state space by generating successors of already-explored states (a.k.a.~expanding states).
* Every states is evaluated: is it a goal state?
* **Repeated** states: Failure to detect repeated states can turn a linear problem into an exponential one!
* must keep track of all possible states (uses a lot of memory)

##### vs Graph Search

```
**function** TREE-SEARCH(problem) **returns** a solution, or failure
  initialize the frontier using the initial state of problem
  **loop do**
    **if** the frontier is empty **then return** failure
    choose a leaf node and remove it from the frontier
    **if** the node contains a goal state **then return** the corresponding solution
    expand the chosen node, adding the resulting nodes to the frontier

**function** GRAPH-SEARCH(problem) **returns** a solution, or failure
  initialize the frontier using the initial state of problem
  **initialize the explored set to be empty**
  loop do
    **if** the frontier is empty **then return** failure
    choose a leaf node and remove it from the frontier
    **if** the node contains a goal state **then return** the corresponding solution
    **_add the node to the explored set_**
    expand the chosen node, adding the resulting nodes to the frontier
      **only if not in the frontier or explored set**
```

### Implementation

* A **state** is a (representation of) a physical configuration
* A **node** n is a data structure constituting part of a search tree contains info such as: _state, parent node, action, path cost g(n)._
* The **Expand function** creates new nodes, filling in the various fields and using the SuccessorFn of the problem to create the corresponding states.

### Search Strategy 

_picking the order of node expansion_

##### Evaluation Metrics

* completeness
* time complexity
* space complexity
* optimality (_least-cost_)

* b: maximum branching factor
* d: depth of the least-cost solution
* m: maximum depth of the state space (may be ∞)

### Uninformed Search

While searching you have no clue whether one non-goal state is better than any other. Your search is blind. You don’t know if your current exploration is likely to be fruitful.

Various blind strategies:

* Breadth-first search
* Uniform-cost search
* Depth-first search
* Iterative deepening search
* Bi-Directional Search

| Criterion | Breadth- First | Uniform- Cost | Depth- First | Depth- Limited | Iterative Deepening | Bidirectional (if applicable) |
|---|---|---|---|---|---|---|
| Time | bd | b | bm | b' | bd | 64n |
| Space | b | b | bm | bl | bd | ber |
| Optimal? | Yes | Yes | No | No | Yes | Yes |
| Complete? | Yes | Yes | No | Yes, if I > d | Yes | Yes |

### Heuristic Search

* **Direct** techniques (blind search) are not always possible
* **Weak** techniques can be effective if applied correctly on the right kinds of tasks. (Heuristic Search Techniques)

* Heuristic search techniques make use of **domain specific information** - a heuristic.

### Generate and Test

```
do while goal not accomplished
generate a possible solution
test solution to see if it is a goal
```

### Hill Climbing

_Variation_ on generate-and-test:

* generation of next state depends on feedback from the test procedure.
* Test now includes a heuristic function that provides a guess as to how good each possible state is.
* There are a number of ways to use the information returned by the test procedure.
* Searching for a goal state = Climbing to the top of a hill

##### Simple Hill Climbing

* Use heuristic to move only to states that are better than the current state.
* Always move to better state when possible.
* The process ends when all operators have been applied and none of the resulting states are better than the current state.

Problems:

* Will terminate when at local optimum.
* The order of application of operators can make a big difference.
* Can’t see past a single move in the state space.

##### Steepest-Ascent Hill Climbing (Gradient Search)

Simulated Annealing

• Based on physical process of annealing a
metal to get the best (minimal energy) state.
• Hill climbing with a twist:
– allow some moves downhill (to worse states)
– start out allowing large downhill moves (to
much worse states) and gradually allow only
small downhill moves.

A variation of hill climbing in which, at the
beginning of the process, some downhill
moves may be made. • To do enough exploration of the whole
space early on, so that the final solution is
relatively insensitive to the starting state.

• Lowering the chances of getting caught at a
local maximum, or plateau, or a ridge.

The search initially jumps around a lot,
exploring many regions of the state space.

• The jumping is gradually reduced and the
search becomes a simple hill climb (search
for local optimum).

