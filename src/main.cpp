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

    float desired = 1.0f/60.0f;

    float pr_time = SDL_GetTicks()/1000.0f;
    float accumulator = 0;

    while (running){
        float ne_time = SDL_GetTicks()/1000.0f;
        float delta_time = ne_time - pr_time;
        accumulator += delta_time;
        
        while (accumulator >= desired){
            accumulator -= desired;
        }
            
        while(SDL_PollEvent(&E)){

            switch(E.key.keysym.sym){
                case SDLK_ESCAPE:
                    running = false;
                    break;
                case SDLK_w:
                    pl.move(Directions::UP, desired);
                    break;
                case SDLK_s:
                    pl.move(Directions::DOWN, desired);
                    break;
                case SDLK_d:
                    pl.move(Directions::RIGHT, desired);
                    break;
                case SDLK_a:
                    pl.move(Directions::LEFT, desired);
                    
            }
        }

        win.render(pl);
    }

    SDL_Quit();
    return 0;
}