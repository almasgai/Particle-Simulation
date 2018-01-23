//
//  Swarm.cpp
//  Particles
//
//  Created by Al Masgai on 1/18/18.
//  Copyright © 2018 Al Masgai. All rights reserved.
//

#include "Swarm.hpp"

Swarm::Swarm(): lastTime(0){
    m_Particles = new Particle[NPARTICLES];
}
Swarm::~Swarm(){
    delete [] m_Particles;
}

void Swarm::update(int elapsed){
    
    int interval = elapsed - lastTime;
    
    for (int i = 0; i < Swarm::NPARTICLES; i++) {
        m_Particles[i].update(interval);
    }
    
    lastTime = elapsed;
}
