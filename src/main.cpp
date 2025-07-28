#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include<Entity.hpp>
#include<Player.hpp>
#include<time.h>

#include<RenderWindow.hpp>

int WinMain(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    RenderWindow win("game", 600, 400);

    bool running = true;
    SDL_Event E;

    SDL_Texture* cat = win.Load_Texture("assets/img/cat.png");
    Player pl("player", 100, Vector2f(50, 50), Vector2f(50, 50), cat);

    //float gravity = 9.80f;

    float desired = 1.0f/60.0f;

    float pr_time = SDL_GetTicks()/1000.0f;
    float accumulator = 0;

    while (running){
        float ne_time = SDL_GetTicks()/1000.0f;
        float delta_time = ne_time - pr_time;
        accumulator += delta_time;
        
        while (accumulator >= desired){
            while(SDL_PollEvent(&E)){
                if (E.key.keysym.sym == SDLK_ESCAPE){
                    running = false;
                }

                else if (E.key.keysym.sym == SDLK_UP){
                    pl.move(Directions::UP, desired);
                }

                else if (E.key.keysym.sym == SDLK_RIGHT){
                    pl.move(Directions::RIGHT, desired);
                }

                else if (E.key.keysym.sym == SDLK_LEFT){
                    pl.move(Directions::LEFT, desired);
                }

    
                win.render(pl);
            }

            accumulator -= desired;
        }
        
    }

    SDL_Quit();
    return 0;
}