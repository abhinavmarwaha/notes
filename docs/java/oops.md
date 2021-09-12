# Objects
_real world mapping of obbjects_

* state / fields / variables
* behaviour / methods / functions - primary mechanism for object-to-object communication

## Why?

* *Modularity*: an object can be easily passed around inside the system.
* Information-*hiding*
* Code *re-use*
* *Pluggability and debugging ease*: If a bolt breaks, you replace it, not the entire machine.

## data encapsulation

Hiding internal state and requiring all interaction to be performed through an object's methods.

# Class
_bicycle is an instance of the class of objects known as bicycles_

A class is the blueprint from which individual objects are created. (instances)

# Inheritance
_organizing and structuring your software_

subclass has superclass's fields and methods.

```
class MountainBike extends Bicycle {

    // new fields and methods defining 
    // a mountain bike would go here

}
```

# Interface

_form a contract between the class and the outside world._

```
interface Bicycle {

    //  wheel revolutions per minute
    void changeCadence(int newValue);

    void changeGear(int newValue);

    void speedUp(int increment);

    void applyBrakes(int decrement);
}

class ACMEBicycle implements Bicycle {

    int cadence = 0;
    int speed = 0;
    int gear = 1;

    void changeCadence(int newValue) {
         cadence = newValue;
    }

    void changeGear(int newValue) {
         gear = newValue;
    }

    void speedUp(int increment) {
         speed = speed + increment;   
    }

    void applyBrakes(int decrement) {
         speed = speed - decrement;
    }

    void printStates() {
         System.out.println("cadence:" +
             cadence + " speed:" + 
             speed + " gear:" + gear);
    }
}
```

# Package

namespace that organizes a set of related classes and interfaces.

# Library

a set of packages
