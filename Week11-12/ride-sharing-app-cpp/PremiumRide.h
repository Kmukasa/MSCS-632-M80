#ifndef PREMIUMRIDE_H
#define PREMIUMRIDE_H

#include "Ride.h"

class PremiumRide : public Ride {
private:
    static const double PREMIUM_RATE_PER_MILE; // $2.50 per mile

public:
    // Constructor
    PremiumRide(const std::string& id, const std::string& pickup, 
                const std::string& dropoff, double dist);
    
    // Override the fare calculation method
    double fare() override;
};

#endif // PREMIUMRIDE_H

