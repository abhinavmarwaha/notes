# Garbage Collection

The main concept of memory management in JavaScript is `reachability`.

### Internal algorithms

The basic garbage collection algorithm is called `mark-and-sweep`.

The following “garbage collection” steps are regularly performed:

* The garbage collector takes roots and “marks” (remembers) them.
* Then it visits and “marks” all references from them.
* Then it visits marked objects and marks their references. All visited objects are remembered, so as not to visit the same object twice in the future.
* …And so on until every reachable (from the roots) references are visited.
* All objects except marked ones are removed.

### Optimisations

* **Generational collection** – objects are split into two sets: “new ones” and “old ones”. Many objects appear, do their job and die fast, they can be cleaned up aggressively. Those that survive for long enough, become “old” and are examined less often.
* **Incremental collection** – if there are many objects, and we try to walk and mark the whole object set at once, it may take some time and introduce visible delays in the execution. So the engine tries to split the garbage collection into pieces. Then the pieces are executed one by one, separately. That requires some extra bookkeeping between them to track changes, but we have many tiny delays instead of a big one.
* **Idle-time collection** – the garbage collector tries to run only while the CPU is idle, to reduce the possible effect on the execution.