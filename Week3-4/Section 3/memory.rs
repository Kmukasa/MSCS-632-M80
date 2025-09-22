fn main() {
    // Allocate memory on the heap using Box
    let data = Box::new(vec![1, 2, 3, 4, 5]);
    println!("Original data: {:?}", data);
    
    // Transfer ownership to another variable
    let owned_data = data;
    // `data` is no longer valid here - ownership moved
    
    // Borrow the data immutably
    let borrowed_ref = &owned_data;
    println!("Borrowed data: {:?}", borrowed_ref);
    
    // Create a mutable allocation
    let mut mutable_data = Box::new(String::from("Hello"));
    
    // Borrow mutably and modify
    {
        let mutable_ref = &mut mutable_data;
        mutable_ref.push_str(", World!");
    } // mutable borrow ends here
    
    println!("Modified data: {}", mutable_data);
    
    // Demonstrate automatic cleanup
    drop(owned_data); // Explicit drop (usually automatic)
    println!("Memory freed automatically when variables go out of scope");
    
    // mutable_data will be automatically freed at end of main()
}