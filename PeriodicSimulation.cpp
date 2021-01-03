//
//  PeriodicSimulation.cpp
//  DLA
//
//  Created by Ralf J. Meyer on 2020-10-07.
//  Copyright © 2020 Ralf Meyer. All rights reserved.
//

#include "PeriodicSimulation.hpp"

#include <cmath>
#include <cstdlib>

#ifndef M_PI  // Accommodate non-POSIX systems
#define M_PI  3.14159265358979323846
#endif  // M_PI

//
//  Class:  PeriodicSimulation
//  Member: PeriodicSimulation()
//
//  The constructor calls the default constructor of DLA object containing
//  the simulated system and sets a seed particle into the centre of the system.
//
PeriodicSimulation::PeriodicSimulation()
 : dla_()
{
    dla_.setSeed(LATTICE_WIDTH/2, LATTICE_HEIGHT/2);
}


//
//  Class:  PeriodicSimulation
//  Member: addParticle()
//
//  The function chooses a random entering position for a particle on a circle
//  or ellipse centred around the original seed particle. This position is then
//  passed to DLA::moveParticle() which moves the particle until it sticks to
//  one of the particles already in the system. Should the initial position
//  already be occupied, the process is repeated.
//
void PeriodicSimulation::addParticle()
{
    int ix, iy;
    do {
        double phi = (2. * M_PI / RAND_MAX) * std::rand();
        ix = LATTICE_WIDTH/2*std::cos(phi) + LATTICE_WIDTH/2;
        iy = LATTICE_HEIGHT/2*std::sin(phi) + LATTICE_HEIGHT/2;
    } while (!dla_.enterParticle(ix, iy));
}


//
//  Class:  PeriodicSimulation
//  Member: print()
//
//  The state of the simulated system is printed on the console by forwarding
//  the call to DLA::printWorld().
//
void PeriodicSimulation::print()
{
    dla_.printWorld();
}


//
//  Class:  PeriodicSimulation
//  Member: numParticles()
//
//  Returns the number of particles that were added to the system.
//
int PeriodicSimulation::numAddedParticles()
{
    // Return total number of particles minus 1 seed particle.
    return dla_.numParticles() - 1;
}
