#include "Driver.h"
#include <iostream>
#include <iomanip>

// Constructor
Driver::Driver(const std::string& id, const std::string& driverName, double driverRating)
    : driverID(id), name(driverName), rating(driverRating) {
}

// Destructor
Driver::~Driver() {
    // Note: We don't delete the Ride pointers here because they may be shared
    // with other objects (like Rider). In a real application, you'd use smart pointers.
}

// Add a ride to the driver's assigned rides list
void Driver::addRide(Ride* ride) {
    if (ride != nullptr) {
        assignedRides.push_back(ride);
    }
}

// Display driver information
void Driver::getDriverInfo() const {
    std::cout << "\n=== Driver Information ===" << std::endl;
    std::cout << "Driver ID: " << driverID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Rating: " << std::fixed << std::setprecision(2) 
              << rating << " / 5.0" << std::endl;
    std::cout << "Total Rides Completed: " << assignedRides.size() << std::endl;
    
    if (!assignedRides.empty()) {
        std::cout << "\nAssigned Rides:" << std::endl;
        for (size_t i = 0; i < assignedRides.size(); ++i) {
            std::cout << "  Ride " << (i + 1) << ": " 
                      << assignedRides[i]->getRideID() << std::endl;
        }
    }
}

// Getters
std::string Driver::getDriverID() const {
    return driverID;
}

std::string Driver::getName() const {
    return name;
}

double Driver::getRating() const {
    return rating;
}

int Driver::getRideCount() const {
    return assignedRides.size();
}

