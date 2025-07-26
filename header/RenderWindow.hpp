#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Entity.hpp>
#include <Util.hpp>

class RenderWindow{
    SDL_Renderer* ren;
    SDL_Window* win;

    public:
    RenderWindow(const char* title, int width, int height);
    SDL_Texture* Load_Texture(const char* relative_path);
    void render(Entity& entity);
    ~RenderWindow();
};