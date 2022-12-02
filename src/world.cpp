#include "World.hpp"

#include "Entity.hpp"
#include "Window.hpp"
#include <vector>

World::World()
    : entities({}), backgroundColor(0, 0, 0)
{

}

World::World(Color p_backgroundColor)
    : entities({}), backgroundColor(p_backgroundColor)
{

}

void World::addEntity(Entity p_entity)
{
    entities.push_back(p_entity);
}

void World::render(Window* p_window)
{
    p_window->setBackgroundColor(backgroundColor);
    for (Entity entity : entities)
    {
        p_window->render(entity);
    }
}
