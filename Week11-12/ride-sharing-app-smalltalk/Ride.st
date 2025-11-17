"Ride Base Class - Abstract base class for all ride types"

Object subclass: #Ride
	instanceVariableNames: 'rideID pickupLocation dropoffLocation distance fareAmount'
	classVariableNames: ''
	poolDictionaries: ''
	category: 'RideSharing'!

!Ride class methodsFor: 'instance creation'!

new: anID pickup: aPickup dropoff: aDropoff distance: aDistance
	"Create a new Ride instance"
	^self new
		rideID: anID;
		pickupLocation: aPickup;
		dropoffLocation: aDropoff;
		distance: aDistance;
		yourself
! !

!Ride methodsFor: 'initialization'!

rideID: anID
	rideID := anID
!

pickupLocation: aLocation
	pickupLocation := aLocation
!

dropoffLocation: aLocation
	dropoffLocation := aLocation
!

distance: aDistance
	distance := aDistance.
	fareAmount := 0.0
! !

!Ride methodsFor: 'accessing'!

rideID
	^rideID
!

pickupLocation
	^pickupLocation
!

dropoffLocation
	^dropoffLocation
!

distance
	^distance
!

fareAmount
	^fareAmount
!

fareAmount: anAmount
	fareAmount := anAmount
!

fare
	"Abstract method - must be overridden by subclasses"
	self subclassResponsibility
!

rideDetails
	"Display ride information"
	Transcript cr; cr.
	Transcript show: '=== Ride Details ==='.
	Transcript cr.
	Transcript show: 'Ride ID: ', rideID.
	Transcript cr.
	Transcript show: 'Pickup Location: ', pickupLocation.
	Transcript cr.
	Transcript show: 'Dropoff Location: ', dropoffLocation.
	Transcript cr.
	Transcript show: 'Distance: ', distance printString, ' miles'.
	Transcript cr.
	Transcript show: 'Fare: $', fareAmount printString.
	Transcript cr
! !

