"Driver Class - Represents a driver with assigned rides"

Object subclass: #Driver
	instanceVariableNames: 'driverID name rating assignedRides'
	classVariableNames: ''
	poolDictionaries: ''
	category: 'RideSharing'!

!Driver class methodsFor: 'instance creation'!

new: anID name: aName rating: aRating
	"Create a new Driver instance"
	^self new
		driverID: anID;
		name: aName;
		rating: aRating;
		yourself
! !

!Driver methodsFor: 'initialization'!

driverID: anID
	driverID := anID
!

name: aName
	name := aName
!

rating: aRating
	rating := aRating.
	assignedRides := OrderedCollection new
! !

!Driver methodsFor: 'accessing'!

driverID
	^driverID
!

name
	^name
!

rating
	^rating
!

rideCount
	^assignedRides size
!

addRide: aRide
	"Add a ride to the driver's assigned rides list (encapsulation - assignedRides is private)"
	aRide ifNotNil: [assignedRides add: aRide]
!

getDriverInfo
	"Display driver information"
	Transcript cr; cr.
	Transcript show: '=== Driver Information ==='.
	Transcript cr.
	Transcript show: 'Driver ID: ', driverID.
	Transcript cr.
	Transcript show: 'Name: ', name.
	Transcript cr.
	Transcript show: 'Rating: ', rating printString, ' / 5.0'.
	Transcript cr.
	Transcript show: 'Total Rides Completed: ', assignedRides size printString.
	Transcript cr.
	assignedRides isEmpty ifFalse: [
		Transcript show: 'Assigned Rides:'.
		Transcript cr.
		assignedRides doWithIndex: [:ride :index |
			Transcript show: '  Ride ', index printString, ': ', ride rideID.
			Transcript cr
		]
	]
! !

