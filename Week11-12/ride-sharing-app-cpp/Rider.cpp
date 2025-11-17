#include "Rider.h"
#include <iostream>

// Constructor
Rider::Rider(const std::string& id, const std::string& riderName)
    : riderID(id), name(riderName) {
}

// Destructor
Rider::~Rider() {
    // Note: We don't delete the Ride pointers here because they may be shared
    // with other objects (like Driver). In a real application, you'd use smart pointers.
}

// Request a ride (add to requestedRides list)
void Rider::requestRide(Ride* ride) {
    if (ride != nullptr) {
        requestedRides.push_back(ride);
    }
}

// Display ride history
void Rider::viewRides() const {
    std::cout << "\n=== Ride History for " << name << " ===" << std::endl;
    std::cout << "Rider ID: " << riderID << std::endl;
    std::cout << "Total Rides Requested: " << requestedRides.size() << std::endl;
    
    if (requestedRides.empty()) {
        std::cout << "No rides requested yet." << std::endl;
    } else {
        std::cout << "\nRide Details:" << std::endl;
        for (size_t i = 0; i < requestedRides.size(); ++i) {
            std::cout << "\n--- Ride " << (i + 1) << " ---" << std::endl;
            requestedRides[i]->rideDetails();
        }
    }
}

// Getters
std::string Rider::getRiderID() const {
    return riderID;
}

std::string Rider::getName() const {
    return name;
}

int Rider::getRideCount() const {
    return requestedRides.size();
}

