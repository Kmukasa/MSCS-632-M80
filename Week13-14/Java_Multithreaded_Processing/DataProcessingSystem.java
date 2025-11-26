/**
 * Main class for the Data Processing System.
 * Creates a shared queue, adds people to it, and manages worker threads
 * that process (greet) the people.
 */
public class DataProcessingSystem {
    private static final int NUM_WORKERS = 3;
    private static final int NUM_PEOPLE = 10;
    
    /**
     * Main method that initializes and runs the data processing system.
     * @param args Command line arguments (not used)
     */
    public static void main(String[] args) {
        System.out.println("=== Data Processing System Starting ===");
        System.out.println("Initializing queue with " + NUM_PEOPLE + " people");
        System.out.println("Creating " + NUM_WORKERS + " worker threads\n");
        
        SharedQueue queue = null;
        WorkerThread[] workers = null;
        
        try {
            // Create the shared queue
            queue = new SharedQueue();
            
            // Add people to the queue
            for (int i = 1; i <= NUM_PEOPLE; i++) {
                try {
                    Person person = new Person("Person " + i);
                    queue.addTask(person);
                } catch (Exception e) {
                    System.out.println("Error creating person " + i + ": " + e.getMessage());
                }
            }
            
            System.out.println("\nQueue initialized with " + queue.size() + " people\n");
            
            // Create worker threads
            workers = new WorkerThread[NUM_WORKERS];
            for (int i = 0; i < NUM_WORKERS; i++) {
                try {
                    workers[i] = new WorkerThread(queue, i + 1);
                } catch (Exception e) {
                    System.out.println("Error creating worker " + (i + 1) + ": " + e.getMessage());
                }
            }
            
            // Start all worker threads
            System.out.println("Starting all worker threads...\n");
            for (WorkerThread worker : workers) {
                if (worker != null) {
                    try {
                        worker.start();
                    } catch (Exception e) {
                        System.out.println("Error starting worker thread: " + e.getMessage());
                    }
                }
            }
            
            // Wait for all worker threads to complete
            System.out.println("Waiting for all workers to complete...\n");
            for (WorkerThread worker : workers) {
                if (worker != null) {
                    try {
                        worker.join();
                    } catch (InterruptedException e) {
                        System.out.println("Main thread interrupted while waiting for worker: " + e.getMessage());
                        Thread.currentThread().interrupt();
                    } catch (Exception e) {
                        System.out.println("Error waiting for worker thread: " + e.getMessage());
                    }
                }
            }
            
            System.out.println("\n=== All workers completed ===");
            System.out.println("Data Processing System finished successfully");
            
        } catch (Exception e) {
            System.out.println("Fatal error in Data Processing System: " + e.getMessage());
            e.printStackTrace();
        } finally {
            // Cleanup if needed
            System.out.println("\nSystem shutdown complete");
        }
    }
}

