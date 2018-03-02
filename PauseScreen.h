//
// Created by charles on 1/03/18.
//

#ifndef PONG_GAME_PAUSESCREEN_H
#define PONG_GAME_PAUSESCREEN_H

#include "Button.h"

class PauseScreen
{
public:
    enum PauseResult {Continue, Exit};

    struct
    {
        Button button;
        PauseResult action;
    };

    PauseResult show()
};


#endif //PONG_GAME_PAUSESCREEN_H
