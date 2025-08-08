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

void Entity::collision_border(){

    if (pos.x < 0){
        pos.x = 0;
        velocity.x = 0;
    }
    else if (pos.x + body.w > 600){
        pos.x = 600 - body.w;
        velocity.x = 0;
    }

    if (pos.y < 0){
        pos.y = 0;
        velocity.y = 0;
    }
    
    else if (pos.y + body.h > 400){
        pos.y = 400 - body.h;
        is_on_ground = true;
        velocity.y = 0;
    }
}

void Entity::update(){
    if (!is_on_ground){
        this->velocity.y += gravity * 0.016f;
    }
    else {
        this->velocity.y = 0;
    }

    this->pos.y += this->velocity.y;
}