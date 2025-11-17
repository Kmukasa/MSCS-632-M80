"StandardRide Class - Standard ride type with $1.50 per mile rate"

Ride subclass: #StandardRide
	instanceVariableNames: ''
	classVariableNames: 'StandardRatePerMile'
	poolDictionaries: ''
	category: 'RideSharing'!

StandardRide class initialize
	"Initialize class variables"
	StandardRatePerMile := 1.50
!

!StandardRide class methodsFor: 'instance creation'!

new: anID pickup: aPickup dropoff: aDropoff distance: aDistance
	"Create a new StandardRide instance"
	^super new: anID pickup: aPickup dropoff: aDropoff distance: aDistance
		initializeStandardRide
! !

!StandardRide methodsFor: 'initialization'!

initializeStandardRide
	"Calculate and set fare upon construction"
	self fareAmount: self fare
! !

!StandardRide methodsFor: 'calculating'!

fare
	"Override fare calculation for standard rides"
	^distance * StandardRatePerMile
! !

