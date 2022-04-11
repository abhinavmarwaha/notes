# Planning

Generate sequences of actions to perform tasks and achieve.
objectives -> States, actions and goals.

* Search for solution over abstract space of plans.
* Classical planning environment: fully observable, deterministic, finite, static(change happens only when the agent acts) and discrete(in time, action, objects, and effects).

### Planning vs. Problem Solving

* States, goals, and actions are decomposed into sets of sentences (usually in first-order logic)
* Search often proceeds through plan space rather than state space (though first we will talk about state-space planners)
* Subgoals can be planned independently, reducing the complexity of the planning problem

### Planning Language

* **Expressive** enough to describe a wide variety of problems.
* **Restrictive** enough to allow efficient algorithms to operate on it.
* Planning algorithm should be able to take advantage of the **logical structure** of the problem.

* STRIPS stands for STanford Research Institute Problem Solver
* ADL: Action Description Language
