reasons to use objects in place of primitives, and the Java platform provides wrapper classes for each of the primitive data types. These classes "wrap" the primitive in an object. Often, the wrapping is done by the compiler

* As an argument of a method that expects an object (often used when manipulating collections of numbers).
* To use constants defined by the class, such as MIN_VALUE and MAX_VALUE, that provide the upper and lower bounds of the data type.
* To use class methods for converting values to and from other primitive types, for converting to and from strings, and for converting between number systems (decimal, octal, hexadecimal, binary).

BigDecimal and BigInteger are used for high-precision calculations. 
AtomicInteger and AtomicLong are used for multi-threaded applications.

* Byte
* Short
* Integer
* Long 
* Float
* Double


```
System.out.printf(...)

System.out.format("The value of " + "the float variable is " +
     "%f%n, while the value of the " + "integer variable is %d, " +
     "and the string is %s", floatVar, intVar, stringVar); 

public PrintStream format(Locale l, String format, Object... args)
```

```
the java.text.DecimalFormat(...)
DecimalFormat myFormatter = new DecimalFormat(pattern);
String output = myFormatter.format(value);
System.out.println(value + "  " + pattern + "  " + output);
```

| number      | pattern     | output      |
| ----------- | ----------- | ----------- |
| 123456.789  | ###,###.### | 123,456.789 | 
| 123456.789  | ###.##      | 123456.79   |
| 123.78      | 000000.000  | 000123.780  | 
| 12345.67    | $###,###.###| $12,345.67  |

## Advanced math

```
import static java.lang.Math.*;
E
PI
abs
ceil
floor
rint
round
min
max
exp
log
pow
sqrt
sin
random()
java.util.Random
```