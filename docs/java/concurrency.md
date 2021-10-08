# Concurrency

__Computer users take it for granted that their systems can do more than one thing at a time.__

Two basic units of execution: 

* Processes
* Threads

In java, we mainly deal with threads.

Processing time for a single core is shared among processes and threads through an OS feature called **time slicing**.

### Process

A process has a self-contained execution environment. (A complete, private set of basic run-time resources: memory space atleast)

An application is a set of processes comunicating with each other. OS support Inter Process Communication (IPC) resources, such as pipes and sockets. 

Most programs in JVM run as a single process, if you want multiple processes extend **ProcessBuilder**.

### Threads

__lightweight processes__ (lower resource requirement)

Threads share the process's resources, including memory and open files. This makes for efficient, but potentially problematic, communication.

### Thread Objects

2 basic strategies for using Thread objects to create a concurrent application:

1. To directly control thread creation and management, simply **instantiate** Thread each time the application needs to initiate an asynchronous task.
2. To abstract thread management from the rest of your application, pass the application's tasks to an **executor**.

### Defination

Thread must provide the code that will run in that thread.

1. Provide a Runnable object.

This approach more flexible and it is applicable to the high-level thread management APIs.

```
public class HelloRunnable implements Runnable {

    public void run() {
        System.out.println("Hello from a thread!");
    }

    public static void main(String args[]) {
        (new Thread(new HelloRunnable())).start();
    }

}
```

2. Subclass Thread. The Thread class itself implements Runnable, though its run method does nothing

The Thread class defines a number of methods useful for thread management.

```
public class HelloThread extends Thread {

    public void run() {
        System.out.println("Hello from a thread!");
    }

    public static void main(String args[]) {
        (new HelloThread()).start();
    }

}
```

### Operations

##### Sleep

```
public class SleepMessages {
    public static void main(String args[])
        throws InterruptedException {
        String importantInfo[] = {
            "Mares eat oats",
            "Does eat oats",
            "Little lambs eat ivy",
            "A kid will eat ivy too"
        };

        for (int i = 0;
             i < importantInfo.length;
             i++) {
            Thread.sleep(4000);
            System.out.println(importantInfo[i]);
        }
    }
}
```

##### Interrupts

An interrupt is an indication to a thread that it should stop what it is doing and do something else.

```
for (int i = 0; i < importantInfo.length; i++) {
    // Pause for 4 seconds
    try {
        Thread.sleep(4000);
    } catch (InterruptedException e) {
        // We've been interrupted: no more messages.
        return;
    }
    // Print a message
    System.out.println(importantInfo[i]);
}

for (int i = 0; i < inputs.length; i++) {
    heavyCrunch(inputs[i]);
    if (Thread.interrupted()) {
        // We've been interrupted: no more crunching.
        return;
    }
}

if (Thread.interrupted()) {
    throw new InterruptedException();
}
```

**The Interrupt Status Flag**

Invoking Thread.interrupt sets this flag. When a thread checks for an interrupt by invoking the static method Thread.interrupted, interrupt status is cleared. The non-static isInterrupted method, which is used by one thread to query the interrupt status of another, does not change the interrupt status flag.

##### Joins

Join method allows one thread to wait for the completion of another

```
t.join();
```

Causes the current thread to pause execution until t's thread terminates

Overloads of join allow the programmer to specify a waiting period.__However, as with sleep, join is dependent on the OS for timing__

### The Simple Thread

```
public class SimpleThreads {

    static void threadMessage(String message) {
        String threadName =
            Thread.currentThread().getName();
        System.out.format("%s: %s%n",
                          threadName,
                          message);
    }

    private static class MessageLoop
        implements Runnable {
        public void run() {
            String importantInfo[] = {
                "Mares eat oats",
                "Does eat oats",
                "Little lambs eat ivy",
                "A kid will eat ivy too"
            };
            try {
                for (int i = 0;
                     i < importantInfo.length;
                     i++) {
                    Thread.sleep(4000);
                    threadMessage(importantInfo[i]);
                }
            } catch (InterruptedException e) {
                threadMessage("I wasn't done!");
            }
        }
    }

    public static void main(String args[])
        throws InterruptedException {
        long patience = 1000 * 60 * 60;

        if (args.length > 0) {
            try {
                patience = Long.parseLong(args[0]) * 1000;
            } catch (NumberFormatException e) {
                System.err.println("Argument must be an integer.");
                System.exit(1);
            }
        }

        threadMessage("Starting MessageLoop thread");
        long startTime = System.currentTimeMillis();
        Thread t = new Thread(new MessageLoop());
        t.start();

        threadMessage("Waiting for MessageLoop thread to finish");
        while (t.isAlive()) {
            threadMessage("Still waiting...");
            t.join(1000);
            if (((System.currentTimeMillis() - startTime) > patience)
                  && t.isAlive()) {
                threadMessage("Tired of waiting!");
                t.interrupt();
                t.join();
            }
        }
        threadMessage("Finally!");
    }
}
```

The main thread creates a new thread from the Runnable object, MessageLoop, and waits for it to finish. If the MessageLoop thread takes too long to finish, the main thread interrupts it.

### Synchronisation

Threads communicate primarily by sharing access to fields and the objects reference fields refer to. Problems:

1. Thread interference
2. Memory consistency errors

Synchronisation solves it but a problem of **thread contention** (Starvation, Livelock etc) arises, which occurs when two or more threads try to access the same resource simultaneously and cause the Java runtime to execute one or more threads more slowly, or even suspend their execution.

two basic synchronization idioms:

1. synchronized methods
2. synchronized statements. 

##### Thread Interference

Interference happens when two operations, running in different threads, but acting on the same data, interleave.

The single expression `c++` can be decomposed into:

* Retrieve the current value of c.
* Increment it by 1.
* Store the value back in c.

eg.

* Thread A: Retrieve c.
* Thread B: Retrieve c.
* Thread A: Increment retrieved value; result is 1.
* Thread B: Decrement retrieved value; result is -1.
* Thread A: Store result in c; c is now 1.
* Thread B: Store result in c; c is now -1.

##### Memory Consistency Errors

Memory consistency errors occur when different threads have inconsistent views of what should be the same data. Understanding the cause is difficult, just focus on avoiding them.

The key to avoiding memory consistency errors is understanding the **happens-before relationship**:

* When a statement invokes Thread.start, every statement that has a happens-before relationship with that statement also has a happens-before relationship with every statement executed by the new thread. The effects of the code that led up to the creation of the new thread are visible to the new thread.
* When a thread terminates and causes a Thread.join in another thread to return, then all the statements executed by the terminated thread have a happens-before relationship with all the statements following the successful join. The effects of the code in the thread are now visible to the thread that performed the join.

### Liveness

A concurrent application's ability to execute in a timely manner is known as its liveness.

##### Deadlock

Deadlock describes a situation where two or more threads are blocked forever, waiting for each other.

```
public class Deadlock {
    static class Friend {
        private final String name;
        public Friend(String name) {
            this.name = name;
        }
        public String getName() {
            return this.name;
        }
        public synchronized void bow(Friend bower) {
            System.out.format("%s: %s"
                + "  has bowed to me!%n", 
                this.name, bower.getName());
            bower.bowBack(this);
        }
        public synchronized void bowBack(Friend bower) {
            System.out.format("%s: %s"
                + " has bowed back to me!%n",
                this.name, bower.getName());
        }
    }

    public static void main(String[] args) {
        final Friend alphonse =
            new Friend("Alphonse");
        final Friend gaston =
            new Friend("Gaston");
        new Thread(new Runnable() {
            public void run() { alphonse.bow(gaston); }
        }).start();
        new Thread(new Runnable() {
            public void run() { gaston.bow(alphonse); }
        }).start();
    }
}
```

##### Starvation

Starvation describes a situation where a thread is unable to gain regular access to shared resources and is unable to make progress.

This happens when shared resources are made unavailable for long periods by "greedy" threads.

##### Livelock

A thread often acts in response to the action of another thread. If the other thread's action is also a response to the action of another thread, then livelock may result.

This is comparable to two people attempting to pass each other in a corridor: Alphonse moves to his left to let Gaston pass, while Gaston moves to his right to let Alphonse pass. Seeing that they are still blocking each other, Alphone moves to his right, while Gaston moves to his left. They're still blocking each other, so..

### Guarded Blocks

Threads often have to coordinate their actions. The most common coordination idiom is the guarded block. Such a block begins by polling a condition that must be true before the block can proceed.

```
public synchronized void guardedJoy() {
    while(!joy) {
        try {
            wait();
        } catch (InterruptedException e) {}
    }
    System.out.println("Joy and efficiency have been achieved!");
}
```

### Immutable objects

An object is considered immutable if its state cannot change after it is constructed. Great for concurrency!

The cost of creating a new object vs updating.

But this can be optimised by:

* Decreased overhead due to garbage collection
* the elimination of code needed to protect mutable objects from corruption.

```
public class SynchronizedRGB {

    // Values must be between 0 and 255.
    private int red;
    private int green;
    private int blue;
    private String name;

    private void check(int red,
                       int green,
                       int blue) {
        if (red < 0 || red > 255
            || green < 0 || green > 255
            || blue < 0 || blue > 255) {
            throw new IllegalArgumentException();
        }
    }

    public SynchronizedRGB(int red,
                           int green,
                           int blue,
                           String name) {
        check(red, green, blue);
        this.red = red;
        this.green = green;
        this.blue = blue;
        this.name = name;
    }

    public void set(int red,
                    int green,
                    int blue,
                    String name) {
        check(red, green, blue);
        synchronized (this) {
            this.red = red;
            this.green = green;
            this.blue = blue;
            this.name = name;
        }
    }

    public synchronized int getRGB() {
        return ((red << 16) | (green << 8) | blue);
    }

    public synchronized String getName() {
        return name;
    }

    public synchronized void invert() {
        red = 255 - red;
        green = 255 - green;
        blue = 255 - blue;
        name = "Inverse of " + name;
    }
}
```

```
SynchronizedRGB color =
    new SynchronizedRGB(0, 0, 0, "Pitch Black");
...
int myColorInt = color.getRGB();      //Statement 1
String myColorName = color.getName(); //Statement 2
If another thread invokes color.set after Statement 1 but before Statement 2, the value of myColorInt won't match the value of myColorName. To avoid this outcome, the two statements must be bound together:

synchronized (color) {
    int myColorInt = color.getRGB();
    String myColorName = color.getName();
} 
This kind of inconsistency is only possible for mutable objects — it will not be an issue for the immutable version of SynchronizedRGB.
```

##### Strategy

Don't provide "setter" methods — methods that modify fields or objects referred to by fields.
Make all fields final and private.
Don't allow subclasses to override methods. The simplest way to do this is to declare the class as final. A more sophisticated approach is to make the constructor private and construct instances in factory methods.
If the instance fields include references to mutable objects, don't allow those objects to be changed:
Don't provide methods that modify the mutable objects.
Don't share references to the mutable objects. Never store references to external, mutable objects passed to the constructor; if necessary, create copies, and store references to the copies. Similarly, create copies of your internal mutable objects when necessary to avoid returning the originals in your methods.

TODO

[LINK](https://docs.oracle.com/javase/tutorial/essential/concurrency/index.html)