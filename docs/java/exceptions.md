# Exceptions

_exceptional event_

disrupts the normal flow of the program's instructions.

* exception object
* throwing an exception
* call stack
* exception handler
* catch the exception

### Catch or Specify Requirement

* A try statement that catches the exception. 
* A method that specifies that it can throw the exception. 

* **Checked Exception**
  * These are exceptional conditions that a well-written application should anticipate and recover from.
  * eg. java.io.FileNotFoundException. 
* **Error**
  * These are exceptional conditions that are external to the application.
  * the application usually cannot anticipate or recover.from.
  * Errors are not subject to the Catch or Specify Requirement.
  * eg. java.io.IOError
* **Runtime Exception**
  * These are exceptional conditions that are internal to the application, and that the application usually cannot anticipate or recover from.
  * programming bugs, such as logic errors or improper use of an API.
  * are not subject to the Catch or Specify Requirement.
  * those indicated by RuntimeException and its subclasses.
  * eg. NullPointerException

__Errors and runtime exceptions are collectively known as unchecked exceptions.__

### Bypassing Catch or Specify

using unchecked exceptions in place of checked exceptions.

### Syntax

```
// Note: This class will not compile yet.
import java.io.*;
import java.util.List;
import java.util.ArrayList;

public class ListOfNumbers {

    private List<Integer> list;
    private static final int SIZE = 10;

    public ListOfNumbers () {
        list = new ArrayList<Integer>(SIZE);
        for (int i = 0; i < SIZE; i++) {
            list.add(new Integer(i));
        }
    }

    public void writeList() {
	// The FileWriter constructor throws IOException, which must be caught.
        PrintWriter out = new PrintWriter(new FileWriter("OutFile.txt"));

        for (int i = 0; i < SIZE; i++) {
            // The get(int) method throws IndexOutOfBoundsException, which must be caught.
            out.println("Value at: " + i + " = " + list.get(i));
        }
        out.close();
    }
}
```

with exception handling

```
public void writeList() {
    PrintWriter out = null;

    try {
        System.out.println("Entering" + " try statement");

        out = new PrintWriter(new FileWriter("OutFile.txt"));
        for (int i = 0; i < SIZE; i++) {
            out.println("Value at: " + i + " = " + list.get(i));
        }
    } catch (IndexOutOfBoundsException e) {
        System.err.println("Caught IndexOutOfBoundsException: "
                           +  e.getMessage());
                                 
    } catch (IOException e) {
        System.err.println("Caught IOException: " +  e.getMessage());
                                 
    } finally {
        if (out != null) {
            System.out.println("Closing PrintWriter");
            out.close();
        } 
        else {
            System.out.println("PrintWriter not open");
        }
    }
}
```

### Suppressed Exceptions

### Classes That Implement the AutoCloseable or Closeable Interface

### Try with Resources

```
public static void viewTable(Connection con) throws SQLException {

    String query = "select COF_NAME, SUP_ID, PRICE, SALES, TOTAL from COFFEES";

    try (Statement stmt = con.createStatement()) {
        ResultSet rs = stmt.executeQuery(query);

        while (rs.next()) {
            String coffeeName = rs.getString("COF_NAME");
            int supplierID = rs.getInt("SUP_ID");
            float price = rs.getFloat("PRICE");
            int sales = rs.getInt("SALES");
            int total = rs.getInt("TOTAL");

            System.out.println(coffeeName + ", " + supplierID + ", " + 
                               price + ", " + sales + ", " + total);
        }
    } catch (SQLException e) {
        JDBCTutorialUtilities.printSQLException(e);
    }
}
```

### Specification

```
public void writeList() throws IOException, IndexOutOfBoundsException {}
```

### Classes

* Throwable 
* Error 
* Exception

### Chained Exceptions

```
Throwable getCause()
Throwable initCause(Throwable)
Throwable(String, Throwable)
Throwable(Throwable)
```

### Stack Trace Information

```
catch (Exception cause) {
    StackTraceElement elements[] = cause.getStackTrace();
    for (int i = 0, n = elements.length; i < n; i++) {       
        System.err.println(elements[i].getFileName()
            + ":" + elements[i].getLineNumber() 
            + ">> "
            + elements[i].getMethodName() + "()");
    }
}
```

### Logging

```
try {
    Handler handler = new FileHandler("OutFile.log");
    Logger.getLogger("").addHandler(handler);
    
} catch (IOException e) {
    Logger logger = Logger.getLogger("package.name"); 
    StackTraceElement elements[] = e.getStackTrace();
    for (int i = 0, n = elements.length; i < n; i++) {
        logger.log(Level.WARNING, elements[i].getMethodName());
    }
}
```

### Unchecked Exceptions — The Controversy

* Why did the designers decide to force a method to specify all uncaught checked exceptions that can be thrown within its scope?
* 

### Advantages of Exceptions

* Separating Error-Handling Code from "Regular" Code
* Propagating Errors Up the Call Stack
* Grouping and Differentiating Error Types
* 

TODO

[Link](https://docs.oracle.com/javase/tutorial/essential/exceptions/index.html)