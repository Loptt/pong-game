//
// Created by charles on 2/18/18.
//

#ifndef PONG_GAME_VISIBLEGAMEOBJECT_H
#define PONG_GAME_VISIBLEGAMEOBJECT_H

#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class VisibleGameObject
{
public:
    VisibleGameObject();
    virtual ~VisibleGameObject();

    virtual void load(std::string filename);
    virtual void draw(sf::RenderWindow &window);

    virtual void setPosition(sf::Vector2f);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    std::string filename;
    bool isLoaded;
};


#endif //PONG_GAME_VISIBLEGAMEOBJECT_H
