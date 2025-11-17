#ifndef STANDARDRIDE_H
#define STANDARDRIDE_H

#include "Ride.h"

class StandardRide : public Ride {
private:
    static const double STANDARD_RATE_PER_MILE; // $1.50 per mile

public:
    // Constructor
    StandardRide(const std::string& id, const std::string& pickup, 
                 const std::string& dropoff, double dist);
    
    // Override the fare calculation method
    double fare() override;
};

#endif // STANDARDRIDE_H

