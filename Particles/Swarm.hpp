//
//  Swarm.hpp
//  Particles
//
//  Created by Al Masgai on 1/18/18.
//  Copyright © 2018 Al Masgai. All rights reserved.
//

#ifndef Swarm_hpp
#define Swarm_hpp

#include <stdio.h>

#include "Particle.hpp"

class Swarm{
private:
    Particle *m_Particles;
    
public:
    Swarm();
    virtual ~Swarm();
    const static int NPARTICLES = 5000;
    Particle * const getPartickes(){ return m_Particles;}
};

#endif /* Swarm_hpp */







