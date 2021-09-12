A package is a grouping of related types (classes, interfaces, enumerations (classes), and annotation types (interfaces)) providing access protection and name space management.

# Why?

* types are related.
* easy to find types that can provide particular functions.
* The names won't conflict with the type names in other packages because the package creates a new namespace.
* unrestricted access to one another yet still restrict access for types outside the package.

At top:

```
package <name>;
```

only one public type in one source file.
You can include non-public types in the same file as a public type (this is strongly discouraged, unless the non-public types are small and closely related to the public type).
All the top-level, non-public types will be package private.

# Naming

The fully qualified name -> library.package.class

* lower case
* reversed Internet domain name
* region specific -> com.example.region.mypackage
* Packages in the Java language itself begin with java. or javax.
* add an underscore for reserved keywords and hyphens adn starting with numbers

# Usage

## by Its Qualified Name
_all right for infrequent use_

You can use a package member's simple name if the code you are writing is in the same package as that member or if that member has been imported.

## Importing a Package Member

```
import graphics.Rectangle;
```
## Importing an Entire Package

if you use many types from a package, you should import the entire package.
It cannot be used to match a subset of the classes in a package.

```
import graphics.*;
```

## import the public nested classes of an enclosing class. 

```
import graphics.Rectangle;
import graphics.Rectangle.*;
```

Be aware that the second import statement will not import Rectangle.

## static import

when you need frequent access to static final fields (constants) and static methods from one or two classes. 

```
import static java.lang.Math.*;
```

Java compiler automatically imports:

1) the java.lang package
2) the package for the current file

# Apparent Hierarchies of Packages

java.awt.xxxx packages are not included in the java.awt package.
java.awt is used for a number of related packages to make the relationship evident, but not to show inclusion.

# Name Ambiguities

if a type in 2 packages have same name and both packagesare included -> use member's fully qualified name.

# Managing Source and Class Files

hierarchical file systems to manage source and class files, although The Java Language Specification does not require this. 

```
<path_one>\sources\com\example\graphics\Rectangle.java

<path_two>\classes\com\example\graphics\Rectangle.class
```

The full path to the classes directory, <path_two>\classes, is called the class path, and is set with the *CLASSPATH* system variable. Both the compiler and the JVM construct the path to your .class files by adding the package name to the class path. For example, if

```
<path_two>\classes
```
is your class path, and the package name is

```
com.example.graphics,
```

then the compiler and JVM look for .class files in

```
<path_two>\classes\com\example\graphics.
```

By default, the compiler and the JVM search the current directory and the JAR file containing the Java platform classes so that these directories are automatically in your class path.

