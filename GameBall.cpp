//
// Created by charles on 20/02/18.
//

#include "GameBall.h"
#include "Game.h"
#include "ServiceLocator.h"
#include "AIPaddle.h"
#include "Scoreboard.h"
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

GameBall::GameBall() :
velocity(800.0f),
elapsedTimeSinceStart(0.0f),
count(0)
{
    load("images/ball.png");
    assert(getIsLoaded());

    getSprite().setOrigin(15,15);

    srand(time(NULL));

    int direction = rand() % 4;

    switch (direction)
    {
        case 0:
            angle = (float)(rand() % 10)-5;
            break;
        case 1:
            angle = (float)(rand() % 10)+85;
            break;
        case 2:
            angle = (float)(rand() % 10)+175;
            break;
        case 3:
            angle = (float)(rand() % 10)+265;
            break;
        default:
            angle = (float)(rand() % 10)-5;
            break;
    }
}

GameBall::~GameBall()
{

}

void GameBall::update(float elapsedTime)
{
    elapsedTimeSinceStart += elapsedTime;

    if (count == 0)
    {
        std::cout << elapsedTime << std::endl;
        std::cout << count << std::endl;
        count++;
    }

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
    AIPaddle *player2 = dynamic_cast<AIPaddle*>(Game::getGameObjectManager().get("Paddle2"));
    Scoreboard *scoreboard = dynamic_cast<Scoreboard*>(Game::getGameObjectManager().get("scoreboard"));

    if (player1 != NULL && player2 != NULL)
    {
        sf::Rect<float> p1BB = player1->getBoundingRect();
        sf::Rect<float> p2BB = player2->getBoundingRect();

        //Intersection with player paddle
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

            float playerVelocity = player1->getVelocity();

            if (playerVelocity < 0)
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

            ServiceLocator::getAudio()->playSound("audio/bounce.wav");
        }

        //Intersection with AI paddle
        if (p2BB.intersects(getBoundingRect()))
        {
            angle = 360.0f - (angle - 180.0f);
            if (angle > 360.0f)
                angle -= 360.0f;

            moveByY = -moveByY;

            if (getBoundingRect().top < player2->getBoundingRect().top + player2->getBoundingRect().height)
            {
                sf::Vector2f position(getPosition().x, player2->getBoundingRect().top + player2->getHeight()
                                      + getWidth()/2+1);

                setPosition(position);
            }

            float playerVelocity = player2->getVelocity();

            if (playerVelocity < 0)
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

            ServiceLocator::getAudio()->playSound("audio/bounce.wav");
        }

        //Player scores
        if (getPosition().y -getHeight()/2 <= 0)
        {
            std::cout << "Player scored with " << elapsedTimeSinceStart << " seconds" << std::endl;

            scoreboard->incrementScore1();
            setPosition(Game::SCREEN_WIDTH/2, Game::SCREEN_HEIGHT/2);

            velocity = 700.0f;
            elapsedTimeSinceStart = 0.0f;

            int direction = rand() % 4;

            switch (direction)
            {
                case 0:
                    angle = (float) (rand() % 10) - 5;
                    break;
                case 1:
                    angle = (float) (rand() % 10) + 85;
                    break;
                case 2:
                    angle = (float) (rand() % 10) + 175;
                    break;
                case 3:
                    angle = (float) (rand() % 10) + 265;
                    break;
                default:
                    angle = (float) (rand() % 10) - 5;
                    break;
            }
        }

        //AI scores
        if (getPosition().y + getHeight()/2 + moveByY >= Game::SCREEN_HEIGHT)
        {
            std::cout << "AI scored with " << elapsedTimeSinceStart << " seconds" << std::endl;

            scoreboard->incrementScore2();
            setPosition(Game::SCREEN_WIDTH/2, Game::SCREEN_HEIGHT/2);

            velocity = 700.0f;
            elapsedTimeSinceStart = 0.0f;

            int direction = rand() % 4;

            switch (direction)
            {
                case 0:
                    angle = (float) (rand() % 10) - 5;
                    break;
                case 1:
                    angle = (float) (rand() % 10) + 85;
                    break;
                case 2:
                    angle = (float) (rand() % 10) + 175;
                    break;
                case 3:
                    angle = (float) (rand() % 10) + 265;
                    break;
                default:
                    angle = (float) (rand() % 10) - 5;
                    break;
            }
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
