# Interfaces

A contract that other people adhere to and people know the API but not the implementation

```
public interface OperateCar {

   // constant declarations, if any

   // method signatures
   
   // An enum with values RIGHT, LEFT
   int turn(Direction direction,
            double radius,
            double startSpeed,
            double endSpeed);
   int changeLanes(Direction direction,
                   double startSpeed,
                   double endSpeed);
   int signalTurn(Direction direction,
                  boolean signalOn);
   int getRadarFront(double distanceToCar,
                     double speedOfCar);
   int getRadarRear(double distanceToCar,
                    double speedOfCar);
         ......
   // more method signatures
}
```

```
public interface GroupedInterface extends Interface1, Interface2, Interface3 {

    // constant declarations
    
    // base of natural logarithms
    double E = 2.718282;
 
    // method signatures
    void doSomething (int i, double x);
    int doSomethingElse(String s);
}
```

abstract methods, default methods, and static methods -> default public , can omit.
All constant values defined in an interface are implicitly public, static, and final.

```
public interface Relatable {
        
    // this (object calling isLargerThan)
    // and other must be instances of 
    // the same class returns 1, 0, -1 
    // if this is greater than, 
    // equal to, or less than other
    public int isLargerThan(Relatable other);
}


public class RectanglePlus 
    implements Relatable {
public int isLargerThan(Relatable other) {
        RectanglePlus otherRect 
            = (RectanglePlus)other;
        if (this.getArea() < otherRect.getArea())
            return -1;
        else if (this.getArea() > otherRect.getArea())
            return 1;
        else
            return 0;               
    }
    }
```

### Evolving Interfaces

making changes in historic interfaces make devs angry. either extend it, or define static and default methods.

```
default boolean didItWork(int i, double x, String s) {
       // Method body 
   }
```

### Extending Interfaces That Contain Default Methods

Not mention the default method at all, which lets your extended interface inherit the default method.
Redeclare the default method, which makes it abstract.
Redefine the default method, which overrides it.

### Static Methods

A static method is a method that is associated with the class in which it is defined rather than with any object. Every instance of the class shares its static methods

```
myDeck.sort(
    Comparator.comparing(Card::getRank)
        .reversed()
        .thenComparing(Comparator.comparing(Card::getSuit)));
```