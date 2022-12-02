#pragma once

#include "Entity.hpp"
#include "Window.hpp"
#include "Math.hpp"
#include <vector>

class World
{
    public:
    World();
    World(Color p_backgroundColor);
    
    void addEntity(Entity p_entity);
    void render(Window* p_window);

    private:

    std::vector<Entity> entities;
    Color backgroundColor;
};
