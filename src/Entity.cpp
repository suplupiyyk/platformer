#include <Entity.hpp>

Entity::Entity(Vector2f p_pos, Vector2f p_box, SDL_Texture* p_texture) : pos(p_pos), texture(p_texture){
    body.x = 0;
    body.y = 0;
    body.w = p_box.x;
    body.h = p_box.y;
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