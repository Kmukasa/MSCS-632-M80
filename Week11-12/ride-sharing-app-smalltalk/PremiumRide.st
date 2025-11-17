"PremiumRide Class - Premium ride type with $2.50 per mile rate"

Ride subclass: #PremiumRide
	instanceVariableNames: ''
	classVariableNames: 'PremiumRatePerMile'
	poolDictionaries: ''
	category: 'RideSharing'!

PremiumRide class initialize
	"Initialize class variables"
	PremiumRatePerMile := 2.50
!

!PremiumRide class methodsFor: 'instance creation'!

new: anID pickup: aPickup dropoff: aDropoff distance: aDistance
	"Create a new PremiumRide instance"
	^super new: anID pickup: aPickup dropoff: aDropoff distance: aDistance
		initializePremiumRide
! !

!PremiumRide methodsFor: 'initialization'!

initializePremiumRide
	"Calculate and set fare upon construction"
	self fareAmount: self fare
! !

!PremiumRide methodsFor: 'calculating'!

fare
	"Override fare calculation for premium rides"
	^distance * PremiumRatePerMile
! !

