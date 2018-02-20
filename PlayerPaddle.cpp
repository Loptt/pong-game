//
// Created by charles on 2/18/18.
//

#include "PlayerPaddle.h"

PlayerPaddle::PlayerPaddle()
{

}

PlayerPaddle::~PlayerPaddle()
{

}

void PlayerPaddle::update(float elapsedTime)
{
    VisibleGameObject::update(elapsedTime);
}

void PlayerPaddle::draw(sf::RenderWindow &window)
{
    VisibleGameObject::draw(window);
}

float PlayerPaddle::getVelocity() const
{
    return 0;
}
