//
// Created by charles on 2/18/18.
//

#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{

}

GameObjectManager::~GameObjectManager()
{
    std::for_each(gameObjects.begin(), gameObjects.end(), gameObjectDeallocator());
}

void GameObjectManager::add(std::string name, VisibleGameObject *gameObject)
{
    gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

void GameObjectManager::remove(std::string name)
{

}

int GameObjectManager::getObjectCount() const
{
    return 0;
}

VisibleGameObject *GameObjectManager::get(std::string name) const
{
    return nullptr;
}

void GameObjectManager::drawAll(sf::RenderWindow &window)
{

}
