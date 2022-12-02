#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"
#include "Math.hpp"

class Window
{
    public:

    Window(const char* p_title, int p_w, int p_h);
    ~Window();

    SDL_Texture* loadTexture(const char* p_filePath) const;
    void clear();
    void display();
    void render(const Entity& p_entity);
    void setCameraPosition(Vector2f p_position);

    private:

    SDL_Window* window;
    SDL_Renderer* renderer;
    int zoomLevel;
    Vector2f cameraPosition;
};
