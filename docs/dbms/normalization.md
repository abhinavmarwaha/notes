# Normalization

avoid data redundancy, insertion, update & deletion anomaly

### Functional dependency

* Multivalued
* Trivial
* Non-Trivial
* Transitive

### Normal forms in SQL

* 1NF - unique records, table cell 1 value
* 2NF - primary key deos not depend on subset of cadidate key
* 3NF - not transitive dependency
* BCNF (Boyce-Codd Normal Form)
  * A relation is in BCNF, if and only if, every determinant is a Form (BCNF) candidate key.
  * A relation is in BCNF iff, X is superkey for every functional dependency (FD) X?Y in given relation.
* 4NF -  NO (two or more, independent and multivalued data describing the relevant entity)
* 5NF - it cannot be decomposed into any number of smaller tables without loss of data
* 6NF - no standard yet


