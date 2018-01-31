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
    Uint32 *m_buffer;
    // Second buffer added to store calculated value of blur effect
    Uint32 *m_buffer2;
    Uint32 *temp;
    // Creating an SDL Event object for the loop
    
    
public:
    Screen();
    bool init();
    void update();
    void close();
    bool processEvents();
    // Setting the color of a pixel based on coordinates of (x, y)
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void clear();
    void boxBlur();
};

#endif /* Screen_hpp */
