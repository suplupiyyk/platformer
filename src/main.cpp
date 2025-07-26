#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include<Entity.hpp>
#include<Player.hpp>

#include<RenderWindow.hpp>

int WinMain(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    RenderWindow win("game", 600, 400);

    bool running = true;
    SDL_Event E;

    SDL_Texture* cat = win.Load_Texture("assets/img/cat.png");
    Player pl("player", 100, Vector2f(50, 50), Vector2f(50, 50), cat);

    while (running){
        while(SDL_PollEvent(&E)){
            switch(E.key.keysym.sym){
                case SDLK_ESCAPE:
                    running = false;
                    break;
            }
        }

        win.render(pl);
    }

    SDL_Quit();
    return 0;
}