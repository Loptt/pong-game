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
    if (!texture.loadFromFile(filename))
    {
        isLoaded = false;
        filename = "";
    }
    else
    {
        this->filename = filename;
        isLoaded = true;
        sprite.setTexture(texture);
        spriteDimensions = sprite.getLocalBounds();
    }
}

void VisibleGameObject::draw(sf::RenderWindow &window)
{
    if (isLoaded)
    {
        window.draw(sprite);
    }
}

void VisibleGameObject::update(float elapsedTime)
{

}

void VisibleGameObject::setPosition(sf::Vector2f position)
{
    if (isLoaded)
    {
        sprite.setPosition(position);
    }
}

sf::Vector2f VisibleGameObject::getPosition() const
{
    if (isLoaded)
    {
        return sprite.getPosition();
    }

    return sf::Vector2f();
}

bool VisibleGameObject::getIsLoaded() const
{
    return isLoaded;
}

sf::Sprite &VisibleGameObject::getSprite()
{
    return sprite;
}
