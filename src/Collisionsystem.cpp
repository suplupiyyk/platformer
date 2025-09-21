#include <Collisionsystem.hpp>

collision_system::collision_system(std::vector<collideable*> array){
    this->array = array;
}

collision_system::collision_system(){
    //do nothing
}

bool collision_system::check(collideable& obj1, collideable& obj2){
    return (
        obj1.get_pos().x < obj2.get_pos().x + obj2.get_body().w &&
        obj1.get_pos().x + obj1.get_body().w > obj2.get_pos().x &&
        obj1.get_pos().y < obj2.get_pos().y + obj2.get_body().w &&
        obj1.get_pos().y + obj1.get_body().h > obj2.get_pos().x
        );
}

void collision_system::checkup(){
    for (unsigned int i = 0; i < array.size() -1; i++){
        if(check((*array[i]), (*array[i+1]))){
            array[i]->on_collide(*array[i+1]);
        }
        else if(typeid(*array[i]) == typeid(Entity)){
            Entity* temp = dynamic_cast<Entity*> (array[i]);
            if (temp){
                temp->get_is_on_ground() = false;
            }
        }
    }
}