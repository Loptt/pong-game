//
// Created by charles on 2/18/18.
//

#ifndef PONG_GAME_GAMEOBJECTMANAGER_H
#define PONG_GAME_GAMEOBJECTMANAGER_H

#include <string>
#include "VisibleGameObject.h"

class GameObjectManager
{
public:
    GameObjectManager();
    ~GameObjectManager();

    void add(std::string name, VisibleGameObject *gameObject);
    void remove(std::string name);
    int getObjectCount() const;
    VisibleGameObject *get(std::string name) const;

    void drawAll(sf::RenderWindow &window);

private:
    std::map<std::string, VisibleGameObject*> gameObjects;

    struct gameObjectDeallocator
    {
        void operator()(const std::pair<std::string, VisibleGameObject*> &p) const
        {
            delete p.second;
        }
    };
};


#endif //PONG_GAME_GAMEOBJECTMANAGER_H
