//
// Created by charles on 2/17/18.
//

#ifndef PONG_GAME_MAINMENU_H
#define PONG_GAME_MAINMENU_H

#include <SFML/Graphics.hpp>
#include "Button.h"
#include <list>

class MainMenu
{
public:
    enum MenuResult {Nothing, Exit, Play};

    struct MenuItem
    {
        Button button;
        MenuResult action;
    };

    MenuResult show(sf::RenderWindow &window);

private:

    MenuResult getMenuResponse(sf::RenderWindow &window);
    MenuResult handleClick(sf::Vector2i mousePos);
    std::list<MenuItem> menuItems;
};


#endif //PONG_GAME_MAINMENU_H
