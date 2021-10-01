# Collections

A collection — sometimes called a container — is simply an object that groups multiple elements into a single unit. Collections are used to store, retrieve, manipulate, and communicate aggregate data.

collections framework is a unified architecture for representing and manipulating collections. eg c++ STL

Interfaces: These are abstract data types that represent collections. form a hierarchy.

Implementations: These are the concrete implementations of the collection interfaces. reusable DS.

Algorithms: These are the methods that perform useful computations, polymorphic, reusable functionality.

### Why?

* Reduces programming effort
* Increases program speed and quality
* Allows interoperability among unrelated APIs
* Reduces effort to learn and to use new APIs
* Reduces effort to design new APIs
* Fosters software reuse
* interoperability among unrelated APIs

Collections:
* Set
  * SortedSet
* List
* Queue
* Dequeue

Map
* SortedMap

### Interfaces

These interfaces allow collections to be manipulated independently of the details of their representation.

```
public interface Collection<E>
```

Collection — the root of the collection hierarchy. A collection represents a group of objects known as its elements. 

Set — a collection that cannot contain duplicate elements.

List — an ordered collection (sometimes called a sequence). Lists can contain duplicate elements. eg Vector

Queue — a collection used to hold multiple elements prior to processing. 
Queues typically, but do not necessarily, order elements in a FIFO (first-in, first-out) manner. priority queues.  ordering properties.

Deque — a collection used to hold multiple elements prior to processing. both ends-> insertion, deletion, removed.

Map — an object that maps keys to values.

SortedSet — a Set that maintains its elements in ascending order. 

SortedMap — a Map that maintains its mappings in ascending key order. 

### Traversing Collections

1. using aggregate operations 
2. with the for-each construct
3. by using Iterators.

```
myShapesCollection.stream()
.filter(e -> e.getColor() == Color.RED)
.forEach(e -> System.out.println(e.getName()));

String joined = elements.stream()
    .map(Object::toString)
    .collect(Collectors.joining(", "));

int total = employees.stream()
.collect(Collectors.summingInt(Employee::getSalary)));
```

The key difference between the new aggregate operations and the existing bulk operations (containsAll, addAll, etc.) is that the old versions are all mutative, meaning that they all modify the underlying collection.


```
for (Object o : collection)
    System.out.println(o);

public interface Iterator<E> {
    boolean hasNext();
    E next();
    void remove(); //optional
}
```

```
polymorphic:

static void filter(Collection<?> c) {
    for (Iterator<?> it = c.iterator(); it.hasNext(); )
        if (!cond(it.next()))
            it.remove();
}
```

```
c.removeAll(Collections.singleton(e));
```

```
import java.util.*;
import java.io.*;

public class Anagrams {
    public static void main(String[] args) {
        int minGroupSize = Integer.parseInt(args[1]);

        // Read words from file and put into a simulated multimap
        Map<String, List<String>> m = new HashMap<String, List<String>>();

        try {
            Scanner s = new Scanner(new File(args[0]));
            while (s.hasNext()) {
                String word = s.next();
                String alpha = alphabetize(word);
                List<String> l = m.get(alpha);
                if (l == null)
                    m.put(alpha, l=new ArrayList<String>());
                l.add(word);
            }
        } catch (IOException e) {
            System.err.println(e);
            System.exit(1);
        }

        // Print all permutation groups above size threshold
        for (List<String> l : m.values())
            if (l.size() >= minGroupSize)
                System.out.println(l.size() + ": " + l);
    }

    private static String alphabetize(String s) {
        char[] a = s.toCharArray();
        Arrays.sort(a);
        return new String(a);
    }
}
```

### Aggregate Operations

```
double average = roster
    .stream()
    .filter(p -> p.getGender() == Person.Sex.MALE)
    .mapToInt(Person::getAge)
    .average()
    .getAsDouble();
```

##### Aggregate Operations vs Iterators

They use internal iteration: It can more easily take advantage of parallel computing, which involves dividing a problem into subproblems, solving those problems simultaneously, and then combining the results of the solutions to the subproblems. Parallelism

They process elements from a stream.

They support behavior as parameters: lambda expressions

### Reduction

```
Integer totalAgeReduce = roster
   .stream()
   .map(Person::getAge)
   .reduce(
       0, // identity
       (a, b) -> a + b // accumulator
       );
```

### Stream.collect Method

Unlike the reduce method, which always creates a new value when it processes an element, the collect method modifies, or mutates, an existing value.

```
Averager averageCollect = roster.stream()
    .filter(p -> p.getGender() == Person.Sex.MALE)
    .map(Person::getAge)
    .collect(Averager::new, // supplier
    Averager::accept, // accumulator 
    Averager::combine // combiner
    );
                   
System.out.println("Average age of male members: " +
    averageCollect.average());
```

```
Map<Person.Sex, Integer> totalAgeByGender =
    roster
        .stream()
        .collect(
            Collectors.groupingBy(
                Person::getGender,                      
                Collectors.reducing(
                    0, // identity
                    Person::getAge, // mapper
                    Integer::sum))); // operation
```

### Algorithms

### Custom implementation

### Interoperability

TODO

[Link](https://docs.oracle.com/javase/tutorial/collections/index.html)