//
// Created by charles on 20/02/18.
//

#include "GameBall.h"
#include <cassert>

GameBall::GameBall()
{
    load("images/ball.png");
    assert(getIsLoaded());

    getSprite().setOrigin(15,15);
}

GameBall::~GameBall()
{

}
