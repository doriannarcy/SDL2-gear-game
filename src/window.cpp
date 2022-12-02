#include "Window.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Window::Window(const char* p_title, int p_w, int p_h)
    : window(nullptr), renderer(nullptr), zoomLevel(1), cameraPosition(Vector2f(0.0f, 0.0f))
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        std::cout << "WINDOW FAILED TO INIT. ERROR : " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    std::cout << "Window Destroyed" << std::endl;
}

SDL_Texture* Window::loadTexture(const char* p_filePath) const
{
    SDL_Texture* texture (nullptr);
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == nullptr)
    {
        std::cout << "FAILED TO LOAD TEXTURE. ERROR : " << SDL_GetError() << std::endl;
    }

    return texture;
}

void Window::clear()
{
    SDL_RenderClear(renderer);
}

void Window::display()
{
    SDL_RenderPresent(renderer);
}

void Window::render(const Entity& p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getPosition().x - cameraPosition.x;
    dst.y = p_entity.getPosition().y - cameraPosition.y;
    dst.w = p_entity.getCurrentFrame().w * zoomLevel;
    dst.h = p_entity.getCurrentFrame().h * zoomLevel;

    SDL_RenderCopy(renderer, p_entity.getTexture(), &src, &dst);
}

void Window::setCameraPosition(Vector2f p_position)
{
    cameraPosition = p_position;
}