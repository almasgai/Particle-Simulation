//
//  Screen.cpp
//  Particles
//
//  Created by Al Masgai on 1/7/18.
//  Copyright © 2018 Al Masgai. All rights reserved.
//

#include "Screen.hpp"

Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
    
}

bool Screen::init(){
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        // cout << "SDL FAILED" << endl;
        return 1;
    }
    // ### Variables do not need to be initialized here becuase they were intiailized in Screen.hpp file
    m_window = SDL_CreateWindow("Simulation", SDL_WINDOWPOS_UNDEFINED,
                                           SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    
    if (m_window == NULL) {
        SDL_Quit();
        return 2;
    }
    // Creating a renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    
    // Creating a texture
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_BGRA8888, SDL_TEXTUREACCESS_STATIC, WIDTH, HEIGHT);
    
    // If renderer or texture equals NULL, abort program
    if (m_renderer == NULL) {
        // cout << "Could not create renderer" << endl;
        
        // Closes window
        SDL_DestroyWindow(m_window);
        
        // Called after destroying window to clean up any resources SDL is using
        SDL_Quit();
        return 2;
    }
    if (m_texture == NULL) {
        // cout << "Could not create texture" << endl;
        
        // Closes window
        SDL_DestroyWindow(m_window);
        
        // Called after destroying window to clean up any resources SDL is using
        SDL_Quit();
        return 2;
    }
    
    // Creating an unsigned 32 bit int because not all systems may have 32 bit ints
    // SDL allow ints to be explicitly declared as 32 bits
    Uint32 * m_buffer = new Uint32[WIDTH * HEIGHT];
    
    // To make sure that the window stays black and doesn't display garbage (horizontal streaks of various colors),
    // I needed to 0 out the values within the buffer to make in 'clean'
    // 1. buffer    2. value writing into every memory (255 => white, 0 => black)  3. # of bytes to write to
    memset(m_buffer, 255, HEIGHT * WIDTH * sizeof(Uint32));
    
    // Setting just one pixel to a specific color
    
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        *(m_buffer + i) = 0xFFFF0000;
    }
    
    // pitch is the number of memory allocated to one row of pixels which is screen width * sizeof(Uint32)
    //Update Texture with the pixel information contained in the buffer
    SDL_UpdateTexture(m_texture, NULL, m_buffer, (WIDTH * (int)sizeof(Uint32)));
    
    
    SDL_RenderClear(m_renderer);
    // entire texture and the enture renderer for the two NULLS repctively
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    // rendering preently to the window
    SDL_RenderPresent(m_renderer);
    
    return true;
}
bool Screen::processEvents(){
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void Screen::close(){
    
    // Deleting Buffer
    delete[] m_buffer;
    
    // Destroy renderer
    SDL_DestroyRenderer(m_renderer);
    
    // Destroy Texture
    SDL_DestroyTexture(m_texture);
    
    // Close window
    SDL_DestroyWindow(m_window);
    // Cleans up any resource(s) SDL is using
    SDL_Quit();
    
}

