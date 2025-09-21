#pragma once
#include <vector>
#include <Collideable.hpp>
#include <Entity.hpp>
#include <typeinfo.h>



class collision_system{
    std::vector<collideable* > array;

    public:
    collision_system(std::vector<collideable*> array);
    collision_system();

    bool check(collideable& obj1, collideable& obj2);

    void checkup();
};