#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <Entity.hpp>
#include <Util.hpp>


class Player : public Entity {
    public:
    Player(std::string name, float hp, Vector2f pos, Vector2f box, SDL_Texture* texture, Vector2f velocity = Vector2f(50, 50));

    void move(Directions dir, float delta_time);

};