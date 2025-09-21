#include<iostream>
#include<time.h>

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include<Entity.hpp>
#include<Player.hpp>
#include<Block.hpp>
#include<Collisionsystem.hpp>
#include<RenderWindow.hpp>

int WinMain(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    RenderWindow win("game", 600, 400);

    bool running = true;

    
    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    SDL_Texture* cat = win.Load_Texture("assets/img/cat.png");

    Player* pl = new Player ("player", 100, Vector2f(300, 200), Vector2f(50, 50), cat, Vector2f(100, 100));

    Block* rect = new Block(Vector2f(50, 50), Vector2f(300, 350), nullptr);
    std::vector<collideable*> array = {pl, rect};
    collision_system cs(array);

    int win_fps = win.get_win_fps();

    float desired_fps = 1.0f/win_fps;

    float pr_time = SDL_GetTicks()/1000.0f;
    float accumulator = 0;

    while (running){
        float ne_time = SDL_GetTicks()/1000.0f;
        float delta_time = ne_time - pr_time;
        accumulator += delta_time;
        pr_time = ne_time;
        
        SDL_PumpEvents();

        if (keystate[SDL_SCANCODE_ESCAPE]){
            running = false;
        }
        

        while (accumulator >= desired_fps){

            pl->check(keystate, desired_fps);
            pl->collision_border();

            pl->update();
            //pl->get_pos().print();

            win.clear();
            win.render_texture(*pl);
            win.render(*rect);
            win.update();
            
            cs.checkup();

            accumulator -= desired_fps;
        }

    }

    SDL_Quit();
    return 0;
}