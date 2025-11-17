#include "Ride.h"
#include <iostream>
#include <iomanip>

// Constructor
Ride::Ride(const std::string& id, const std::string& pickup, 
           const std::string& dropoff, double dist)
    : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), 
      distance(dist), fareAmount(0.0) {
}

// Virtual destructor
Ride::~Ride() {
}

// Display ride information
void Ride::rideDetails() {
    std::cout << "\n=== Ride Details ===" << std::endl;
    std::cout << "Ride ID: " << rideID << std::endl;
    std::cout << "Pickup Location: " << pickupLocation << std::endl;
    std::cout << "Dropoff Location: " << dropoffLocation << std::endl;
    std::cout << "Distance: " << std::fixed << std::setprecision(2) 
              << distance << " miles" << std::endl;
    std::cout << "Fare: $" << std::fixed << std::setprecision(2) 
              << fareAmount << std::endl;
}

// Getters
std::string Ride::getRideID() const {
    return rideID;
}

std::string Ride::getPickupLocation() const {
    return pickupLocation;
}

std::string Ride::getDropoffLocation() const {
    return dropoffLocation;
}

double Ride::getDistance() const {
    return distance;
}

double Ride::getFare() const {
    return fareAmount;
}

// Setter for fare
void Ride::setFare(double f) {
    fareAmount = f;
}

