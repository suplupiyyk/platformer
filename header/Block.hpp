#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <Util.hpp>

class Block{
    Vector2f pos;

    SDL_Rect body;
    SDL_Texture* text;
    SDL_Color col;


    public:
    Block(Vector2f dim, Vector2f pos, SDL_Texture* text);
    Block(Vector2f dim, Vector2f pos, SDL_Color col);

    Vector2f get_pos();

    SDL_Color get_color();
    SDL_Rect get_body();
    SDL_Texture* get_text();
};