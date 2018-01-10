//
//  Screen.hpp
//  Particles
//
//  Created by Al Masgai on 1/7/18.
//  Copyright © 2018 Al Masgai. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Screen {
public:
    const static int WIDTH = 800;
    const static int HEIGHT = 600;
    
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 * m_buffer;
    // Creating an SDL Event object for the loop
    SDL_Event event;
    
    
public:
    Screen();
    bool init();
    void close();
    bool processEvents();
};

#endif /* Screen_hpp */
