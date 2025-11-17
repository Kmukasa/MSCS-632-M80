"Rider Class - Represents a rider with requested rides"

Object subclass: #Rider
	instanceVariableNames: 'riderID name requestedRides'
	classVariableNames: ''
	poolDictionaries: ''
	category: 'RideSharing'!

!Rider class methodsFor: 'instance creation'!

new: anID name: aName
	"Create a new Rider instance"
	^self new
		riderID: anID;
		name: aName;
		yourself
! !

!Rider methodsFor: 'initialization'!

riderID: anID
	riderID := anID
!

name: aName
	name := aName.
	requestedRides := OrderedCollection new
! !

!Rider methodsFor: 'accessing'!

riderID
	^riderID
!

name
	^name
!

rideCount
	^requestedRides size
!

requestRide: aRide
	"Request a ride (add to requestedRides list)"
	aRide ifNotNil: [requestedRides add: aRide]
!

viewRides
	"Display ride history"
	Transcript cr; cr.
	Transcript show: '=== Ride History for ', name, ' ==='.
	Transcript cr.
	Transcript show: 'Rider ID: ', riderID.
	Transcript cr.
	Transcript show: 'Total Rides Requested: ', requestedRides size printString.
	Transcript cr.
	requestedRides isEmpty ifTrue: [
		Transcript show: 'No rides requested yet.'.
		Transcript cr
	] ifFalse: [
		Transcript show: 'Ride Details:'.
		Transcript cr.
		requestedRides doWithIndex: [:ride :index |
			Transcript show: '--- Ride ', index printString, ' ---'.
			ride rideDetails
		]
	]
! !

