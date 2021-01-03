//Cosc 2947E - Object Oriented Programming Using C++
//Created by Jordan Tiedemann on 2020-11-01
//Lattice.cpp
//Version 1.3

#include "Lattice.hpp"

//	Constructor
//  Class:  Lattice
//  Member: Lattice()
//
//	Generates a Lattice object of predetermined size (indicated in Lattice.hpp)
//	Initializes all sites as Empty
//
Lattice::Lattice()
	: occupied_(0), open_(0)
{
	for (int widthIndex = 0; widthIndex < LATTICE_WIDTH; ++widthIndex) {
		for (int heightIndex = 0; heightIndex < LATTICE_HEIGHT; ++heightIndex) {
			dlaSimulation[widthIndex][heightIndex] = Site::Empty;
		}
	}
}

//	Accessor
//  Class:  Lattice
//  Member: getState()
//
//	Accessor for the value of the requested Site
//
Lattice::Site Lattice::getState(int widthIndex, int heightIndex) {
	return dlaSimulation[widthIndex][heightIndex];
}

//	Accessor
//  Class:  Lattice
//  Member: getOccupied()
//
//	Accessor for the stored value representing the number of occupied Sites
//
int Lattice::getOccupied() {
	return occupied_;
}

//	Accessor
//  Class:  Lattice
//  Member: getOccupied()
//
//	Accessor for the stored value representing the number of open Sites
//
int Lattice::getOpen() {
	return open_;
}

//	Mutator
//  Class:  Lattice
//  Member: setState()
//
//  Sets the value of the requested site to the specified value.
//	Maintains the correct count of Open and Occupied sites.
//
void Lattice::setState(int widthIndex, int heightIndex, Lattice::Site set) {
	Lattice::Site target = Lattice::getState(widthIndex, heightIndex);
	switch (set) {
		case Site::Empty:
			if (target != Site::Empty) {
				if (target == Site::Occupied) {
					--occupied_;
				}
				if (target == Site::Open) {
					--open_;
				}
				dlaSimulation[widthIndex][heightIndex] = Site::Empty;
			}
			break;
		case Site::Occupied:
			if (target != Site::Occupied) {
				if (target == Site::Open) {
					--open_;
				}
				dlaSimulation[widthIndex][heightIndex] = Site::Occupied;
				++occupied_;
			}
			break;
		case Site::Open:
			if (target != Site::Open) {
				if (target == Site::Occupied) {
					--occupied_;
				}
				dlaSimulation[widthIndex][heightIndex] = Site::Open;
				++open_;
			}
			break;
	}
}
