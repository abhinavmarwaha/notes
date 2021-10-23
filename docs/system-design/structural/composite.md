# Composite

lets you compose objects into tree structures and then work with these structures as if they were individual objects.

### When

* Use the Composite pattern when you have to implement a tree-like object structure.
* Use the pattern when you want the client code to treat both simple and complex elements uniformly.


| Pros | Cons |
|------|------|
|You can work with complex tree structures more conveniently: use polymorphism and recursion to your advantage.| It might be difficult to provide a common interface for classes whose functionality differs too much. In certain scenarios, you’d need to overgeneralize the component interface, making it harder to comprehend.|
|**Open/Closed Principle**: You can introduce new element types into the app without breaking the existing code, which now works with the object tree.|   |