//
// Created by charles on 2/18/18.
//

#include <cassert>
#include "PlayerPaddle.h"
#include "Game.h"

PlayerPaddle::PlayerPaddle() :
velocity(0),
maxVelocity(600.0f)
{
    load("images/paddle.png");
    assert(isLoaded());

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
        velocity -= 3.0f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        velocity += 3.0f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        velocity = 0.0f;
    }

    if (velocity > maxVelocity)
        velocity = maxVelocity;

    if (velocity < -maxVelocity)
        velocity = -maxVelocity;

    sf::Vector2f pos = this->getPosition();

    if ((pos.x < spriteDimensions.width/2) || (pos.x > (Game::SCREEN_WIDTH - spriteDimensions.width/2)))
    {
        velocity = -velocity;
    }

    getSprite().move(velocity * elapsedTime, 0);
}

void PlayerPaddle::draw(sf::RenderWindow &window)
{
    VisibleGameObject::draw(window);
}

float PlayerPaddle::getVelocity() const
{
    return velocity;
}
