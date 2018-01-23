//
//  Particle.cpp
//  Particles
//
//  Created by Al Masgai on 1/18/18.
//  Copyright © 2018 Al Masgai. All rights reserved.
//

#include "Particle.hpp"
#include <stdlib.h>
#include <math.h>

using namespace std;

Particle::Particle(): m_x(0), m_y(0){
    
    m_direction = (2 * M_PI * rand() / RAND_MAX);
    m_speed = (0.001 * rand() / RAND_MAX);
    
}

Particle::~Particle(){ /* TODO */ }

void Particle::update(int interval){
    double xSpeed = m_speed * (cos(m_direction));
    double ySpeed = m_speed * (sin(m_direction));
    
    m_x += xSpeed * interval;
    m_y += ySpeed * interval;
    
}


