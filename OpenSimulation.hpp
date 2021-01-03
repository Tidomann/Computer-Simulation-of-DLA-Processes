//
//  OpenSimulation.hpp
//  DLA
//
//  Created by Ralf J. Meyer on 2020-10-07.
//  Copyright © 2020 Ralf Meyer. All rights reserved.
//

#ifndef OpenSimulation_hpp
#define OpenSimulation_hpp

#include "DLA.hpp"


//
//  Class:  OpenSimulation
//
//  The object manages a DLA simulation for a system with an open boundary at
//  its top border and a sticky seed layer on its bottom. Periodic boundary
//  conditions apply at the left and right boundaries.
//
class OpenSimulation {
public:
    OpenSimulation();
    
    void  addParticle();
    void  print();
    int   numAddedParticles();

private:
    DLA     dla_;
};

#endif /* OpenSimulation_hpp */
