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
    Player pl("player", 100, Vector2f(300, 200), Vector2f(50, 50), cat, Vector2f(0, 0));

    //float gravity = 9.80f;
    int win_fps = win.get_win_fps();

    float desired_fps = 1.0f/win_fps;

    float pr_time = SDL_GetTicks()/1000.0f;
    float accumulator = 0;

    while (running){
        float ne_time = SDL_GetTicks()/1000.0f;
        float delta_time = ne_time - pr_time;
        accumulator += delta_time;
        pr_time = ne_time;
        
        while(SDL_PollEvent(&E)){
            if (keystate[SDL_SCANCODE_ESCAPE]){
                running = false;
            }

            pl.check(keystate, desired_fps);

        }

        while (accumulator >= desired_fps){

            pl.collision();
            pl.accel_update();
            pl.update();
            pl.get_pos().print();

            win.render(pl);

            
            accumulator -= desired_fps;
        }

    }

    SDL_Quit();
    return 0;
}