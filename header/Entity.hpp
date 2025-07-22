#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Vector2f.hpp>

class ENTITY {
    Vector2f pos;
    Vector2f box;

    SDL_Rect rect;

    

    public:
    ENTITY(Vector2f p_pos, Vector2f p_box, SDL_Texture* texture) : pos(p_pos), box(p_box){};
};