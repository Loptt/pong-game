//
// Created by charles on 2/25/18.
//

#ifndef PONG_GAME_AIPADDLE_H
#define PONG_GAME_AIPADDLE_H


#include "VisibleGameObject.h"

class AIPaddle : public VisibleGameObject
{
public:
    AIPaddle(void);
    ~AIPaddle(void) override;

    void update(float elapsedTime) override;
    void draw(sf::RenderWindow *window) override;

    float getVelocity() const;

private:
    float velocity;
    float maxVelocity;
};


#endif //PONG_GAME_AIPADDLE_H
