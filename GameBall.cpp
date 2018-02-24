//
// Created by charles on 20/02/18.
//

#include "GameBall.h"
#include "Game.h"
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <cmath>

GameBall::GameBall() :
velocity(30.0f),
elapsedTimeSinceStart(0.0f)
{
    load("images/ball.png");
    assert(getIsLoaded());

    getSprite().setOrigin(15,15);

    srand(time(NULL));

    angle = (float)(rand() % 361);
}

GameBall::~GameBall()
{

}

void GameBall::update(float elapsedTime)
{
    elapsedTimeSinceStart += elapsedTime;

    if (elapsedTimeSinceStart < 3.0f)
        return;

    float moveAmount  = velocity * elapsedTime;

    float moveByX = linearVelocityX(angle) * moveAmount;
    float moveByY = linearVelocityY(angle) * moveAmount;

    if (getPosition().x + moveByX <= 0 + getWidth()/2
        || getPosition().x + getHeight()/2 + moveByX >= Game::SCREEN_WIDTH)
    {
        angle = 360.0f - angle;

        if (angle > 260.0f && angle < 280.0f)
            angle += 20.0f;
        if (angle > 80.0f && angle < 100.0f)
            angle += 20.0f;

        moveByX = -moveByX;
    }

    PlayerPaddle *player1 = dynamic_cast<PlayerPaddle*>(Game::getGameObjectManager().get("Paddle1"));

    if (player1 != NULL)
    {
        sf::Rect<float> p1BB = player1->getBoundingRect();

        if (p1BB.intersects(getBoundingRect()))
        {
            angle = 360.0f - (angle - 180.0f);
            if (angle > 360.0f)
                angle -= 360.0f;

            moveByY = -moveByY;

            if (getBoundingRect().top + getBoundingRect().height > player1->getBoundingRect().top)
            {
                sf::Vector2f position(getPosition().x, player1->getBoundingRect().top- getWidth()/2-1);
                setPosition(position);
            }

            if (!player1->getIsGoingRight())
            {
                angle -= 20.0f;
                if (angle < 0)
                    angle = 360.0f - angle;
            }
            else
            {
                angle += 20.0f;
                if (angle > 360.0f)
                    angle = angle -360.0f;
            }

            velocity += 5.0f;
        }

        if (getPosition().y -getHeight()/2 <= 0)
        {
            angle = 180.0f - angle;
            moveByY = -moveByY;
        }

        if (getPosition().y + getHeight()/2 + moveByY >= Game::SCREEN_HEIGHT)
        {
            getSprite().setPosition(Game::SCREEN_WIDTH/2, Game::SCREEN_HEIGHT/2);
            angle = (float)(rand() % 361);
            velocity = 220.0f;
            elapsedTimeSinceStart = 0.0f;
        }
    }

    getSprite().move(moveByX, moveByY);

}

float GameBall::linearVelocityX(float angle)
{
    angle -= 90;

    if (angle < 0)
        angle = 360 + angle;

    return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float GameBall::linearVelocityY(float angle)
{
    angle -= 90;

    if (angle < 0)
        angle = 360 + angle;

    return (float)std::sin(angle* (3.1415925/180.0f));
}
