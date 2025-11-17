#ifndef DRIVER_H
#define DRIVER_H

#include "Ride.h"
#include <vector>
#include <string>

class Driver {
private:
    std::string driverID;
    std::string name;
    double rating;
    std::vector<Ride*> assignedRides; // Private - encapsulation

public:
    // Constructor
    Driver(const std::string& id, const std::string& driverName, double driverRating);
    
    // Destructor
    ~Driver();
    
    // Method to add a ride to the driver's assigned rides list
    void addRide(Ride* ride);
    
    // Method to display driver information
    void getDriverInfo() const;
    
    // Getters
    std::string getDriverID() const;
    std::string getName() const;
    double getRating() const;
    int getRideCount() const;
};

#endif // DRIVER_H

