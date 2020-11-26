#include "EntityManager.h"

void EntityManager::ClearData() {
    for (auto& entity: entities) {
        entity->Destroy();
    }
}

bool EntityManager::HasNoEntities() {
    return entities.size() == 0;
}

void EntityManager::Update(float deltaTime) {
    for (auto& entity: entities) {
        entity->Update(deltaTime);
    }
}

void EntityManager::Render() {
    for (auto& entity: entities) {
        entity->Render();
    }
};
    
std::shared_ptr<Entity> EntityManager::AddEntity(std::string entityName) {
    entities.emplace_back(std::make_shared<Entity>(*this, entityName));
    return entities.back();
}

std::vector<std::shared_ptr<Entity>> EntityManager::GetEntities() const {
    return entities;
}

unsigned int EntityManager::GetEntityCount() {
    return entities.size();
}
