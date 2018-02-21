//
// Created by charles on 2/18/18.
//

#include <iostream>
#include "GameObjectManager.h"
#include "Game.h"

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
    std::map<std::string, VisibleGameObject*>::const_iterator results = gameObjects.find(name);

    if (results != gameObjects.end())
    {
        delete results->second;
        gameObjects.erase(results);
    }
}

int GameObjectManager::getObjectCount() const
{
    return static_cast<int>(gameObjects.size());
}

VisibleGameObject *GameObjectManager::get(std::string name) const
{
    std::map<std::string, VisibleGameObject*>::const_iterator results = gameObjects.find(name);
    if (results == gameObjects.end())
    {
        return NULL;
    }
    return results->second;
}

void GameObjectManager::drawAll(sf::RenderWindow &window)
{
    std::map<std::string, VisibleGameObject*>::const_iterator itr = gameObjects.begin();

    while (itr != gameObjects.end())
    {
        itr->second->draw(window);
        itr++;
    }
}

void GameObjectManager::updateAll(float timeDelta)
{
    std::map<std::string,VisibleGameObject*>::const_iterator itr = gameObjects.begin();

    while (itr != gameObjects.end())
    {
        itr->second->update(timeDelta);
        itr++;
    }
}
