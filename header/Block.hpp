#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include <Collideable.hpp>
#include <Util.hpp>

class Block : public collideable{
    Vector2f pos;

    SDL_Texture* text = nullptr;
    SDL_Color col;


    public:
    Block(Vector2f dim, Vector2f pos, SDL_Texture* text);
    Block(Vector2f dim, Vector2f pos, SDL_Color col);

    Vector2f get_pos();

    SDL_Color get_color();
    SDL_Texture* get_text();
};