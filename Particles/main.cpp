//
//  main.cpp
//  Particles
//
//  Created by Al Masgai on 1/5/18.
//  Copyright © 2018 Al Masgai. All rights reserved.
//

#include <SDL.h>
#include <iostream>
#include <math.h>
#include "Screen.hpp"
#include "Swarm.hpp"

using namespace std;

int main(int argc, char* args[]){
    
    // Initializing/Seeding a random number based on the time program runs
    srand(time(NULL));
    
    Screen screen;
    
    if (screen.init() == false) {
        cout << "Error initializing.." << endl;
    }else{
        cout << "Initializing SDL..." << endl;
    }
    
    Swarm swarm;
    
    // Creating a loop so that the window can be constantly updated
    while (true) {
        // update & draw particles
        // Check events
        
        // Gets the number of milliseconds since program ran
        int elapsed = SDL_GetTicks();
        
        // Allows a pulsating effect
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.002)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.002)) * 128);
        unsigned char blue = (unsigned char)((1 + cos(elapsed * 0.002)) * 128);
        
        for (int y = 0; y < Screen::HEIGHT; y++) {
            for (int x = 0; x < Screen::WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }
                
        // Draw to the screen
        screen.update();
        
        if (screen.processEvents() == false) {
            break;
        }
    }
    
    // Cleaning things up by calling the close function
    screen.close();
    
    return 0;
}
