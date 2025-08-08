
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <Entity.hpp>
#include <Player.hpp>
#include <Util.hpp>

Player::Player(std::string name, float hp, Vector2f pos, Vector2f box, SDL_Texture* texture, Vector2f velocity)
    : Entity(name, hp, pos, box, texture)
{
    this->velocity = velocity;
}
void Player::check(const Uint8* keystate, float desired_fps){

    if (keystate[SDL_SCANCODE_UP] && is_on_ground){
        this->is_on_ground = false;
        this->velocity.y -= 100* desired_fps;
    }

    if (keystate[SDL_SCANCODE_RIGHT]){
        this->move(Directions::RIGHT, desired_fps);
    }

    if (keystate[SDL_SCANCODE_LEFT]){
        this->move(Directions::LEFT, desired_fps);
    }
}

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