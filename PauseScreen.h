//
// Created by charles on 1/03/18.
//

#ifndef PONG_GAME_PAUSESCREEN_H
#define PONG_GAME_PAUSESCREEN_H

#include "Button.h"
#include <list>

class PauseScreen
{
public:
    PauseScreen();

    enum PauseResult {Continue, Exit, Nothing};

    struct PauseItem
    {
        Button button;
        PauseResult action;
    };

    PauseResult show(sf::RenderWindow &window);

private:
    PauseResult getPauseResponse(sf::RenderWindow *window);
    PauseResult handleClick(sf::Vector2i mousePos);

    std::list<PauseItem> pauseItems;
    sf::Text pauseText;
    sf::Font font;

};


#endif //PONG_GAME_PAUSESCREEN_H
