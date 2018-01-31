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

private:
    double m_speed;
    double m_direction;
    void init();

public:
    Particle();
    // This is for inheritance
    virtual ~Particle();
    void update(int interval);
};

#endif /* Particle_hpp */
