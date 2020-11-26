#include <iostream>
#include "Constants.h"
#include "Game.h"
#include "Components/TransformComponent.h"
#include "../lib/glm/glm.hpp"

EntityManager manager;
std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> Game::renderer(nullptr, SDL_DestroyRenderer);

Game::Game()
: window(nullptr, SDL_DestroyWindow)//, renderer(nullptr, SDL_DestroyRenderer)
{
    this->isRunning = false;
}

Game::~Game()
{
}

bool Game::IsRunning() const
{
    return this->isRunning;
}

void Game::Initialize(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }
    window.reset(
            SDL_CreateWindow(
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_BORDERLESS));
    
    

    if (!window)
    {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }
    renderer.reset(SDL_CreateRenderer(window.get(), -1, 0));
    if (!renderer)
    {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return;
    }

    LoadLevel(0);

    isRunning = true;
    return;
}

void Game::LoadLevel(int levelNumber)
{
  std::shared_ptr<Entity> newEntity (manager.AddEntity("projectile"));
  newEntity->AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);

  
  std::shared_ptr<Entity> anotherEntity (manager.AddEntity("projectile2"));
  anotherEntity->AddComponent<TransformComponent>(800, 0, -20, 20, 32, 32, 1);
}

void Game::ProcessInput()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
    {
        isRunning = false;
        break;
    }
    case SDL_KEYDOWN:
    {
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            isRunning = false;
        }
    }
    default:
    {
        break;
    }
    }
}

void Game::Update()
{
    // Wait until 16ms has ellapsed since the last frame
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TARGET_TIME))
        ;

    // Delta time is the difference in ticks from last frame converted to secomds
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    // Clamp deltaTime to a maximum value
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    // Sets the new ticks for the current frame to be used in the next pass
    ticksLastFrame = SDL_GetTicks();

    manager.Update(deltaTime);
}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer.get(), 21, 21, 21, 255);
    SDL_RenderClear(renderer.get());

    if (manager.HasNoEntities())
    {
        return;
    }

    manager.Render();

    SDL_RenderPresent(renderer.get());
}

void Game::Destroy()
{
    SDL_DestroyRenderer(renderer.get());
    SDL_DestroyWindow(window.get());
    SDL_Quit();
}
