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
#include "GameObjectManager.h"
#include "GameBall.h"

class Game
{
public:
    static void start();
    const static int SCREEN_WIDTH = 1024;
    const static int SCREEN_HEIGHT = 768;

    static sf::RenderWindow& getWindow();

private:
    static bool isExiting();
    static void gameLoop();

    static void showMainMenu();
    static void showSplashScreen();

    enum GameState {Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing,
                    Exiting};

    static GameState gameState;
    static sf::RenderWindow mainWindow;

    static GameObjectManager gameObjectManager;

    static sf::Clock clock;
};

#endif //PROJECT_PYROS_GAME_H
