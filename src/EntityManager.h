#pragma once

#include <vector>

#include "Component.h"
#include "Entity.h"

class EntityManager {
 private:
  std::vector<std::shared_ptr<Entity>> entities;

 public:
  void ClearData();
  void Update(float deltaTime);
  void Render();
  bool HasNoEntities();
  std::shared_ptr<Entity> AddEntity(std::string entityName);
  std::vector<std::shared_ptr<Entity>> GetEntities() const;
  unsigned int GetEntityCount();
};

