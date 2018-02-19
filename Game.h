//
// Created by charles on 15/02/18.
//

#ifndef PROJECT_PYROS_GAME_H
#define PROJECT_PYROS_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MainMenu.h"
#include "SplashScreen.h"
#include "PlayerPaddle.h"

class Game
{
public:
    static void start();

private:
    static bool isExiting();
    static void gameLoop();

    static void showMainMenu();
    static void showSplashScreen();

    enum GameState {Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing,
                    Exiting};

    static GameState gameState;
    static sf::RenderWindow mainWindow;
    static PlayerPaddle player1;
};

#endif //PROJECT_PYROS_GAME_H
