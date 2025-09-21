#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <typeinfo.h>

#include <Util.hpp>


struct collideable{
    protected:
    SDL_Rect body;
    Vector2f pos;

    public:

    virtual void on_collide(collideable& touched){
        //do nothing
    }

    virtual SDL_Rect get_body(){
        return body;
    }

    virtual Vector2f get_pos(){
        return pos;
    }
};