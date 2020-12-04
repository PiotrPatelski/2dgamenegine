#pragma once

#include "Component.h"
#include "Entity.h"
#include "EntityManager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <memory>

class Game
{
  private:
    bool isRunning;
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;

  public:
    Game();
    ~Game();
    int ticksLastFrame = 0;
    bool IsRunning() const;
    static std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
    void LoadLevel(int levelNumber);
    void Initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
    void ListEntities();
    void ListComponents();
};
