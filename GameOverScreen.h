//
// Created by charles on 3/2/18.
//

#ifndef PONG_GAME_GAMEOVERSCREEN_H
#define PONG_GAME_GAMEOVERSCREEN_H


#include "Button.h"
#include <list>

class GameOverScreen
{
public:
    GameOverScreen();

    enum OverResult {Nothing, Exit, Menu, PlayAgain};

    struct OverItem
    {
        Button button;
        OverResult action;
    };

    OverResult show(sf::RenderWindow &window, bool isWinner);

private:
    OverResult getResponse(sf::RenderWindow *window);
    OverResult handleClick(sf::Vector2i mousePos);

    std::list<OverItem> overItems;
    sf::Text text;
    sf::Font font;

};


#endif //PONG_GAME_GAMEOVERSCREEN_H
