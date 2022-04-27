# Transaction

can't break it.

### ACID

* atomicity
* consistency - after/before
* durable - latest updates even if system fails
* isolation - txn should be isolated

### schedule / serializability

### Equavalence

* result - same I/O
* view 
* Conflict Equivalence

View equivalent schedules are view serializable and conflict equivalent schedules are conflict serializable. All conflict serializable schedules are view serializable too.

### States

* active
* partially commited
* failed
* commited
* aborted

### Concurrent txn

* lost update
* dirty read
* unrepeatable read
* incorrect summary

* reduced wait time
* high throughput
* high resource utilization

### Schedule

* serial
* complete
* recoverable
* cascadeless
* strict

### concurrency control

* shared lock
* exclusive lock

2 phase locking protocol

### BASE


    Basically Available: This constraint states that the system does guarantee the availability of the data as regards CAP Theorem; there will be a response to any request. But, that response could still be ‘failure’ to obtain the requested data or the data may be in an inconsistent or changing state, much like waiting for a check to clear in your bank account.
    Soft state: The state of the system could change over time, so even during times without input there may be changes going on due to ‘eventual consistency,’ thus the state of the system is always ‘soft.’
    Eventual consistency: The system will eventually become consistent once it stops receiving input. The data will propagate to everywhere it should sooner or later, but the system will continue to receive input and is not checking the consistency of every transaction before it moves onto the next one. Werner Vogel’s article “Eventually Consistent – Revisited” covers this topic is much greater detail.
