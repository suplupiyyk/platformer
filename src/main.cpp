#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include<RenderWindow.hpp>

int WinMain(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    RenderWindow win("hello world", 600, 400);

    bool running = true;
    SDL_Event E;
    
    while (running){
        while(SDL_PollEvent(&E)){
            switch(E.key.keysym.sym){
                case SDLK_ESCAPE:
                    running = false;
                    break;
            }
        }

        win.render();
    }

    SDL_Quit();
    return 0;
}