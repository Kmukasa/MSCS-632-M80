/**
 * Person class representing a person with a name.
 * This is a simple data class used in the data processing system.
 */
public class Person {
    private String name;
    
    /**
     * Constructor to create a Person with a name.
     * @param name The name of the person
     */
    public Person(String name) {
        this.name = name;
    }
    
    /**
     * Gets the name of the person.
     * @return The person's name
     */
    public String getName() {
        return name;
    }
    
    /**
     * Returns a string representation of the person.
     * @return String representation
     */
    @Override
    public String toString() {
        return name;
    }
}

