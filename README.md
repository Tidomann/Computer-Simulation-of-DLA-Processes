# Computer-Simulation-of-DLA-Processes
Project 1 C++

Diffusion Limited Aggregation (DLA) is a process where aggregates are formed from  randomly moving particles. Structures formed through DLA can be observed in  many natural processes (for examples, see  https://en.wikipedia.org/wiki/Diffusion-limited_aggregation).

The simulated system is represented by a two-dimensional array of lattice sites. Each site can be in one of three states: empty, occupied or open. In the simulation, particles enter the system on an empty site. When a particles enters the system, it moves randomly one step to the right, to the left, upwards or downwards. Periodic boundary conditions are used if a particle crosses one of the system borders. For example, if a particle goes beyond the right border, it re-enters the system on the left side. 

The random walk of a particle ends under two conditions: If the particles reaches a site where at least one of the four neighbours is occupied, the particles becomes immobile and its site is marked as occupied. If the particle reaches a site which is in the open state, the particles leaves the system. Particles are added to the system one at a time. A new particle enters the system only when its predecessor has become immobile by sticking to its neighbours or has left the system through an open site.
