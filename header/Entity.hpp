#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Util.hpp>

class Entity{
    //attributes
    protected:
    SDL_Rect body;
    Vector2f pos;
    Vector2f velocity;
    Vector2f accel; //acceleration
    float hp;
    std::string name;


    SDL_Texture* texture;

    //methods from here and on
    public:
    Entity(const std::string p_name, float p_hp, Vector2f p_pos, Vector2f p_box, SDL_Texture* p_texture);

    virtual SDL_Rect get_body();
    virtual Vector2f get_pos();
    virtual Vector2f get_velocity();

    virtual SDL_Texture* get_texture();

    virtual void gravity();

    virtual void update();
};