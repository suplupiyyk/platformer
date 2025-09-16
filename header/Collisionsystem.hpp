#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include <Collideable.hpp>


class collision_system{
    std::vector<collideable> array;

    public:
    collision_system(std::vector<collideable>);
    
};