/**
 * Worker thread that processes people from the shared queue.
 * Each worker retrieves people, greets them, and logs the results.
 */
public class WorkerThread extends Thread {
    private SharedQueue queue;
    private int workerId;
    private static final int PROCESSING_DELAY_MS = 200; // Simulate processing time
    
    /**
     * Constructor to create a worker thread.
     * @param queue The shared queue to retrieve tasks from
     * @param workerId The unique identifier for this worker
     */
    public WorkerThread(SharedQueue queue, int workerId) {
        this.queue = queue;
        this.workerId = workerId;
    }
    
    /**
     * Main execution method for the worker thread.
     * Continuously retrieves people from the queue and greets them.
     */
    @Override
    public void run() {
        System.out.println("Worker " + workerId + " started");
        
        try {
            while (true) {
                // Retrieve a person from the queue
                Person person = queue.getTask();
                
                // If queue is empty, exit the loop
                if (person == null) {
                    // Double-check if queue is truly empty
                    if (queue.isEmpty()) {
                        break;
                    }
                    // If not empty, wait a bit and try again
                    Thread.sleep(50);
                    continue;
                }
                
                // Process the person (greet them)
                try {
                    // Simulate processing delay
                    Thread.sleep(PROCESSING_DELAY_MS);
                    
                    // Greet the person
                    System.out.println("Worker " + workerId + " greets " + person.getName());
                    
                } catch (InterruptedException e) {
                    System.out.println("Worker " + workerId + " was interrupted during processing: " + e.getMessage());
                    Thread.currentThread().interrupt(); // Restore interrupt status
                    break;
                } catch (Exception e) {
                    System.out.println("Worker " + workerId + " encountered error while processing " + 
                                     person.getName() + ": " + e.getMessage());
                }
            }
            
            System.out.println("Worker " + workerId + " completed all tasks");
            
        } catch (InterruptedException e) {
            System.out.println("Worker " + workerId + " was interrupted: " + e.getMessage());
            Thread.currentThread().interrupt(); // Restore interrupt status
        } catch (Exception e) {
            System.out.println("Worker " + workerId + " encountered unexpected error: " + e.getMessage());
            e.printStackTrace();
        }
    }
    
    /**
     * Gets the worker ID.
     * @return The worker's ID
     */
    public int getWorkerId() {
        return workerId;
    }
}

