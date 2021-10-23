# Builder

lets you construct complex objects step by step. The pattern allows you to produce different types and representations of an object using the same construction code.

### When?

* Use the Builder pattern to get rid of a “telescopic constructor”.
* Use the Builder pattern when you want your code to be able to create different representations of some product (for example, stone and wooden houses).
* Use the Builder to construct Composite trees or other complex objects.


| Pros | Cons |
|------|------|
|You can construct objects step-by-step, defer construction steps or run steps recursively.|The overall complexity of the code increases since the pattern requires creating multiple new classes.|
|You can reuse the same construction code when building various representations of products.|      |
|Single Responsibility Principle. You can isolate complex construction code from the business logic of the product.|   |