//	Cosc 2947E - Object Oriented Programming Using C++
//	Created by Jordan Tiedemann on 2020-11-01
//	DLA.cpp
//	Version 2.1

#include "DLA.hpp"
#include <cstdlib>
#include <iostream>

//	Class: DLA
//	Member: DLA()
//
//	Creates a Lattice Object with predefined size detailed in Lattice.hpp
//	to be used by the DLA object to run the DLA simulation
//
DLA::DLA()
	: system()
{

}

//	Class: DLA
//	Member: enterParticle()
//
//	Enters a new particle from a starting position and
//	moves the particle until it sticks to an existing particle or leaves the system.
//	Returns false if the starting position is not empty, or if the particle leaves the system.
//	Returns true if the particle sticks to an existing particle
//
bool DLA::enterParticle(int widthIndex, int heightIndex) {

	//Check to make sure entrance site is empty
	if (system.getState(widthIndex, heightIndex) != Lattice::Site::Empty) {
		return false;
	}
	// Assign variables that can be freely changed to represent the simulated movement
	// of the particle
	int posx = widthIndex;
	int posy = heightIndex;
	bool repeat = true;
	//	Must check neighbours once before looping, this avoids the situation when the particle enters 
	//	next to an occupied site
	if (checkNeighbours(posx, posy)) {
		repeat = false;
		system.setState(posx, posy, Lattice::Site::Occupied);
		return true;
	}
	while (repeat) {
		moveParticle(posx, posy); //"randomly" moves the particle in one of four directions
		//End Condition 1: Particle enters open site
		if(system.getState(posx, posy) == Lattice::Site::Open){
			repeat = false;
			return false;
		}
		// End Condition 2: Particle neighbour is immobile
		if (checkNeighbours(posx, posy)) {
			repeat = false;
			system.setState(posx, posy, Lattice::Site::Occupied);
			return true;
		}
	}
	
}


//	Class: DLA
//	Member: setSeed()
//
//	DLA simulation sets an Occupied Site in the Lattice Object
//	at the specified position
//
void DLA::setSeed(int widthIndex, int heightIndex) {
	system.setState(widthIndex, heightIndex, Lattice::Site::Occupied);
}

//	Class: DLA
//	Member: makeOpen()
//
//	DLA simulation sets an Open Site in the Lattice Object
//	at the specified position
//
void DLA::makeOpen(int widthIndex, int heightIndex) {
	system.setState(widthIndex, heightIndex, Lattice::Site::Open);
}

//	Class: DLA
//	Member: numParticles()
//
//	Returns the number of particles that have become Occupied as well as
//	the number of seeds set in the system.
//
int DLA::numParticles() {
	return system.getOccupied();
}

//	Class: DLA
//	Member: printWorld()
//
//	Prints the content of the system lattice to cout
//	X axis ascends left to right
//	Y axis ascends bottom to top
//
void DLA::printWorld() {
	std::cout << '\n';
	for (int ny = LATTICE_HEIGHT - 1; ny >= 0; --ny) {
		for (int nx = 0; nx < LATTICE_WIDTH; ++nx) {
			switch (system.getState(nx, ny)) {
				case Lattice::Site::Occupied:
					std::cout << "X ";
					break;
				case Lattice::Site::Empty:
					std::cout << "  ";
					break;
				case Lattice::Site::Open:
					std::cout << "O ";
					break;
			}
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

//	Class: DLA
//	Member: checkNeighbours()
//
//	Checks the specified position to determine if a particle in that position has at least one of four
//	neighbours that are occupied. Function checks calculates the neighbouring position then
//	checks after each calculcation to reduce the total number of calculations should it detect a neighbour after each calculation
//	Returns true if a neighbour is an occupied site, otherwise returns false.
//
bool DLA::checkNeighbours(int widthIndex, int heightIndex) {
	// Check top neighbour
	int check = (heightIndex < LATTICE_HEIGHT - 1) ? (heightIndex + 1) : 0;
	if (system.getState(widthIndex, check) == Lattice::Site::Occupied) {
		return true;
	}
	// Check bottom neighbour
	check = (heightIndex > 0) ? (heightIndex - 1) : (LATTICE_HEIGHT - 1);
	if (system.getState(widthIndex, check) == Lattice::Site::Occupied) {
		return true;
	}
	// Check left neighbour
	check = (widthIndex > 0) ? (widthIndex - 1) : (LATTICE_WIDTH - 1);
	if (system.getState(check, heightIndex) == Lattice::Site::Occupied) {
		return true;
	}
	// Check right neighbour
	check = (widthIndex < LATTICE_WIDTH - 1) ? (widthIndex + 1) : 0;
	if (system.getState(check, heightIndex) == Lattice::Site::Occupied) {
		return true;
	}
	return false;
}

//	Class: DLA
//	Member: moveParticle()
//
//	This function will simulate movement of the particle in one of four random directions.
//	Will modify the values of the parameters (pass by referance) to simulate the movement
//	Checks boundary conditions should the particle attempt to move outside the Lattice boundaries
//
void DLA::moveParticle(int &widthIndex, int &heightIndex) {
	// Change referanced parameters by 1 Site in one of four random directions
	//	Shift the random number by 13 bits to the right
	//	prevents simple implementation of rand() having very statistical properties
	//
	//	Boundary Conditions are checked if the particles crosses one of the system borders.
	//	check within switch statements to avoid extra comparisons
	//	IE: particle goes beyond right border, it re-enters the system on the left side
	//
	switch ((std::rand() >> 13) % 4) {
	case 0: //Up
		++heightIndex;
		if (heightIndex >= LATTICE_HEIGHT) { //	check boundary statements within each switch statement
			heightIndex = 0;
		}
		break;
	case 1: //Down
		--heightIndex;
		if (heightIndex < 0) {
			heightIndex = LATTICE_HEIGHT - 1;
		}
		break;
	case 2: //Right
		++widthIndex;
		if (widthIndex >= LATTICE_WIDTH) {
			widthIndex = 0;
		}
		break;
	case 3: //Left
		--widthIndex;
		if (widthIndex < 0) {
			widthIndex = LATTICE_WIDTH - 1;
		}
		break;
	}






}


