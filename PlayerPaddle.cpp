//
// Created by charles on 2/18/18.
//

#include <cassert>
#include "PlayerPaddle.h"
#include "Game.h"

PlayerPaddle::PlayerPaddle() :
velocity(0),
maxVelocity(600.0f),
isGoingRight(true)
{
    load("images/paddle.png");
    assert(getIsLoaded());

    spriteDimensions = getSprite().getLocalBounds();

    getSprite().setOrigin(spriteDimensions.width/2,spriteDimensions.height/2);
}

PlayerPaddle::~PlayerPaddle()
{

}

void PlayerPaddle::update(float elapsedTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        getSprite().move(-10.0f,0);
        isGoingRight = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        getSprite().move(10.0f,0);
        isGoingRight = true;
    }
}

void PlayerPaddle::draw(sf::RenderWindow &window)
{
    VisibleGameObject::draw(window);
}

float PlayerPaddle::getVelocity() const
{
    return velocity;
}

bool PlayerPaddle::getIsGoingRight()
{
    return isGoingRight;
}
