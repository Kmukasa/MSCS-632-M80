import java.util.*;

public class Memory {
    public static void main(String[] args) {
        // Allocate memory on the heap using an array
        List<Integer> data = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
        System.out.println("Original data: " + data);
        // In Java, assignment creates a reference copy (not ownership transfer)
        List<Integer> referencedData = data;
        System.out.println("Referenced data: " + referencedData);

        // Demonstrate shared reference behavior
        referencedData.add(6); // Modifies the shared object
        System.out.println("Original after modification: " + data); // Shows the change

        // Create a mutable string-like object
        StringBuilder mutableData = new StringBuilder("Hello");


       // Pass reference to method and modify
        modifyString(mutableData);
        System.out.println("Modified data: " + mutableData);

        // Demonstrates "cleanup" by removing references
        data = null; // Remove reference

        // Demonstrate automatic cleanup
        mutableData = null; // Eligible for GC if no other references
        System.out.println("Memory will be freed automatically by the garbage collector");

    }
}