# Java 9 & Beyond

### Java 9

##### jshell

Read-Evaluate-Print Loop (REPL)

##### modules and linking

* level of organisation above packages
* reduce size of apps
* coupled with new java linker
* private packages
* fast failure incase method not present

```
java --list-modules
```

##### javadoc

* searchable
* HTML5 compliant
* compatible with the new module hierarchy

##### Collection immutable factory methods 

```
Set<String> seasons = Set.of("winter", "spring", "summer", "fall")
```

##### Stream improvements

* functional programming

```
Stream.iterate("hey", x -> x.length() < 7, x -> x + "y").forEach(System.out::println)
IntStream.range(0, 5).takeWhile(i -> i < 3).forEach(System.out::println)
IntStream.range(0, 5).dropWhile(i -> i < 3).forEach(System.out::println)
Optional.ofNullable(null).stream().forEach(System.out::println)
```

Maybe we will get list comprehensions in the future?

##### multi-release jars 

* specify class implementations for each java version

```
jar root /
  - Foo.class
  - Bar.class
  - META-INF
     - MANIFEST.MF
     - versions
        - 9
           - Foo.class
        - 10
           - Foo.class
```

##### private interface methods

```
interface MyInterface {

  private void printHelper (String verb, int n, int pow) {
    System.out.printf("%d %s is %d%n", n, verb, (int) Math.pow(n, pow));
  }

  default void printSquared (int n) {
    printHelper("squared", n, 2);
  }

  default void printCubed (int n) {
    printHelper("cubed", n, 3);
  }
}

public class MyImplementation implements MyInterface { }
```

### Java 10

##### GraalVM

* new VM
* based on HotSpot and OpenJDK.
* supports Ahead of Time (AOT) compilation
* polyglot programming
* Android Runtime has used AOT compilation since about 2013
* GraalVM combines these two steps to produce machine-native images -- binary code which is created for the particular architecture on which the VM is running.
* Graal provides zero-overhead interoperability between Java, JavaScript, R, Python, Ruby, and C, thanks to the Truffle Language Implementation Framework.

```
const express = require('express');
const app = express();
app.listen(3000);

app.get('/', function(req, res) {
  var text = 'Hello World!';
  const BigInteger = Java.type('java.math.BigInteger');
  text += BigInteger.valueOf(2).pow(100).toString(16);
  text += Polyglot.eval('R', 'runif(100)')[0];
  res.send(text);
})
```

##### local variable type inference 

* var type allows for local type inference
* Local type inference means that var can only be used inside of method bodies or other similar blocks of code. It can't be used to declare instance variables or as the return type of a method, etc.
* Java is still a statically-typed language
* This is different from, for instance, JavaScript, where the type of a variable is dynamic and can change from line to line.

##### Unmodifiable Collection enhancements

```
List<Integer> view = Collections.unmodifiableList(lint);
```

##### Container awarenesss

Docker and Java are finally friends.

### Java 11

##### Single source file launch

```
java Example.java
```

### Java 12

##### switch expressions

* a step toward pattern matching

```
String name = switch(x) {
    case 1 -> "one";
    case 2 -> "two";
    case 3 -> "three";
    default -> throw new IllegalArgumentException("I can only count to 3.");
};

System.out.println(name);
```

##### teeing Collectors

```
import static java.util.stream.Collectors.*

var ints = DoubleStream.of(1, 2, 3, 4, 5)

ints.boxed().collect(teeing(
   summingDouble(e -> e),
   counting(),
   (a,b) -> a/b
  ))
```

### Java 14

##### Multiline text blocks

```
String html3 = """
   <html>
       <body>
           <h1>"I love Java and Java loves me!"</h1>
       </body>
   </html>
   """
```

### Java 14+

##### Java-on-Java compiler with Project Metropolis 

* decouple Java from dependencies on other languages
* allow the VM to optimise itself
* maintainability / simplification

##### Project Amber

**flow typing**
  
```
void alertNChars (Object o) {
  if (o instanceof String s)
    System.out.println("String contains " + s.length() + " characters");
  else System.out.println("not a String");
}
```

**anonymous variables**

```
BiFunction<Integer, Double, String> bids = (i, _) -> String.valueOf(i);
```

**data classes**

* public instance variables
* hashCode()
* equals()
* toString()

```
record Boilerplate (int myInt, double myDouble, String myString) { }
```

**sealed types**

```
sealed interface Car (Make make, Model model) { }

record FossilFuelCar (Make make, Model model) implements Car { }
record ElectricCar   (Make make, Model model) implements Car { }
record HybridCar     (Make make, Model model) implements Car { }
record FuelCellCar   (Make make, Model model) implements Car { }
```

##### Project Loom

_lightweight multithreading_

* application-level Thread-like abstraction called a Fiber.
* VM-level multithreading (rather than OS-level)
* coroutines
* tail-call optimisation
* lightweight user-mode Fiber

##### Project Valhalla

* value types
* generic specialisation
* reified generics

### Refferences

1. [20 Reasons to Move On from Java 8](https://dev.to/awwsmm/20-reasons-to-move-on-from-java-8-1dio)
2. [Keeping up with Java 9, 10, 11, and Beyond](https://4comprehension.com/keeping-up-with-java-9-10-11-and-beyond/)
3. [From Java 8 to Java 11 – Quick Guide](https://codete.com/blog/java-8-java-11-quick-guide)
4. [Java 8 v/s Java 11](https://www.javatpoint.com/java-8-vs-java-11)
5. [JDK 17: The new features in Java 17](https://www.infoworld.com/article/3606833/jdk-17-the-new-features-in-java-17.html)
6. [Java Versions and Features](https://www.marcobehler.com/guides/a-guide-to-java-versions-and-features)