#ifndef RIDE_H
#define RIDE_H

#include <string>

class Ride {
protected:
    std::string rideID;
    std::string pickupLocation;
    std::string dropoffLocation;
    double distance;
    double fareAmount;

public:
    // Constructor
    Ride(const std::string& id, const std::string& pickup, 
         const std::string& dropoff, double dist);
    
    // Virtual destructor for proper cleanup
    virtual ~Ride();
    
    // Virtual method for fare calculation (to be overridden by derived classes)
    virtual double fare() = 0;
    
    // Method to display ride information
    void rideDetails();
    
    // Getters
    std::string getRideID() const;
    std::string getPickupLocation() const;
    std::string getDropoffLocation() const;
    double getDistance() const;
    double getFare() const;
    
    // Setter for fare (called after calculation)
    void setFare(double f);
};

#endif // RIDE_H

