#include <Entitiy.hpp>

Entity::Entity(int p_x, int p_y) : x(p_x), y(p_y){
    rect.x = 0;
    rect.y = 0;
    rect.w = w;
    rect.h = h;
}
