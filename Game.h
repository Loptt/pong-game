//
// Created by charles on 15/02/18.
//

#ifndef PROJECT_PYROS_GAME_H
#define PROJECT_PYROS_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
public:
    static void start();

private:
    static bool isExiting();
    static void gameLoop();

    enum GameState {Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing,
                    Exiting};

    static GameState gameState;
    static sf::RenderWindow mainWindow;
};

#endif //PROJECT_PYROS_GAME_H
