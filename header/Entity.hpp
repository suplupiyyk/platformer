#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Util.hpp>

class Entity{
    //attributes
    protected:
    std::string name;
    Vector2f pos;
    SDL_Rect body;
    float hp;


    SDL_Texture* texture;

    //methods from here and on
    public:
    Entity(const std::string p_name, float p_hp, Vector2f p_pos, Vector2f p_box, SDL_Texture* p_texture);

    virtual SDL_Rect get_body();
    virtual Vector2f get_pos();

    virtual SDL_Texture* get_texture();
};