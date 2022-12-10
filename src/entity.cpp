#include "Entity.hpp"

#include <SDL2/SDL.h>
#include <iostream>

#include "Math.hpp"

Entity::Entity(Vector2f p_position, SDL_Texture* p_texture)
    : position(p_position), texture(p_texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;

    int textureWidth;
    int textureHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);

    currentFrame.w = textureWidth;
    currentFrame.h = textureHeight;
}

Vector2f Entity::getPosition() const
{
    return position;
}

SDL_Rect Entity::getCurrentFrame() const
{
    return currentFrame;
}

SDL_Texture* Entity::getTexture() const
{
    return texture;
}

void Entity::move(Vector2f movement)
{
    position += movement;
}