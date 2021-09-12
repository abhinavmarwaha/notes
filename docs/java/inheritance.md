* subclass (also a derived class, extended class, or child class). 
* superclass (also a base class or a parent class).
* the topmost class, Object. Such a class is said to be descended from all the classes in the inheritance chain stretching back to Object.
* Constructors are not members, so they are not inherited by subclasses

A subclass inherits all of the public and protected members of its parent, no matter what package the subclass is in. If the subclass is in the same package as its parent, it also inherits the package-private members of the parent. You can use the inherited members as is, replace them, hide them, or supplement them with new members:

* You can declare a field in the subclass with the same name as the one in the superclass, thus hiding it (not recommended).
* You can write a new instance method in the subclass that has the same signature as the one in the superclass, thus overriding it.
* You can write a new static method in the subclass that has the same signature as the one in the superclass, thus hiding it.
* You can write a subclass constructor that invokes the constructor of the superclass, either implicitly or by using the keyword super.

A nested class has access to all the private members of its enclosing class—both fields and methods. Therefore, a public or protected nested class inherited by a subclass has indirect access to all of the private members of the superclass.

## Casting Objects

```
// implicit casting
Object obj = new MountainBike();

// explicit casting
MountainBike myBike = (MountainBike)obj;
```

instanceof

## Multiple Inheritance of State, Implementation, and Type

multiple inheritance of state problem:

* name conflicts and ambiguity.
* Because interfaces do not contain fields, you do not have to worry about problems that result from multiple inheritance of state.
* As with multiple inheritance of implementation, a class can inherit different implementations of a method defined (as default or static) in the interfaces that it extends. In this case, the compiler or the user must decide which one to use.

## Polymorphism

principle in biology in which an organism or species can have many different forms or stages.
Subclasses of a class can define their own unique behaviors and yet share some of the same functionality of the parent class.

### virtual method invocation

It does not call the method that is defined by the variable's type

## super keyword

Note: If a constructor does not explicitly invoke a superclass constructor, the Java compiler automatically inserts a call to the no-argument constructor of the superclass. If the super class does not have a no-argument constructor, you will get a compile-time error. Object does have such a constructor, so if Object is the only superclass, there is no problem.

```
super(parameter list) -> constructor of super class.
```

### constructor chaining

a whole chain of constructors called, all the way back to the constructor of Object.


## Object as superclass

protected Object clone() throws CloneNotSupportedException
      Creates and returns a copy of this object.
public boolean equals(Object obj)
      Indicates whether some other object is "equal to" this one. check only refernece / symbol not values
protected void finalize() throws Throwable
      Called by the garbage collector on an object when garbage
      collection determines that there are no more references to the object
public final Class getClass()
      Returns the runtime class of an object.
public int hashCode()
      Returns a hash code value for the object.
public String toString()
      Returns a string representation of the object.

public final void notify()
public final void notifyAll()
public final void wait()
public final void wait(long timeout)
public final void wait(long timeout, int nanos)

If you override equals(), you must override hashCode() as well.

The Class class, in the java.lang package, has a large number of methods (more than 50). For example, you can test to see if the class is an annotation (isAnnotation()), an interface (isInterface()), or an enumeration (isEnum()). You can see what the object's fields are (getFields()) or what its methods are (getMethods()), and so on.

You can declare some or all of a class's methods final
Methods called from constructors should generally be declared finaal. 
A class that is declared final cannot be subclassed.

## Abstract Methods and Classes

Abstract classes cannot be instantiated, but they can be subclassed.

## Abstract classes vs interface

Abstract classes are similar to interfaces. You cannot instantiate them, and they may contain a mix of methods declared with or without an implementation. However, with abstract classes, you can declare fields that are not static and final, and define public, protected, and private concrete methods. With interfaces, all fields are automatically public, static, and final, and all methods that you declare or define (as default methods) are public. In addition, you can extend only one class, whether or not it is abstract, whereas you can implement any number of interfaces.

Which should you use, abstract classes or interfaces?

Consider using abstract classes if any of these statements apply to your situation:
You want to share code among several closely related classes.
You expect that classes that extend your abstract class have many common methods or fields, or require access modifiers other than public (such as protected and private).
You want to declare non-static or non-final fields. This enables you to define methods that can access and modify the state of the object to which they belong.
Consider using interfaces if any of these statements apply to your situation:
You expect that unrelated classes would implement your interface. For example, the interfaces Comparable and Cloneable are implemented by many unrelated classes.
You want to specify the behavior of a particular data type, but not concerned about who implements its behavior.
You want to take advantage of multiple inheritance of type.

## overriding and hiding methods

same signature (name, plus the number and the type of its parameters) and return type 

```
@Override
```

If a subclass defines a static method with the same signature as a static method in the superclass, then the method in the subclass hides the one in the superclass.

The version of the overridden instance method that gets invoked is the one in the subclass.
The version of the hidden static method that gets invoked depends on whether it is invoked from the superclass or the subclass.

```
public class Animal {
    public static void testClassMethod() {
        System.out.println("The static method in Animal");
    }
    public void testInstanceMethod() {
        System.out.println("The instance method in Animal");
    }
}

public class Cat extends Animal {
    public static void testClassMethod() {
        System.out.println("The static method in Cat");
    }
    public void testInstanceMethod() {
        System.out.println("The instance method in Cat");
    }

    public static void main(String[] args) {
        Cat myCat = new Cat();
        Animal myAnimal = myCat;
        Animal.testClassMethod();
        myAnimal.testInstanceMethod();
    }
}

The static method in Animal
The instance method in Cat
```


