// name(s) and Perm: Angelina Suy | 4704532 
// This is the only file to submit.


#include <cstddef>
#include <cstring>
#include "car.hpp"
#include "doors.hpp"
#include "perf.hpp"
//

Car::Car(){
	manufacturer = nullptr;
	model = nullptr;
	zeroToSixtyNs = 0;
	headonDragCoeff = 0;
	horsepower = 0;
	backseatDoors = None;
	seatCount = 0;
}

Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign){
	manufacturer = const_cast<char*>(manufacturerName);
	model = const_cast<char*>(modelName);
	zeroToSixtyNs = perf.zeroToSixtyNs;
	headonDragCoeff = perf.headonDragCoeff;
	horsepower = perf.horsepower;
	backseatDoors = backseatDoorDesign;
	seatCount = numSeats;
}

Car::Car(Car const & o){
	manufacturer = o.manufacturer;
	model = o.model;
	zeroToSixtyNs = o.zeroToSixtyNs;
	headonDragCoeff = o.headonDragCoeff;
	horsepower = o.horsepower;
	backseatDoors = o.backseatDoors;
	seatCount = o.seatCount;
}

Car::~Car(){
	//recycle memory of variables
	//performancestats
}

Car& Car::operator=(Car const& o){
	manufacturer = o.manufacturer;
	model = o.model;
	zeroToSixtyNs = o.zeroToSixtyNs;
	headonDragCoeff = o.headonDragCoeff;
	horsepower = o.horsepower;
	backseatDoors = o.backseatDoors;
	seatCount = o.seatCount;
	return *this;
}

char const* Car::getManufacturer() const{
	return manufacturer;
}

char const* Car::getModel() const{
	return model;
}

PerformanceStats Car::getStats() const{
	PerformanceStats ps = {horsepower, zeroToSixtyNs, headonDragCoeff};
	return ps;
}

uint8_t Car::getSeatCount() const{
	return seatCount;
}

DoorKind Car::getBackseatDoors() const{
	return backseatDoors;
}

void Car::manufacturerChange(char const* const newManufacturer){
	manufacturer = const_cast<char*>(newManufacturer);
}

void Car::modelNameChange(char const* const newModelName){
	model = const_cast<char*>(newModelName);
}

void Car::reevaluateStats(PerformanceStats newStats){
	horsepower = newStats.horsepower;
	zeroToSixtyNs = newStats.zeroToSixtyNs;
	headonDragCoeff = newStats.headonDragCoeff;
}

void Car::recountSeats(uint8_t newSeatCount){
	seatCount = newSeatCount;
}

void Car::reexamineDoors(DoorKind newDoorKind){
	backseatDoors = newDoorKind;
}
