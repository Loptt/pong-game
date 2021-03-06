//
// Created by charles on 2/18/18.
//

#ifndef PONG_GAME_PLAYERPADDLE_H
#define PONG_GAME_PLAYERPADDLE_H

#include "VisibleGameObject.h"

class PlayerPaddle : public VisibleGameObject
{
public:
    PlayerPaddle();
    ~PlayerPaddle();

    void update(float elapsedTime) override;
    void draw(sf::RenderWindow *window) override;

    bool getIsGoingRight();

    float getVelocity() const;

private:
    float velocity;
    float maxVelocity;
    bool isGoingRight;
};


#endif //PONG_GAME_PLAYERPADDLE_H
