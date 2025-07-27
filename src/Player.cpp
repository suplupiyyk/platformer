
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <Entity.hpp>
#include <Player.hpp>
#include <Util.hpp>

void Player::move(Directions dir, float delta_time){
    switch (dir){
        case Directions::LEFT:
            pos.x -= velocity.x * delta_time;
            break;
        case Directions::RIGHT:
            pos.x += velocity.x * delta_time;
            break;
        case Directions::UP:
            pos.y -= velocity.y * delta_time;
            break;
        case Directions::DOWN:
            pos.y += velocity.y * delta_time;

    }
}