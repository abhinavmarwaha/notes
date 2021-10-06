# Classes

```
private class MyClass extends MySuperClass implements YourInterface {
    // field, constructor, and
    // method declarations
}
```

* Member variables -> fields.
* Variables in a method or block of code -> local variables.
* Variables in method declarations -> parameters.

### Overloading

```
public class DataArtist {
    ...
    public void draw(String s) {
        ...
    }
    public void draw(int i) {
        ...
    }
    public void draw(double f) {
        ...
    }
    public void draw(int i, double f) {
        ...
    }
}
```

### Arbitrary no. of Parameters

```
public PrintStream printf(String format, Object... args)
```

### Creating objects


* Declaration: `type name;`
* Instantiation: `new Class()`
* Initialization: `new Class()`

### This

### Access Specifier

| Modifier | Class | Package | Subclass | World |
|---|---|---|---|---|
| public | Y | Y | Y | Y |
| protected | Y | Y | Y | N |
| no modifier | Y | Y | N | N |
| private | Y | N | N | N |

### NestedClass

```
class OuterClass {
    ...
    <access> class NestedClass {
        ...
    }
}
```

### Why

* It is a way of logically grouping classes that are only used in one place
* It increases encapsulation
* It can lead to more readable and maintainable code

### Shadowing

If a declaration of a type (such as a member variable or a parameter name) in a particular scope (such as an inner class or a method definition) has the same name as another declaration in the enclosing scope, then the declaration shadows the declaration of the enclosing scope.

```
public class ShadowTest {

    public int x = 0;

    class FirstLevel {

        public int x = 1;

        void methodInFirstLevel(int x) {
            System.out.println("x = " + x);
            System.out.println("this.x = " + this.x);
            System.out.println("ShadowTest.this.x = " + ShadowTest.this.x);
        }
    }

    public static void main(String... args) {
        ShadowTest st = new ShadowTest();
        ShadowTest.FirstLevel fl = st.new FirstLevel();
        fl.methodInFirstLevel(23);
    }
}

Output:

x = 23
this.x = 1
ShadowTest.this.x = 0
```

##### Serialization

Serialization of inner classes, including local and anonymous classes, is strongly discouraged. When the Java compiler compiles certain constructs, such as inner classes, it creates synthetic constructs; these are classes, methods, fields, and other constructs that do not have a corresponding construct in the source code. Synthetic constructs enable Java compilers to implement new Java language features without changes to the JVM. However, synthetic constructs can vary among different Java compiler implementations, which means that .class files can vary among different implementations as well. Consequently, you may have compatibility issues if you serialize an inner class and then deserialize it with a different JRE implementation. See the section Implicit and Synthetic Parameters in the section Obtaining Names of Method Parameters for more information about the synthetic constructs generated when an inner class is compiled.

### Local and Anonymous Classes

There are two additional types of inner classes. You can declare an inner class within the body of a method. These classes are known as local classes. You can also declare an inner class within the body of a method without naming the class. These classes are known as anonymous classes.

```
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
 
public class HelloWorld extends Application {
    public static void main(String[] args) {
        launch(args);
    }
    
    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Hello World!");
        Button btn = new Button();
        btn.setText("Say 'Hello World'");
        btn.setOnAction(new EventHandler<ActionEvent>() {
 
            @Override
            public void handle(ActionEvent event) {
                System.out.println("Hello World!");
            }
        });
        
        StackPane root = new StackPane();
        root.getChildren().add(btn);
        primaryStage.setScene(new Scene(root, 300, 250));
        primaryStage.show();
    }
}
```

### Lambda Expressions

```
p -> p.getGender() == Person.Sex.MALE 
    && p.getAge() >= 18
    && p.getAge() <= 25
```

Ideall use cases:

| Field | Description |
|---|---|
| Name | Perform action on selected members |
| Primary Actor | Administrator |
| Preconditions | Administrator is logged in to the system. |
| Postconditions | Action is performed only on members that fit the specified criteria. |
| Frequency of Occurrence | Many times during the day. |
| Extensions | Administrator has an option to preview those members who match the specified criteria before he or she specifies the action to be performed or before selecting the **Submit** button.|
| Main Success Scenario | <ol><li>Administrator specifies criteria of members on which to perform a certain action.</li><li>Administrator specifies an action to perform on those selected members.</li><li>Administrator selects the **Submit** button.</li><li>The system finds all members that match the specified criteria.</li><li>The system performs the specified action on all matching members. </ol>|

###### Serialization

### When to Use which

As mentioned in the section Nested Classes, nested classes enable you to logically group classes that are only used in one place, increase the use of encapsulation, and create more readable and maintainable code. Local classes, anonymous classes, and lambda expressions also impart these advantages; however, they are intended to be used for more specific situations:

Local class: Use it if you need to create more than one instance of a class, access its constructor, or introduce a new, named type (because, for example, you need to invoke additional methods later).

Anonymous class: Use it if you need to declare fields or additional methods.

Lambda expression:

Use it if you are encapsulating a single unit of behavior that you want to pass to other code. For example, you would use a lambda expression if you want a certain action performed on each element of a collection, when a process is completed, or when a process encounters an error.

Use it if you need a simple instance of a functional interface and none of the preceding criteria apply (for example, you do not need a constructor, a named type, fields, or additional methods).

Nested class: Use it if your requirements are similar to those of a local class, you want to make the type more widely available, and you don't require access to local variables or method parameters.

Use a non-static nested class (or inner class) if you require access to an enclosing instance's non-public fields and methods. Use a static nested class if you don't require this access.

### Method 

| Kind | Syntax | Examples |
|---|---|---|
| Reference to a static method | ContainingClass::staticMethodName | Person::compareByAge MethodReferencesExamples::appendStrings |
| Reference to an instance method of a particular object | containingObject::instanceMethodName | myComparisonProvider::compareByName myApp::appendStrings2 |
| Reference to an instance method of an arbitrary object of a particular type | ContainingType::methodName | String::compareToIgnoreCase String::concat |
| Reference to a constructor | ClassName::new | HashSet::new |

TODO

[Link](https://docs.oracle.com/javase/tutorial/java/javaOO/index.html)