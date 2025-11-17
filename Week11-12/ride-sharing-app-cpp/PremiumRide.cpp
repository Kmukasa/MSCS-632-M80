#include "PremiumRide.h"

// Premium rate per mile
const double PremiumRide::PREMIUM_RATE_PER_MILE = 2.50;

// Constructor
PremiumRide::PremiumRide(const std::string& id, const std::string& pickup, 
                         const std::string& dropoff, double dist)
    : Ride(id, pickup, dropoff, dist) {
    // Calculate and set fare upon construction
    setFare(fare());
}

// Override fare calculation for premium rides
double PremiumRide::fare() {
    return distance * PREMIUM_RATE_PER_MILE;
}

