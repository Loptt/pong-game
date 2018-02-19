//
// Created by charles on 2/18/18.
//

#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject()
{
    isLoaded = false;
}

VisibleGameObject::~VisibleGameObject()
{

}

void VisibleGameObject::load(std::string filename)
{
    if (!texture.loadFromFile("paddle.png"))
    {
        isLoaded = false;
        filename = "";
    }
    else
    {
        this->filename = filename;
        isLoaded = true;
        sprite.setTexture(texture);
    }
}

void VisibleGameObject::draw(sf::RenderWindow &window)
{
    if (isLoaded)
    {
        window.draw(sprite);
    }
}

void VisibleGameObject::setPosition(sf::Vector2f position)
{
    if (isLoaded)
    {
        sprite.setPosition(position);
    }
}
