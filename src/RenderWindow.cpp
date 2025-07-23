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

SDL_Texture* RenderWindow::Load_Texture(const char* relative_path){
    SDL_Texture* temp = NULL;

    temp = IMG_LoadTexture(ren, strcat(SDL_GetBasePath(), relative_path));
    if (temp == nullptr){
        std::cerr << "Texture failed to load:" << IMG_GetError() << std::endl;
    }

    return temp;
}

void RenderWindow::render(Entity entity){
    SDL_RenderClear(ren);
    
    // render entity code
    
    SDL_RenderPresent(ren);
}


RenderWindow::~RenderWindow(){
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
}