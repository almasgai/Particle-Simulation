//
//  main.cpp
//  Particles
//
//  Created by Al Masgai on 1/5/18.
//  Copyright © 2018 Al Masgai. All rights reserved.
//

#include <SDL.h>
#include <iostream>
#include "Screen.hpp"

using namespace std;

int main( int argc, char* args[] ){
    Screen screen;
    
    if (screen.init() == false) {
        cout << "SDL is running.." << endl;
    }else{
        cout << "There is a problem with initializing SDL" << endl;
    }
    
    // Tells the main loop of the program when to quit & exit
    bool quitProgram = false;
    
    // Creating a loop so that the window can be constantly updated
    while (true) {
        // update & draw particles
        // Check events
        
        if (screen.processEvents() == false) {
            break;
        }
    }
    
    // Cleaning things up by calling the close function
    screen.close();
    
    return 0;
}
