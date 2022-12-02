#include "World.hpp"

#include "Entity.hpp"
#include "Window.hpp"
#include <vector>

World::World()
    : entities({})
{

}

void World::addEntity(Entity p_entity)
{
    entities.push_back(p_entity);
}

void World::render(Window* p_window)
{
    for (Entity entity : entities)
    {
        p_window->render(entity);
    }
}
