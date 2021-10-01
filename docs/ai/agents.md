# Agents

* perceiving its environment through sensors
* acting upon that environment through actuators
* = architecture + program

### Agent Function

```
[f: P* -> A]
```

### Rationality

* expected to maximize its performance measure.
* Rationality is distinct from omniscience (all-knowing with infinite knowledge)

### Types

##### Table Driven

```
function TABLE-DRIVEN-AGENT(percept) returns an action

  persistent: perepts: a sequence, initially empty
              table: a table of actions, indexed by percept sequences, initially fully specified

  append perept to the end of percepts

  action-LoOKUP(percepts, table)
```

##### Simple reflex agents

```
function SIMPLE-REFLEX-AGENT(Pereept) returns an action
  
  persistent: rules: a set of condition-action rules

  state<-INTERPRET-INPUT(percept)
  rule<-RULE-MATCH(state, rules)
  action<-rule.ACTION

  return action
```

##### Model-based reflex agents

```
function MoDEL-BASED-REFLEX-AGENT(percept) returns an action

  persistent: state: the agent's current conception of the world state
              model: a description of how the next state depends on current state and action
              rules: a set of condition-action rules
              action: the most recent action, initially none

  state<-UPDATE-STATE(state, aetion, pereept, model)
  rule<-RULE-MATCH(state, rules)
  action<-rule.ACTION

  return action
```

##### Goal-based

* Knowing about the current state of the environment is not always enough to decide what to do (e.g. decision at a road junction)
* The agent needs some sort of goal information that describes situations that are desirable
* The agent program can combine this with information about the results of possible actions in order to choose actions that achieve the goal
* Usually requires search and planning

**Vs Reflex**

* Although goal-based agents appears less efficient, it is more flexible because the knowledge that supports its decision is represented explicitly and can be modified
* On the other hand, for the reflex-agent, we would have to rewrite many condition-action rules
* The goal based agent's behavior can easily be changed
* The reflex agent's rules must be changed for a new situation

##### Utility-based

* Goals alone are not really enough to generate high quality behavior in most environments – they just provide a binary distinction between happy and unhappy states A more general performance measure should allow a comparison of different world states according to exactly how happy they would make the agent if they could be achieved
* Happy – Utility (the quality of being useful)
* A utility function maps a state onto a real number which describes the associated degree of happiness

##### Learning agents

* _Turing_ – instead of actually programming intelligent machines by hand, which is too much work, build learning machines and then teach them
* Learning also allows the agent to operate in initially __unknown environments__ and to become more competent than its initial knowledge alone might allow

* **Learning element** – responsible for making improvements
* **Performance element** – responsible for selecting external actions.
  * Learning element uses feedback from the critic on how the agent is doing and determines how the performance element should be modified to do better in the future
* **Problem generator** is responsible for suggesting actions that will lead to a new and informative experiences.