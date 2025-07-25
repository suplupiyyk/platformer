#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Vector2f.hpp>

class Entity{
    Vector2f pos;
    SDL_Rect body;

    SDL_Texture* texture;

    public:
    Entity(Vector2f p_pos, Vector2f p_box, SDL_Texture* p_texture);

    SDL_Rect get_body();
    Vector2f get_pos();

    SDL_Texture* get_texture();
};