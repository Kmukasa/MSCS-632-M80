import java.util.LinkedList;
import java.util.Queue;

/**
 * Thread-safe shared queue implementation for managing tasks (people).
 * Uses synchronized methods to ensure thread-safe access to the queue.
 */
public class SharedQueue {
    private Queue<Person> queue;
    
    /**
     * Constructor to create an empty shared queue.
     */
    public SharedQueue() {
        this.queue = new LinkedList<>();
    }
    
    /**
     * Adds a person to the queue in a thread-safe manner.
     * @param person The person to add to the queue
     */
    public synchronized void addTask(Person person) {
        try {
            if (person != null) {
                queue.offer(person);
                System.out.println("Added " + person.getName() + " to the queue");
            } else {
                System.out.println("Warning: Attempted to add null person to queue");
            }
        } catch (Exception e) {
            System.out.println("Error adding task to queue: " + e.getMessage());
        }
    }
    
    /**
     * Retrieves and removes a person from the queue in a thread-safe manner.
     * Returns null if the queue is empty to signal completion.
     * @return The next person in the queue, or null if queue is empty
     */
    public synchronized Person getTask() {
        try {
            if (queue.isEmpty()) {
                return null;
            }
            return queue.poll();
        } catch (Exception e) {
            System.out.println("Error retrieving task from queue: " + e.getMessage());
            return null;
        }
    }
    
    /**
     * Checks if the queue is empty in a thread-safe manner.
     * @return true if the queue is empty, false otherwise
     */
    public synchronized boolean isEmpty() {
        try {
            return queue.isEmpty();
        } catch (Exception e) {
            System.out.println("Error checking queue status: " + e.getMessage());
            return true;
        }
    }
    
    /**
     * Gets the current size of the queue in a thread-safe manner.
     * @return The number of people in the queue
     */
    public synchronized int size() {
        try {
            return queue.size();
        } catch (Exception e) {
            System.out.println("Error getting queue size: " + e.getMessage());
            return 0;
        }
    }
}

