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
    int lastTime;
    
public:
    Swarm();
    virtual ~Swarm();
    void update(int elapsed);
    
    const static int NPARTICLES = 50000;
    const Particle * const getParticles(){ return m_Particles;}
};

#endif /* Swarm_hpp */
