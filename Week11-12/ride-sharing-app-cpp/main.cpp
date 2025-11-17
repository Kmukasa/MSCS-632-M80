#include <iostream>
#include <vector>
#include "Ride.h"
#include "StandardRide.h"
#include "PremiumRide.h"
#include "Driver.h"
#include "Rider.h"

int main() {
    std::cout << "=== Ride Sharing App Demonstration ===" << std::endl;
    std::cout << "Demonstrating OOP Principles: Inheritance, Polymorphism, and Encapsulation\n" << std::endl;
    
    // Create instances of different ride types
    StandardRide ride1("R001", "123 Main St", "456 Oak Ave", 5.5);
    PremiumRide ride2("R002", "789 Pine Rd", "321 Elm St", 8.2);
    StandardRide ride3("R003", "555 Broadway", "777 Market St", 3.0);
    PremiumRide ride4("R004", "999 Park Ave", "111 Center St", 12.5);
    
    // Demonstrate polymorphism: Store different ride types in a vector of Ride pointers
    std::vector<Ride*> rides;
    rides.push_back(&ride1);
    rides.push_back(&ride2);
    rides.push_back(&ride3);
    rides.push_back(&ride4);
    
    std::cout << "=== POLYMORPHISM DEMONSTRATION ===" << std::endl;
    std::cout << "Calling fare() and rideDetails() polymorphically on different ride types:\n" << std::endl;
    
    // Polymorphically call fare() and rideDetails() on all rides
    for (size_t i = 0; i < rides.size(); ++i) {
        // Recalculate fare (demonstrating polymorphic call)
        double calculatedFare = rides[i]->fare();
        rides[i]->setFare(calculatedFare);
        
        // Display ride details (demonstrating polymorphic call)
        rides[i]->rideDetails();
        std::cout << std::endl;
    }
    
    // Create Driver instances
    Driver driver1("D001", "John Smith", 4.8);
    Driver driver2("D002", "Sarah Johnson", 4.9);
    
    // Demonstrate encapsulation: Add rides to drivers using the public method
    std::cout << "=== ENCAPSULATION DEMONSTRATION ===" << std::endl;
    std::cout << "Adding rides to drivers (assignedRides is private, accessed via addRide()):\n" << std::endl;
    
    driver1.addRide(&ride1);
    driver1.addRide(&ride2);
    driver2.addRide(&ride3);
    driver2.addRide(&ride4);
    
    // Display driver information
    driver1.getDriverInfo();
    driver2.getDriverInfo();
    
    // Create Rider instances
    Rider rider1("RDR001", "Alice Brown");
    Rider rider2("RDR002", "Bob Wilson");
    
    // Demonstrate adding rides to riders
    std::cout << "\n=== RIDER FUNCTIONALITY ===" << std::endl;
    std::cout << "Riders requesting rides:\n" << std::endl;
    
    rider1.requestRide(&ride1);
    rider1.requestRide(&ride2);
    rider2.requestRide(&ride3);
    rider2.requestRide(&ride4);
    
    // Display rider ride history
    rider1.viewRides();
    rider2.viewRides();
    
    // Summary
    std::cout << "\n=== SUMMARY ===" << std::endl;
    std::cout << "Total rides created: " << rides.size() << std::endl;
    std::cout << "Total drivers: 2" << std::endl;
    std::cout << "Total riders: 2" << std::endl;
    
    std::cout << "\n=== OOP PRINCIPLES DEMONSTRATED ===" << std::endl;
    std::cout << "1. Inheritance: StandardRide and PremiumRide inherit from Ride" << std::endl;
    std::cout << "2. Polymorphism: fare() method called polymorphically on vector of Ride*" << std::endl;
    std::cout << "3. Encapsulation: Driver's assignedRides is private, accessed via addRide()" << std::endl;
    std::cout << "4. Abstraction: Base class Ride defines interface, subclasses implement specifics" << std::endl;
    
    return 0;
}

