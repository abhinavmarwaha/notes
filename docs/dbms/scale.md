* Scaling

### Query optimization 

and connection pool implementation

### Vertical / up

### CQRS

command query responsibility segregation

### Partition

* data center wise

### horizontal

### Sharding

### SQL

* cluster proxy
* shared proxy

### NoSQL

* shards/nodes are equal (no master-slave)
* gossip/epidemic protocol

### Master

Master-Master: This is similar to Master-Slave architecture, the only difference is that both the nodes are masters and replica at the same time i.e. there will be circular replication between the nodes. It is most recommended to configure both the servers to log the transactions from the replication thread (log-slave-updates) but it ignores its own already replicated transactions (set replicate-same-server-id to 0) to prevent infinite loops in the replication.

Master-Slave: In this, as each data has only one master, so consistency is not difficult.   

Advantages of Master-Master Database:

    Masters can be distributed across the network that means in several physical sites master can be located.
    If the one master fails, other masters will start updating the database.

Disadvantages of Master-Master Database:

    This introduces some communication latency, and eager replication systems are complex in this architecture.
    Multi-Master replication systems will be mostly loosely consistent, i.e. asynchronous, lazy and violating ACID properties.
    As the number of nodes involved rises and the required latency decreases, so Issues such as conflict resolution can become intractable.