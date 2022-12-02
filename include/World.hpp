#pragma once

#include "Entity.hpp"
#include "Window.hpp"
#include <vector>

class World
{
    public:
    World();
    
    void addEntity(Entity p_entity);
    void render(Window* p_window);

    private:

    std::vector<Entity> entities;
};
