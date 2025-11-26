# Multi-threaded Data Processing System

This repository contains two implementations—a Go and a Java version—of a multithreaded data processing system that greets a list of people using worker threads (or goroutines). Both approaches aim to achieve safe and efficient concurrency, but leverage distinct language-specific mechanisms for exception handling, synchronization, and managing worker execution.

**Concurrency and Synchronization**

- **Java:**  
  The Java implementation uses explicit worker threads (extending `Thread`) and a shared queue (`SharedQueue`) for task distribution. Synchronization is handled with the `synchronized` keyword on queue methods, ensuring thread-safe operations and preventing race conditions or deadlocks. Java’s concurrency primitives (e.g., `join()` for thread coordination) require careful management of thread lifecycles and mutual exclusion for shared state.

- **Go:**  
  Go leverages lightweight goroutines and buffered channels. The channel serves as a thread-safe method for passing tasks (people) to workers. The Go approach avoids explicit locks by using channels for synchronization, eliminating many traditional deadlock risks. The `sync.WaitGroup` synchronizes goroutine completion. Go’s concurrency model is built around communicating sequential processes (CSP), promoting simplicity and safety.

**Exception Handling**

- **Java:**  
  Java uses structured exception handling with `try-catch` blocks to guard against runtime errors. Errors within worker threads are caught and handled gracefully to ensure stability and proper logging, and checked/unchecked exceptions are part of the thread execution flow.

- **Go:**  
  Go uses an explicit, error-return idiom for function calls. Within goroutines, panics are captured using `defer` and `recover`, enabling graceful error handling without stopping the whole program. Errors can be communicated between goroutines using separate error channels.

**Worker Threads**

- **Java:**  
  Workers are heavy-weight threads managed by the JVM. Developers must manage starting, stopping, and joining these threads explicitly.

- **Go:**  
  Workers are lightweight goroutines managed by Go’s runtime scheduler. Launching workers is as simple as invoking `go worker()` and WaitGroups help track their completion.

**Summary**

| Feature            | Java                             | Go                                 |
| ------------------ | -------------------------------- | ---------------------------------- |
| Worker Unit        | Thread class                     | Goroutine function                 |
| Task Distribution  | Synchronized shared queue        | Buffered/unbuffered channel        |
| Synchronization    | `synchronized`, explicit locking | Channels, implicit synchronization |
| Exception Handling | `try-catch` blocks               | `error` values, `defer/recover`    |
| Coordination       | `join()` on threads              | `sync.WaitGroup`                   |
| Deadlock Avoidance | Manual (locks, careful coding)   | Channels reduce explicit locking   |

Both implementations provide practical examples of multithreaded data processing, reflecting best practices in concurrency management and exception handling for their respective languages.

**Example Java Output:**

```
keishamukasa@MacBookPro Java_Multithreaded_Processing % java DataProcessingSystem
=== Data Processing System Starting ===
Initializing queue with 10 people
Creating 3 worker threads

Added Person 1 to the queue
Added Person 2 to the queue
Added Person 3 to the queue
Added Person 4 to the queue
Added Person 5 to the queue
Added Person 6 to the queue
Added Person 7 to the queue
Added Person 8 to the queue
Added Person 9 to the queue
Added Person 10 to the queue

Queue initialized with 10 people

Starting all worker threads...

Waiting for all workers to complete...

Worker 1 started
Worker 3 started
Worker 2 started
Worker 1 greets Person 1
Worker 2 greets Person 3
Worker 3 greets Person 2
Worker 1 greets Person 4
Worker 2 greets Person 5
Worker 3 greets Person 6
Worker 3 greets Person 9
Worker 2 greets Person 8
Worker 1 greets Person 7
Worker 2 completed all tasks
Worker 1 completed all tasks
Worker 3 greets Person 10
Worker 3 completed all tasks

=== All workers completed ===
Data Processing System finished successful
```

**Example Go Output:**

```
keishamukasa@MacBookPro Go_Multithreaded_Processing % ./data_processing_system
=== Data Processing System Starting ===
Initializing queue with 10 people
Creating 3 worker goroutines

Adding people to the queue...
Added Person 1 to the queue
Added Person 2 to the queue
Added Person 3 to the queue
Added Person 4 to the queue
Added Person 5 to the queue
Added Person 6 to the queue
Added Person 7 to the queue
Added Person 8 to the queue
Added Person 9 to the queue
Added Person 10 to the queue

Queue initialized with 10 people

Starting all worker goroutines...

Waiting for all workers to complete...

Worker 3 started
Worker 1 started
Worker 2 started
Worker 1 greets Person 2
Worker 2 greets Person 3
Worker 3 greets Person 1
Worker 3 greets Person 6
Worker 2 greets Person 5
Worker 1 greets Person 4
Worker 1 greets Person 9
Worker 2 greets Person 8
Worker 2 completed all tasks
Worker 3 greets Person 7
Worker 3 completed all tasks
Worker 1 greets Person 10
Worker 1 completed all tasks

=== All workers completed ===
Data Processing System finished successfully

System shutdown complete
```
