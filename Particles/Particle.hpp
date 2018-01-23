//
//  Particle.hpp
//  Particles
//
//  Created by Al Masgai on 1/18/18.
//  Copyright © 2018 Al Masgai. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
struct Particle{
    double m_x;
    double m_y;
    
    double m_speed;
    double m_direction;
    
public:
    Particle();
    virtual ~Particle();
    void update(int interval);
};

#endif /* Particle_hpp */
