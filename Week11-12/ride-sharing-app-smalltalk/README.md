# Ride Sharing App - Smalltalk Implementation

This is a Smalltalk implementation of the ride sharing application, demonstrating Object-Oriented Programming principles: Inheritance, Polymorphism, and Encapsulation.

## Classes

### 1. Ride (Base Class)
- **Instance Variables**: `rideID`, `pickupLocation`, `dropoffLocation`, `distance`, `fareAmount`
- **Methods**:
  - `fare` - Abstract method for fare calculation (must be overridden)
  - `rideDetails` - Displays ride information
  - Accessor methods for all instance variables

### 2. StandardRide (Subclass of Ride)
- **Class Variable**: `StandardRatePerMile` = 1.50
- **Methods**:
  - `fare` - Overrides base class method, calculates fare at $1.50 per mile

### 3. PremiumRide (Subclass of Ride)
- **Class Variable**: `PremiumRatePerMile` = 2.50
- **Methods**:
  - `fare` - Overrides base class method, calculates fare at $2.50 per mile

### 4. Driver
- **Instance Variables**: `driverID`, `name`, `rating`, `assignedRides` (private OrderedCollection)
- **Methods**:
  - `addRide:` - Adds a ride to the driver's assigned rides (encapsulation)
  - `getDriverInfo` - Displays driver information and ride count

### 5. Rider
- **Instance Variables**: `riderID`, `name`, `requestedRides` (OrderedCollection)
- **Methods**:
  - `requestRide:` - Adds a ride to the rider's requested rides
  - `viewRides` - Displays ride history

## Running the Application

### Using GNU Smalltalk

1. **Load all classes**:
   ```bash
   gst Ride.st StandardRide.st PremiumRide.st Driver.st Rider.st
   ```

2. **Run the demo**:
   ```bash
   gst demo.st
   ```

   Or interactively:
   ```bash
   gst
   ```
   Then in the Smalltalk prompt:
   ```smalltalk
   FileStream fileIn: 'Ride.st'.
   FileStream fileIn: 'StandardRide.st'.
   FileStream fileIn: 'PremiumRide.st'.
   FileStream fileIn: 'Driver.st'.
   FileStream fileIn: 'Rider.st'.
   StandardRide initialize.
   PremiumRide initialize.
   "Then run the demo code from demo.st"
   ```

### Using Pharo or Squeak

1. Open the image
2. Use the file browser to load each `.st` file
3. Execute the demo code from `demo.st` in a workspace

## OOP Principles Demonstrated

1. **Inheritance**: `StandardRide` and `PremiumRide` inherit from `Ride`
2. **Polymorphism**: The `fare` method is called polymorphically on a collection containing different ride types
3. **Encapsulation**: `Driver`'s `assignedRides` is a private instance variable, accessed only through the `addRide:` method
4. **Abstraction**: The base class `Ride` defines the interface with `fare` as an abstract method (using `subclassResponsibility`), and subclasses implement the specific fare calculation logic

## Notes

- In Smalltalk, instance variables are private by default (encapsulation)
- Methods are dispatched based on the receiver's class (polymorphism)
- The `subclassResponsibility` method in the base class `fare` method ensures subclasses must override it
- Collections in Smalltalk (like `OrderedCollection`) provide natural polymorphism support

