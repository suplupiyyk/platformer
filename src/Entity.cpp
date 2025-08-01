#include <Entity.hpp>

Entity::Entity(std::string name, float hp, Vector2f pos, Vector2f box, SDL_Texture* texture){
    this->name = name;
    this->pos = pos;
    this->hp = hp;

    this->velocity = Vector2f(10, 10);

    this->body.x = 0;
    this->body.y = 0;
    this->body.w = box.x; 
    this->body.h = box.y;

    this->texture = texture;

    this->gravity = 9.8/20;
}

SDL_Rect Entity::get_body(){
    return body;
}

Vector2f Entity::get_pos(){
    return pos;
}

Vector2f Entity::get_velocity(){
    return velocity;
}

SDL_Texture* Entity::get_texture(){
    return texture;
}

void Entity::collision(){

    if (this->pos.y + this->body.h>= 400){
        this->velocity.y = 0;
        this->pos.y = 400-this->body.h;
    }

    if (this->pos.x + this->body.w >= 600){
        this->pos.x = 600-this->body.w;
    }

    if (this->pos.x <= 0){
        this->pos.x = 0;
    }
}

void Entity::accel_update(){
    velocity.y += gravity;
}

void Entity::update(){
    this->pos.y += velocity.y;
}