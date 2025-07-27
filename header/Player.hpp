#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <Entity.hpp>
#include <Util.hpp>


class Player : public Entity {
    public:
    using Entity::Entity;

    void move(Directions dir, float delta_time);

};