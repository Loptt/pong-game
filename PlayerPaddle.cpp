//
// Created by charles on 2/18/18.
//

#include <cassert>
#include "PlayerPaddle.h"
#include "Game.h"
#include <iostream>

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        velocity -= 3.0f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        velocity += 3.0f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        velocity = 0.0f;
    }

    if (velocity > maxVelocity)
    {
        velocity = maxVelocity;
    }

    if (velocity < -maxVelocity)
    {
        velocity = -maxVelocity;
    }

    sf::Vector2f pos = getPosition();

    if (pos.x > (Game::SCREEN_WIDTH - getSprite().getLocalBounds().width/2))
    {
        velocity = -velocity;
        setPosition(pos.x-1, pos.y);
    }

    if (pos.x < getSprite().getLocalBounds().width/2)
    {
        velocity = -velocity;
        setPosition(pos.x+1, pos.y);
    }

    getSprite().move(velocity * elapsedTime, 0);

    velocity *= 0.995f;
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
