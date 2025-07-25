#include <Entity.hpp>

Entity::Entity(std::string p_name, float p_hp, Vector2f p_pos, Vector2f p_box, SDL_Texture* p_texture){
    name = p_name;
    pos = p_pos;
    hp = p_hp;

    body.x = 0;
    body.y = 0;
    body.w = p_box.x; 
    body.h = p_box.y;

    texture = p_texture;
}

SDL_Rect Entity::get_body(){
    return body;
}

Vector2f Entity::get_pos(){
    return pos;
}

SDL_Texture* Entity::get_texture(){
    return texture;
}