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
        return 2;
    }
    // Creating a renderer
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    
    // Creating a texture
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_BGRA8888, SDL_TEXTUREACCESS_STATIC, WIDTH, HEIGHT);
    
    // If renderer or texture equals NULL, abort program
    if (renderer == NULL) {
        cout << "Could not create renderer" << endl;
        
        // Closes window
        SDL_DestroyWindow(window);
        
        // Called after destroying window to clean up any resources SDL is using
        SDL_Quit();
        return 2;
    }
    if (texture == NULL) {
        cout << "Could not create texture" << endl;
        
        // Closes window
        SDL_DestroyWindow(window);
        
        // Called after destroying window to clean up any resources SDL is using
        SDL_Quit();
        return 2;
    }
    
    // Creating an unsigned 32 bit int because not all systems may have 32 bit ints
    // SDL allow ints to be explicitly declared as 32 bits
    Uint32 * buffer = new Uint32[WIDTH * HEIGHT];
    
    // Creating a loop so that the window can be constantly updated
    while (!quitProgram) {
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quitProgram = true;
            }
        }
        
    }
    
    // Deleting Buffer
    delete buffer;
    
    // Destroy renderer
    SDL_DestroyRenderer(renderer);
    
    // Destroy Texture
    SDL_DestroyTexture(texture);
    
    // Close window
    SDL_DestroyWindow(window);
    // Cleans up any resource(s) SDL is using
    SDL_Quit();
    
    return 0;
}







