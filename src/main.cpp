#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include<Entity.hpp>
#include<RenderWindow.hpp>

int WinMain(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    RenderWindow win("game", 600, 400); // hard coded screen size 

    bool running = true;
    SDL_Event E;

    SDL_Texture* cat = win.Load_Texture("assets/img/cat.png");
    Entity box(Vector2f(0, 0), Vector2f(50, 50), cat);

    while (running){
        while(SDL_PollEvent(&E)){
            switch(E.key.keysym.sym){
                case SDLK_ESCAPE:
                    running = false;
                    break;
            }
        }

        win.render(box);
    }

    SDL_Quit();
    return 0;
}