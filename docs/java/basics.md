# Basics

### Variables

* Instance Variables (Non-Static Fields)
* Class Variables (Static Fields) 
* Local Variables: bw {}.
* Parameters: always classified as "variables" not "fields"

long creditCardNumber = 1234_5678_9012_3456L;

primitive data types are: byte, short, int, long, float, double, boolean, and char. java.lang.String class

##### Naming

* case sensitive
* unlimited-length sequence of Unicode letters and digits (avoid _ and $ in start)
* not keyword or reserved word
* gearRatio 
* NUM_GEARS = 6

### Arrays

its length is fixed.

```
int[] anArray = new int[10];
String[][] names = {
            {"Mr. ", "Mrs. ", "Ms. "},
            {"Smith", "Jones"}
        };
```

```
System.arraycopy(copyFrom, 2, copyTo, 0, 7);
java.util.Arrays.copyOfRange(copyFrom, 2, 9);
```

##### java.util.Arrays

* binarySearch 
* equals 
* fill 
* parallelSort 
* java.util.Arrays.stream(copyTo).map(coffee -> coffee + " ").forEach(System.out::print)
* System.out.println(java.util.Arrays.toString(copyTo))

### Operators

specific operations on one, two, or three operands, and then return a result.

Simple Assignment Operator

```
=
```

Arithmetic Operators

```
+       Additive operator (also used
        for String concatenation)
-       Subtraction operator
*       Multiplication operator
/       Division operator
%       Remainder operator
```

Unary Operators

```
+       Unary plus operator; indicates
        positive value (numbers are 
        positive without this, however)
-       Unary minus operator; negates
        an expression
++      Increment operator; increments
        a value by 1
--      Decrement operator; decrements
        a value by 1
!       Logical complement operator;
        inverts the value of a boolean
```

Equality and Relational Operators

```
==      Equal to
!=      Not equal to
>       Greater than
>=      Greater than or equal to
<       Less than
<=      Less than or equal to
Conditional Operators
&&      Conditional-AND
||      Conditional-OR
?:      Ternary (shorthand for 
        if-then-else statement)
```

Type Comparison Operator

```
instanceof      Compares an object to 
                a specified type 
```

Bitwise and Bit Shift Operators

```
~       Unary bitwise complement
<<      Signed left shift
>>      Signed right shift
>>>     Unsigned right shift
&       Bitwise AND
^       Bitwise exclusive OR
|       Bitwise inclusive OR
```

* Expressions -> result=9
* blocks -> {}
* statements ;->;

### Control flow

_program runs in top-down_

decision-making statements

if-then-else

```
if (testscore >= 90) {
    grade = 'A';
} else if (testscore >= 60) {
    grade = 'D';
} else {
    grade = 'F';
}
```

switch

```
switch (month) {
    case 1:  monthString = "January";
             break;
    default: monthString = "Invalid month";
             break;
}
```

the looping statements (for, while, do-while)

```
while (expression) {
     statement(s)
}

do {
     statement(s)
} while (expression);

for (initialization; termination;
     increment) {
    statement(s)
}
```

branching statements (break, continue, return) 

```
search:
for (i = 0; i < arrayOfInts.length; i++) {
    for (j = 0; j < arrayOfInts[i].length;
         j++) {
        if (arrayOfInts[i][j] == searchfor) {
            foundIt = true;
            break search;
        }
    }
}

if (foundIt) {
    System.out.println("Found " + searchfor + " at " + i + ", " + j);
} else {
    System.out.println(searchfor + " not in the array");
} 
```

### access modifiers

* public field is accessible from all classes.
* private field is accessible only within its own class.
* protected - same class and derived classes