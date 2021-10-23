# Decorator

lets you attach new behaviors to objects by placing these objects inside special wrapper objects that contain the behaviors.

### Why?

* Use the Decorator pattern when you need to be able to assign extra behaviors to objects at runtime without breaking the code that uses these objects.
* Use the pattern when it’s awkward or not possible to extend an object’s behavior using inheritance.

| Pros | Cons |
|------|------|
|You can extend an object’s behavior without making a new subclass.|It’s hard to remove a specific wrapper from the wrappers stack.|
|You can add or remove responsibilities from an object at runtime.|It’s hard to implement a decorator in such a way that its behavior doesn’t depend on the order in the decorators stack.|
|You can combine several behaviors by wrapping an object into multiple decorators.|The initial configuration code of layers might look pretty ugly.|
|**Single Responsibility Principle**: You can divide a monolithic class that implements many possible variants of behavior into several smaller classes.|   |