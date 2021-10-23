# Anti Patterns

### ECS (Entity-Component derivatives)

The pattern has nothing to do with OOP. It introduces severe limitations, locking developers all the way down to procedural programming. However, it helps to reduce blast radius from inexperienced devs in big teams (reminds me of microservices and Kubernetes somehow).
ECS is based on a Service Locator in disguise. Look at the way systems find components to execute on, you'll get the idea.

It's very difficult to write strict ECS code. Developers end up breaking the pattern:
"Because purist-ecs is basically fucking unusable."
- A popular Unity/C# programmer who's name won't be disclosed.

### MVC

Just use an object composition instead. Controller is the especially problematic bit.
Nearly all objects ending with -er are wrong:

### DI Container (or IoC Container)

A more descriptive name to this anti-pattern would be a "Service Locator Container" or "Service Locator Injection".
Yet it helps to mitigate limitations of MonoBehaviour design. Inability to use constructors is otherwise a huge problem.