//
// Created by charles on 2/25/18.
//

#include "AIPaddle.h"
#include "GameBall.h"
#include "Game.h"
#include <cassert>

AIPaddle::AIPaddle(void) :
velocity(0),
maxVelocity(600.0f)
{
    load("images/paddle.png");
    assert(getIsLoaded());

    getSprite().setOrigin(spriteDimensions.width/2,spriteDimensions.height/2);
}

AIPaddle::~AIPaddle(void)
{

}

float AIPaddle::getVelocity() const
{
    return velocity;
}

void AIPaddle::update(float elapsedTime)
{
    const GameBall* gameBall = dynamic_cast<GameBall*>(Game::getGameObjectManager().get("Ball"));

    sf::Vector2f ballPosition = gameBall->getPosition();

    if (getPosition().x -20 < ballPosition.x)
        velocity += 15.0f;
    else
    {
        if (getPosition().x + 20 > ballPosition.x)
            velocity -= 10.0f;
        else
            velocity = 0.0f;
    }

    if (velocity > maxVelocity)
        velocity = maxVelocity;

    if (velocity < -maxVelocity)
        velocity = -maxVelocity;

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

void AIPaddle::draw(sf::RenderWindow &window)
{
    VisibleGameObject::draw(window);
}
