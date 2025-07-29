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
    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    SDL_Texture* cat = win.Load_Texture("assets/img/cat.png");
    Player pl("player", 100, Vector2f(50, 50), Vector2f(50, 50), cat);

    //float gravity = 9.80f;
    int win_fps = win.get_win_fps();

    float desired_fps = 1.0f/win_fps;

    float pr_time = SDL_GetTicks()/1000.0f;
    float accumulator = 0;

    while (running){
        float ne_time = SDL_GetTicks()/1000.0f;
        float delta_time = ne_time - pr_time;
        accumulator += delta_time;
        
        while (accumulator >= desired_fps){
            while(SDL_PollEvent(&E)){
                if (keystate[SDL_SCANCODE_ESCAPE]){
                    running = false;
                }

                if (keystate[SDL_SCANCODE_UP]){
                    pl.move(Directions::UP, desired_fps);
                }

                if (keystate[SDL_SCANCODE_RIGHT]){
                    pl.move(Directions::RIGHT, desired_fps);
                }

                if (keystate[SDL_SCANCODE_LEFT]){
                    pl.move(Directions::LEFT, desired_fps);
                }

            }
            pl.gravity();
            pl.update();
            win.render(pl);
            accumulator -= desired_fps;
        }

        if (accumulator != 0){ //idk just experimenting
            SDL_Delay(accumulator*1000);
            accumulator -= accumulator;
        }
    }

    SDL_Quit();
    return 0;
}