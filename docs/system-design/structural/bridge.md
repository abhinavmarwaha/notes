# Bridge

lets you split a large class or a set of closely related classes into two separate hierarchies—abstraction and implementation—which can be developed independently of each other.

### When?

* Use the Bridge pattern when you want to divide and organize a monolithic class that has several variants of some functionality (for example, if the class can work with various database servers).
* Use the pattern when you need to extend a class in several orthogonal (independent) dimensions.
* Use the Bridge if you need to be able to switch implementations at runtime.


| Pros | Cons |
|------|------|
|You can create platform-independent classes and apps.|You might make the code more complicated by applying the pattern to a highly cohesive class.|
|The client code works with high-level abstractions. It isn’t exposed to the platform details.|      |
|**Single Responsibility Principle**: You can introduce new abstractions and implementations independently from each other.|   |
|**Open/Closed Principle**: You can focus on high-level logic in the abstraction and on platform details in the implementation.|   |