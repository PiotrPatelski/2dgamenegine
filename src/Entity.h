#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Component.h"

class EntityManager;
class Component;

class Entity
{
  private:
    EntityManager &manager;
    bool isActive;
    std::vector<std::shared_ptr<Component>> components;

  public:
    std::string name;
    Entity(EntityManager &manager);
    Entity(EntityManager &manager, std::string name);
    void Update(float deltaTime);
    void Render();
    void Destroy();
    bool IsActive() const;
    std::vector<std::shared_ptr<Component>> GetComponents()
    {
        return components;
    }

    template <typename T, typename... TArgs> std::shared_ptr<Component> AddComponent(TArgs &&...args)
    {
        components.emplace_back(std::make_shared<T>(std::forward<TArgs>(args)...));
        components.back()->owner.reset(this);
        components.back()->Initialize();
        return components.back();
    }
};
