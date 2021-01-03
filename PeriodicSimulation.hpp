//
//  PeriodicSimulation.hpp
//  DLA
//
//  Created by Ralf J. Meyer on 2020-10-07.
//  Copyright © 2020 Ralf Meyer. All rights reserved.
//

#ifndef PeriodicSimulation_hpp
#define PeriodicSimulation_hpp

#include "DLA.hpp"


//
//  Class:  PeriodicSimulation
//
//  The object manages a DLA simulation for a system with periodic boundary
//  conditions. A single seed particle is set at the centre of the system.
//  Particles are added randomly on a circle or ellipse centered around the
//  seed particle.
//
class PeriodicSimulation {
public:
    PeriodicSimulation();
    
    void  addParticle();
    void  print();
    int   numAddedParticles();

private:
    DLA     dla_;
};

#endif /* PeriodicSimulation_hpp */
