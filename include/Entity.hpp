#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "Math.hpp"

class Entity
{
    public:
    Entity(Vector2f p_position, SDL_Texture* p_texture);

    Vector2f getPosition() const;
    SDL_Rect getCurrentFrame() const;
    SDL_Texture* getTexture() const;

    void move(Vector2f movement);

    private:

    Vector2f position;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};