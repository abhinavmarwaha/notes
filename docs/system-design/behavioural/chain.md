# Chain of Responsibility

lets you pass requests along a chain of handlers. Upon receiving a request, each handler decides either to process the request or to pass it to the next handler in the chain.

### When?

* Use the Chain of Responsibility pattern when your program is expected to process different kinds of requests in various ways, but the exact types of requests and their sequences are unknown beforehand.
* Use the pattern when it’s essential to execute several handlers in a particular order.
* Use the CoR pattern when the set of handlers and their order are supposed to change at runtime.


| Pros | Cons |
|------|------|
|You can control the order of request handling.|Some requests may end up unhandled.|
|You avoid tight coupling between concrete products and client code.|      |
|**Single Responsibility Principle**: You can decouple classes that invoke operations from classes that perform operations.|   |
|**Open/Closed Principle**: You can introduce new handlers into the app without breaking the existing client code.|   |