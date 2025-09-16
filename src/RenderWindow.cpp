#include<RenderWindow.hpp>

RenderWindow::RenderWindow(const char* title, int width, int height){
    win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_BORDERLESS);

    if (win == nullptr){
        std::cerr << "window failed: " << SDL_GetError() << std::endl;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
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

void RenderWindow::render_texture(Entity& entity){
    
    SDL_Rect src = entity.get_body();
    src.x = 0;
    src.y = 0;

    SDL_Rect des = entity.get_body();
    des.x = entity.get_pos().x;
    des.y = entity.get_pos().y;

    SDL_RenderCopy(ren, entity.get_texture(), &src, &des);
}

void RenderWindow::render(Block& block){
    if (block.get_text() != nullptr){
        SDL_Rect src = block.get_body();
        src.x = 0;
        src.y = 0;

        SDL_Rect des = block.get_body();
        des.x = block.get_pos().x;
        des.y = block.get_pos().y;

        SDL_RenderCopy(ren, block.get_text(), &src, &des);

        return ;
    }

    SDL_SetRenderDrawColor(ren, 
        block.get_color().r, 
        block.get_color().g, 
        block.get_color().b, 
        block.get_color().a);
    
    SDL_Rect temp =block.get_body();
    temp.x = block.get_pos().x;
    temp.y = block.get_pos().y;
    SDL_RenderFillRect(ren, &temp);

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
}

void RenderWindow::clear(){
    SDL_RenderClear(ren);
}

void RenderWindow::update(){
    SDL_RenderPresent(ren);
}

int RenderWindow::get_win_fps(){
    int dis_index = SDL_GetWindowDisplayIndex(win);

    SDL_DisplayMode mode;

    SDL_GetDisplayMode(dis_index, 0, &mode);

    return mode.refresh_rate;
}

RenderWindow::~RenderWindow(){
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
}