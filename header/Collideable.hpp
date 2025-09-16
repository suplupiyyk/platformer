#pragma once

#include <iostream>
#include <SDL2/SDL.h>

struct collideable{
    protected:
    SDL_Rect body;

    public:
    virtual SDL_Rect get_body(){
        return body;
    }
};