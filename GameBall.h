//
// Created by charles on 20/02/18.
//

#ifndef PONG_GAME_GAMEBALL_H
#define PONG_GAME_GAMEBALL_H

#include "VisibleGameObject.h"

class GameBall : public VisibleGameObject
{
public:
    GameBall();
    virtual ~GameBall();
    void update(float) override;

private:
    float velocity;
    float angle;
    float elapsedTimeSinceStart;
    int count;

    float linearVelocityX(float);
    float linearVelocityY(float);
};


#endif //PONG_GAME_GAMEBALL_H
