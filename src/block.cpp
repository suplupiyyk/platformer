#include <Block.hpp>

Block::Block(Vector2f dim, Vector2f pos, SDL_Texture* text){
    body.w = dim.x;
    body.h = dim.y;

    this->pos = pos;    
    this->text = text;

}

Block::Block(Vector2f dim, Vector2f pos, SDL_Color col){
    body.w = dim.x;
    body.h = dim.y;
    body.x = 0;
    body.y = 0;

    this->pos = pos;
    this->col = col;
    this->text = NULL;

}

Vector2f Block::get_pos(){
    return pos;
}

SDL_Color Block::get_color(){
    return col;
}

SDL_Texture* Block::get_text(){
    return text;
}