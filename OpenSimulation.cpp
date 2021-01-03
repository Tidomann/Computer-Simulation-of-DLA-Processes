//
//  OpenSimulation.cpp
//  DLA
//
//  Created by Ralf J. Meyer on 2020-10-07.
//  Copyright © 2020 Ralf Meyer. All rights reserved.
//

#include "OpenSimulation.hpp"

#include <cstdlib>


//
//  Class:  OpenSimulation
//  Member: OpenSimulation()
//
//  The constructor calls the default constructor of DLA object containing
//  the simulated system. It then adds a layer of seed particles at the
//  bottome of the system and an open boundary layer at its top.
//
OpenSimulation::OpenSimulation()
 : dla_()
{
    // Fill the bottom of the system with seed particles
    for (int ix = 0; ix < LATTICE_WIDTH; ++ix) {
        dla_.setSeed(ix, 0);
    }

    // Make the top of the system open
    for (int ix = 0; ix < LATTICE_WIDTH; ++ix) {
        dla_.makeOpen(ix, LATTICE_HEIGHT-1);
    }
}


//
//  Class:  OpenSimulation
//  Member: addParticle()
//
//  The function chooses a random entering position for a particle four layers
//  below the open top boundary. This starting position is then passed to
//  DLA::moveParticle() which moves the particle until it sticks to
//  one of the particles already in the system or leaves the system through the
//  open top boundary. Should the particle leave the system of if the initial
//  position is already occupied, the process is repeated.
//
void OpenSimulation::addParticle()
{
    int ix, iy;
    do {
        ix = std::rand() % LATTICE_WIDTH;
        iy = LATTICE_HEIGHT - 5;
    } while (!dla_.enterParticle(ix, iy));
}


//
//  Class:  OpenSimulation
//  Member: print()
//
//  The state of the simulated system is printed on the console by forwarding
//  the call to DLA::printWorld().
//
void OpenSimulation::print()
{
    dla_.printWorld();
}




//
//  Class:  OpenSimulation
//  Member: numAddedParticles()
//
//  Returns the number of particles that were added to the system.
//
int OpenSimulation::numAddedParticles()
{
    // Return total number of particles minus LATTICE_WIDTH seed particles.
    return dla_.numParticles() - LATTICE_WIDTH;
}
