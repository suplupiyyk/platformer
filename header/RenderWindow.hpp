#pragma once
#include<iostream>
#include<SDL2/SDL.h>

class RenderWindow{
    SDL_Renderer* ren;
    SDL_Window* win;

    public:
    RenderWindow(const char* title, int width, int height);
    SDL_Texture* Load_Texture(const char path);
    void render();
    ~RenderWindow();
};