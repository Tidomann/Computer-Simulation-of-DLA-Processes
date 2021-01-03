//
//  main.cpp
//  DLA
//
//  Created by Ralf J. Meyer on 2020-10-07.
//  Copyright © 2020 Ralf Meyer. All rights reserved.
//

#include <cstdlib>
#include <iostream>
using namespace std;

#include "OpenSimulation.hpp"
#include "PeriodicSimulation.hpp"


void simulateOpen(int);
void simulatePeriodic(int);

int main(int argc, const char * argv[]) {
    // Obtain seed for rand().
    int seed = 1;
    cout << "Enter the seed for the random number generator: ";
    cin >> seed;
    srand(seed);
    
    // Prompt user for system type
    char sys;
    cout << "Do you want to simulate an open or a periodic system [o/p]? ";
    cin >> sys;
    if (sys != 'o' and sys != 'p' ) {
        cout << "Illegal input. Assuming a periodic system\n;";
    }
    
    // Prompt user for number of particles to be added to the system
    int npart = 0;
    cout << "How many particles do you want to add to the system? ";
    cin >> npart;

    // Run the simulation of the requested type
    if (sys == 'o') {
        simulateOpen(npart);
    }
    else {
            simulatePeriodic(npart);    
    }

    return 0;
}



//
//  Function:   simulateOpen()
//
//  This function simulates a system with an open border at the top of the
//  system and a sticky seed on the bottom. Periodic boundary conditions
//  apply at the left and right borders. The function creates a simulation
//  object of type OpenSimulation, adds 'npart' particles to it and prints
//  the final state to the console.
//
void simulateOpen(int npart)  {
    OpenSimulation  sim;
    
    for (int n = 0; n < npart; ++n) {
        sim.addParticle();
    }
    if (sim.numAddedParticles() == npart) {
        sim.print();
    }
    else {
        cerr << "Program error: Incorrect number of particles in the system\n";
    }
}


//
//  Function:   simulatePeriodic()
//
//  This function simulates a system with periodic boundary conditions on all
//  sides. The function creates a simulation object of type Simulation, adds
//  'npart' particles to it and prints the final state to the console.
//
void simulatePeriodic(int npart)  {
    PeriodicSimulation  sim;
    
    for (int n = 0; n < npart; ++n) {
        sim.addParticle();
    }
    if (sim.numAddedParticles() == npart) {
        sim.print();
    }
    else {
        cerr << "Program error: Incorrect number of particles in the system\n";
    }
}
