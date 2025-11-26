# Java Multithreaded Data Processing System

## Overview

This is a simple Java application that demonstrates multithreaded data processing using worker threads. The system simulates a greeting scenario where multiple worker threads retrieve people from a shared queue and greet them. The implementation includes proper concurrency management, exception handling, and logging.

## System Components

### 1. Person.java

A simple data class representing a person with a name. This is the basic unit of work processed by the system.

### 2. SharedQueue.java

A thread-safe queue implementation that manages the shared resource (people) that worker threads process. It uses synchronized methods to ensure thread-safe access:

- `addTask(Person person)` - Adds a person to the queue
- `getTask()` - Retrieves and removes a person from the queue (returns null if empty)
- `isEmpty()` - Checks if the queue is empty
- `size()` - Gets the current queue size

### 3. WorkerThread.java

A worker thread that extends `Thread` and processes people from the shared queue. Each worker:

- Retrieves people from the queue
- Simulates processing with a delay (200ms)
- Greets each person and logs the action
- Handles exceptions gracefully
- Exits when the queue is empty

### 4. DataProcessingSystem.java

The main class that orchestrates the entire system:

- Creates a shared queue
- Adds 10 people to the queue
- Creates 3 worker threads
- Starts all threads and waits for completion
- Handles exceptions at the system level

## Concurrency Model

The system uses Java's `synchronized` keyword to ensure thread-safe access to the shared queue. All methods in `SharedQueue` are synchronized, preventing race conditions when multiple threads access the queue simultaneously.

### Key Concurrency Features:

- **Synchronized Methods**: All queue operations are synchronized to prevent race conditions
- **Thread Termination**: Workers check for empty queue and exit gracefully
- **Thread Joining**: Main thread waits for all workers to complete using `join()`
- **No Deadlocks**: Minimal synchronized blocks prevent deadlock scenarios

## Exception Handling

The system implements comprehensive exception handling:

1. **InterruptedException**: Handled in worker threads when `Thread.sleep()` is interrupted
2. **NullPointerException**: Prevented by null checks before processing
3. **General Exceptions**: Caught and logged at appropriate levels
4. **Resource Cleanup**: Proper thread interruption status restoration

## Logging

The system logs important events:

- Queue operations (adding people)
- Worker thread lifecycle (start, completion)
- Greeting actions (which worker greets which person)
- Error messages and exceptions

## Compilation and Execution

### Prerequisites

- Java Development Kit (JDK) 8 or higher

### Compilation

Navigate to the `Java_Multithreaded_Processing` directory and compile all Java files:

```bash
javac *.java
```

### Execution

Run the main class:

```bash
java DataProcessingSystem
```

### Expected Output

The program will output messages showing:

1. System initialization
2. People being added to the queue
3. Worker threads starting
4. Workers greeting people
5. Workers completing their tasks
6. System completion message

## Example Output

```
=== Data Processing System Starting ===
Initializing queue with 10 people
Creating 3 worker threads

Added Person 1 to the queue
Added Person 2 to the queue
...
Queue initialized with 10 people

Starting all worker threads...

Worker 1 started
Worker 2 started
Worker 3 started
Waiting for all workers to complete...

Worker 1 greets Person 1
Worker 2 greets Person 2
Worker 3 greets Person 3
...

=== All workers completed ===
Data Processing System finished successfully

System shutdown complete
```

## Design Decisions

1. **Synchronized Methods**: Used `synchronized` keyword for simplicity and readability
2. **Null Return Pattern**: `getTask()` returns null when queue is empty to signal completion
3. **Processing Delay**: 200ms delay simulates real-world processing time
4. **Console Logging**: Simple `System.out.println()` for logging (can be replaced with proper logging framework)
5. **Fixed Configuration**: 3 workers and 10 people as constants (can be made configurable)

## Testing Considerations

When testing the system, verify:

- All 10 people are greeted exactly once
- No race conditions occur (no duplicate greetings or missed people)
- Proper thread termination (all workers complete)
- Exception handling works correctly
- No deadlocks occur

## Future Enhancements

Potential improvements:

- Make number of workers and people configurable via command-line arguments
- Add file-based logging instead of console output
- Implement a proper logging framework (e.g., Log4j, SLF4J)
- Add metrics collection (processing time, throughput)
- Support for dynamic task addition during execution
- Use thread pools (ExecutorService) for better resource management
