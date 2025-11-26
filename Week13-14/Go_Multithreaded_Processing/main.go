package main

import (
	"fmt"
	"sync"
)

const (
	numWorkers = 3
	numPeople  = 10
)

func main() {
	fmt.Println("=== Data Processing System Starting ===")
	fmt.Printf("Initializing queue with %d people\n", numPeople)
	fmt.Printf("Creating %d worker goroutines\n\n", numWorkers)

	// Create a buffered channel to hold the people (tasks)
	// Buffered channel allows adding all people before workers start processing
	taskChan := make(chan *Person, numPeople)
	errorChan := make(chan error, numWorkers)

	// Use WaitGroup to wait for all goroutines to complete
	var wg sync.WaitGroup

	// Add people to the channel
	fmt.Println("Adding people to the queue...")
	for i := 1; i <= numPeople; i++ {
		person := NewPerson(fmt.Sprintf("Person %d", i))
		taskChan <- person
		fmt.Printf("Added %s to the queue\n", person.Name)
	}

	fmt.Printf("\nQueue initialized with %d people\n\n", len(taskChan))

	// Start worker goroutines
	fmt.Println("Starting all worker goroutines...\n")
	for i := 1; i <= numWorkers; i++ {
		wg.Add(1)
		go func(workerID int) {
			defer wg.Done()
			Worker(workerID, taskChan, errorChan)
		}(i)
	}

	// Close the channel after all people are added
	// This signals to workers that no more tasks will be added
	close(taskChan)

	// Wait for all workers to complete
	fmt.Println("Waiting for all workers to complete...\n")

	// Wait for all goroutines to finish
	wg.Wait()

	// Check for any errors
	select {
	case err := <-errorChan:
		if err != nil {
			fmt.Printf("Error occurred: %v\n", err)
		}
	default:
		// No errors
	}

	fmt.Println("\n=== All workers completed ===")
	fmt.Println("Data Processing System finished successfully")
	fmt.Println("\nSystem shutdown complete")
}

