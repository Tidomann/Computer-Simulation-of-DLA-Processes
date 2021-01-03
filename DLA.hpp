//  Cosc 2947E - Object Oriented Programming Using C++
//  Created by Ralf J. Meyer on 2020-10-07.
//	Modified by Jordan Tiedemann on 2020-11-01
//  DLA.hpp
//	Version 2.0

#ifndef DLA_hpp
#define DLA_hpp

#include "Lattice.hpp"


//
//  Class:  DLA
//
//  Objects of type DLA are used to run a two-dimenional DLA simulation. The
//  centre of the class is a function that moves a particle from a starting
//  position until it sticks to the existing particles or leaves the system.
//  In addition, functions are provided to set seed particles and open cells
//  where particles can escape. Details of the simulation such as the position
//  of initial seed particles, boundary conditions or the number of particles
//  to be added are not handled by this class.
//
class DLA {
public:

    //  Constructor
    DLA();

    // Accessor
    // Get the number of particles (including seeds) in the system.
    int     numParticles();

    // Mutators
    // Set a seed particle at a given position
    void    setSeed(int, int);

    // Declare a lattice site as open (particles escape from there)
    void    makeOpen(int, int);

    //Functions
    // Enter a new particle and move it until it sticks or leaves the system
    bool    enterParticle(int,int);
    // Print contents of the system lattice to cout
    void    printWorld();
    // Check the neighbours of the given lattice parameters
    bool    checkNeighbours(int, int);
    // Moves the particle in a random direction (Left, Right, Up, Down), checks for lattice boundaries
    void    moveParticle(int&, int&);
    
private:
    Lattice system;
};

#endif /* DLA_hpp */
