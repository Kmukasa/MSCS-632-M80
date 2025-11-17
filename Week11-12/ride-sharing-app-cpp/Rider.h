#ifndef RIDER_H
#define RIDER_H

#include "Ride.h"
#include <vector>
#include <string>

class Rider {
private:
    std::string riderID;
    std::string name;
    std::vector<Ride*> requestedRides;

public:
    // Constructor
    Rider(const std::string& id, const std::string& riderName);
    
    // Destructor
    ~Rider();
    
    // Method to request a ride (add to requestedRides list)
    void requestRide(Ride* ride);
    
    // Method to display ride history
    void viewRides() const;
    
    // Getters
    std::string getRiderID() const;
    std::string getName() const;
    int getRideCount() const;
};

#endif // RIDER_H

