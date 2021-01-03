//  Cosc 2947E - Object Oriented Programming Using C++
//  Created by Ralf J. Meyer on 2020-10-07.
//	Modified by Jordan Tiedemann on 2020-11-01
//  Lattice.hpp
//	Version 1.3

#ifndef Lattice_hpp
#define Lattice_hpp

// Hardcoded lattice dimensions
const int   LATTICE_WIDTH = 65;
const int   LATTICE_HEIGHT = 65;


//
//  Class:  Lattice
//
//  Objects of this class contain a two dimensional array of lattice sites
//  for DLA simulation. The class provides functions to test or modify the
//  state of lattice sites. Encapsulation ensures that all sites are always
//  in one of the three allowed states.
//
class Lattice {
public:
    //  Constructor
    Lattice();

    // Type for the state of lattice sites.
    enum class Site { Empty=0, Occupied=1, Open=2 };

    // Accessor
    Site getState(int, int);
    int getOccupied();
    int getOpen();
    // Mutators
    void setState(int, int, Site);
    //Functions
    
 private:
     int occupied_;
     int open_;
     Lattice::Site dlaSimulation[LATTICE_WIDTH][LATTICE_HEIGHT];
};

#endif /* Lattice_hpp */
