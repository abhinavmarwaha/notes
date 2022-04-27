# RDBMS

B+ trees

### degree of relation

* 1-1
* 1-many
* many-many

### Constraints

* cardinality ratio / degree 
* participation constraints

### Keys

* candidate - unique,  nC(floor(n/2))
* super - cadidate + X 
* primary - chosen cadidate
* alternate
* foreign

### ER model

### Relational algebra

| Operation(Symbols) | Purpose |
| ----------- | ----------- |
| Select(σ) | subset of tuples given condition |
| Projection(π) | The projection eliminates all attributes of the input relation but those mentioned in the projection list. |
| Union Operation(∪) | all in A or/and in B |
| Set Difference(-) | A not B |
| Intersection(∩) | both in A and B |
| Cartesian Product(X) | merge columns of 2 tables|
| Inner Join | Inner join, includes only those tuples that satisfy the matching criteria. |
| Theta Join(θ) | The general case of JOIN operation is called a Theta join. It is denoted by symbol θ. |
| EQUI Join | When a theta join uses only equivalence condition, it becomes a equi join. |
| Natural Join(⋈) | Natural join can only be performed if there is a common attribute (column) between the relations. |
| Outer Join | In an outer join, along with tuples that satisfy the matching criteria. |
| Left Outer Join | In the left outer join, operation allows keeping all tuple in the left relation. |
| Right Outer join | In the right outer join, operation allows keeping all tuple in the right relation. |
| Full Outer Join | In a full outer join, all tuples from both relations are included in the result irrespective of the matching condition. |