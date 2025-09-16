#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Collideable.hpp>
#include <Util.hpp>

class Entity : public collideable{
    //attributes
    protected:
    Vector2f pos;
    Vector2f velocity;
    Vector2f accel;
    float hp;

    bool is_on_ground = false;

    float gravity;
    std::string name;


    SDL_Texture* texture;

    //methods from here and on
    public:
    Entity(const std::string p_name, float p_hp, Vector2f p_pos, Vector2f p_box, SDL_Texture* p_texture);

    virtual Vector2f get_pos();
    virtual Vector2f get_velocity();

    virtual SDL_Texture* get_texture();

    virtual void collision_border();

    virtual void update();
};