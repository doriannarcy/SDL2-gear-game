#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Window.hpp"
#include "Entity.hpp"
#include "World.hpp"

const float timeStep (0.01f); // 100 fps => 1/100 seconds between frames

int main (int argc, char* argv[])
{
    //* SDL Initialisation
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        std::cout << "FAILED TO INIT SDL. ERROR : " << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "FAILED TO INIT SDL_image PNGs. ERROR : " << SDL_GetError() << std::endl;
    }

    //* Window Creation
    Window* window(nullptr);
    window = new Window("Untitled Gear Game", 800, 600);
    window->setCameraPosition(Vector2f(0.0f, 0.0f));

    //* World Creation
    Color backgroundColor(255, 0, 0);
    World world(backgroundColor);
    SDL_Texture* t = window->loadTexture("res/gfx/man.png");
    world.addEntity( Entity( Vector2f(10, 20), t ) );

    //* Game Loop Setup
    bool gameRunning (true);
    SDL_Event event;
    float accumulator (0.0f);
    float lastTime = SDL_GetTicks();

    while (gameRunning)
    {
        float nowTime = SDL_GetTicks();
        float deltaTime = nowTime - lastTime;

        lastTime = nowTime;
        accumulator += deltaTime;

        while (accumulator > timeStep)
        {
            //* UPDATE GAME

            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    gameRunning = false;
                }

                if (event.type == SDL_KEYDOWN)
                {
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            gameRunning = false;
                            break;
                    }
                }
            }

            accumulator -= timeStep;
        }

        //* DISPLAY TO THE SCREEN
        window->clear();
        world.render(window);
        window->display();
    }

    return 0;
}
