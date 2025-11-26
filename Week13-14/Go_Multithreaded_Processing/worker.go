package main

import (
	"fmt"
	"time"
)

const processingDelay = 200 * time.Millisecond // Simulate processing time

// Worker processes people from the shared channel.
// Each worker retrieves people, greets them, and logs the results.
func Worker(workerID int, taskChan <-chan *Person, errorChan chan<- error) {
	defer func() {
		// Recover from any panics and log them as errors
		if r := recover(); r != nil {
			err := fmt.Errorf("Worker %d panicked: %v", workerID, r)
			select {
			case errorChan <- err:
			default:
				// Error channel is full, log to console
				fmt.Printf("Worker %d encountered error (channel full): %v\n", workerID, err)
			}
		}
	}()

	fmt.Printf("Worker %d started\n", workerID)

	for person := range taskChan {
		// Check for nil person (defensive programming)
		if person == nil {
			err := fmt.Errorf("Worker %d received nil person", workerID)
			select {
			case errorChan <- err:
			default:
				fmt.Printf("Worker %d encountered error (channel full): %v\n", workerID, err)
			}
			continue
		}

		// Process the person (greet them)
		// Simulate processing delay
		time.Sleep(processingDelay)

		// Greet the person
		fmt.Printf("Worker %d greets %s\n", workerID, person.Name)
	}

	fmt.Printf("Worker %d completed all tasks\n", workerID)
}

