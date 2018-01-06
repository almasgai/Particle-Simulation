//
//  main.cpp
//  Particles
//
//  Created by Al Masgai on 1/5/18.
//  Copyright © 2018 Al Masgai. All rights reserved.
//

#include <SDL.h>
#include <iostream>

#define WIDTH   800
#define HEIGHT  600

using namespace std;

int main( int argc, char* args[] )
{
    // Tells the main loop of the program when to quit & exit
    bool quitProgram = false;
    
    // Creating an SDL Event object for the loop
    SDL_Event event;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "SDL FAILED" << endl;
        return 1;
    }
    
    SDL_Window * window = SDL_CreateWindow("Simulation", SDL_WINDOWPOS_UNDEFINED,
                                           SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    
    if (window == NULL) {
        SDL_Quit();
        return 1;
    }
    
    // Creating a loop so that the window can be constantly updated
    while (!quitProgram) {
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quitProgram = true;
            }
        }
        
    }
    
    
    // Close window
    SDL_DestroyWindow(window);
    // Cleans up any resource(s) SDL is using
    SDL_Quit();
    
    return 0;
}







