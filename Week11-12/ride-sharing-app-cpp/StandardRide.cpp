#include "StandardRide.h"

// Standard rate per mile
const double StandardRide::STANDARD_RATE_PER_MILE = 1.50;

// Constructor
StandardRide::StandardRide(const std::string& id, const std::string& pickup, 
                           const std::string& dropoff, double dist)
    : Ride(id, pickup, dropoff, dist) {
    // Calculate and set fare upon construction
    setFare(fare());
}

// Override fare calculation for standard rides
double StandardRide::fare() {
    return distance * STANDARD_RATE_PER_MILE;
}

