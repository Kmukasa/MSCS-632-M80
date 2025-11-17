"Ride Sharing App Demonstration Script"
"Demonstrating OOP Principles: Inheritance, Polymorphism, and Encapsulation"

"Load all class definitions"
FileStream fileIn: 'Ride.st'.
FileStream fileIn: 'StandardRide.st'.
FileStream fileIn: 'PremiumRide.st'.
FileStream fileIn: 'Driver.st'.
FileStream fileIn: 'Rider.st'.

"Initialize class variables"
StandardRide initialize.
PremiumRide initialize.

Transcript clear.
Transcript show: '=== Ride Sharing App Demonstration ==='.
Transcript cr.
Transcript show: 'Demonstrating OOP Principles: Inheritance, Polymorphism, and Encapsulation'.
Transcript cr; cr.

"Create instances of different ride types"
ride1 := StandardRide new: 'R001' pickup: '123 Main St' dropoff: '456 Oak Ave' distance: 5.5.
ride2 := PremiumRide new: 'R002' pickup: '789 Pine Rd' dropoff: '321 Elm St' distance: 8.2.
ride3 := StandardRide new: 'R003' pickup: '555 Broadway' dropoff: '777 Market St' distance: 3.0.
ride4 := PremiumRide new: 'R004' pickup: '999 Park Ave' dropoff: '111 Center St' distance: 12.5.

"Demonstrate polymorphism: Store different ride types in an OrderedCollection"
rides := OrderedCollection new.
rides add: ride1.
rides add: ride2.
rides add: ride3.
rides add: ride4.

Transcript show: '=== POLYMORPHISM DEMONSTRATION ==='.
Transcript cr.
Transcript show: 'Calling fare() and rideDetails() polymorphically on different ride types:'.
Transcript cr; cr.

"Polymorphically call fare() and rideDetails() on all rides"
rides do: [:ride |
	"Recalculate fare (demonstrating polymorphic call)"
	calculatedFare := ride fare.
	ride fareAmount: calculatedFare.
	
	"Display ride details (demonstrating polymorphic call)"
	ride rideDetails.
	Transcript cr
].

"Create Driver instances"
driver1 := Driver new: 'D001' name: 'John Smith' rating: 4.8.
driver2 := Driver new: 'D002' name: 'Sarah Johnson' rating: 4.9.

"Demonstrate encapsulation: Add rides to drivers using the public method"
Transcript show: '=== ENCAPSULATION DEMONSTRATION ==='.
Transcript cr.
Transcript show: 'Adding rides to drivers (assignedRides is private, accessed via addRide:):'.
Transcript cr; cr.

driver1 addRide: ride1.
driver1 addRide: ride2.
driver2 addRide: ride3.
driver2 addRide: ride4.

"Display driver information"
driver1 getDriverInfo.
driver2 getDriverInfo.

"Create Rider instances"
rider1 := Rider new: 'RDR001' name: 'Alice Brown'.
rider2 := Rider new: 'RDR002' name: 'Bob Wilson'.

"Demonstrate adding rides to riders"
Transcript cr.
Transcript show: '=== RIDER FUNCTIONALITY ==='.
Transcript cr.
Transcript show: 'Riders requesting rides:'.
Transcript cr; cr.

rider1 requestRide: ride1.
rider1 requestRide: ride2.
rider2 requestRide: ride3.
rider2 requestRide: ride4.

"Display rider ride history"
rider1 viewRides.
rider2 viewRides.

"Summary"
Transcript cr.
Transcript show: '=== SUMMARY ==='.
Transcript cr.
Transcript show: 'Total rides created: ', rides size printString.
Transcript cr.
Transcript show: 'Total drivers: 2'.
Transcript cr.
Transcript show: 'Total riders: 2'.
Transcript cr; cr.

Transcript show: '=== OOP PRINCIPLES DEMONSTRATED ==='.
Transcript cr.
Transcript show: '1. Inheritance: StandardRide and PremiumRide inherit from Ride'.
Transcript cr.
Transcript show: '2. Polymorphism: fare() method called polymorphically on collection of Rides'.
Transcript cr.
Transcript show: '3. Encapsulation: Driver''s assignedRides is private, accessed via addRide:'.
Transcript cr.
Transcript show: '4. Abstraction: Base class Ride defines interface, subclasses implement specifics'.
Transcript cr.

