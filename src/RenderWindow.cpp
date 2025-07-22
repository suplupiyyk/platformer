#include<RenderWindow.hpp>

RenderWindow::RenderWindow(const char* title, int width, int height){
    win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_BORDERLESS);

    if (win == nullptr){
        std::cerr << "window failed: " << SDL_GetError() << std::endl;
    }

    ren = SDL_CreateRenderer(win, -1, 0);
    if (ren == nullptr){
        std::cerr << "renderer failed: " << SDL_GetError()  << std::endl;
    }
}


void RenderWindow::render(){
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
}


RenderWindow::~RenderWindow(){
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
}