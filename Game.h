//
// Created by charles on 15/02/18.
//

#ifndef PROJECT_PYROS_GAME_H
#define PROJECT_PYROS_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cassert>
#include <chrono>
#include <thread>
#include "MainMenu.h"
#include "SplashScreen.h"
#include "PlayerPaddle.h"
#include "GameObjectManager.h"
#include "GameBall.h"
#include "SFMLSoundProvider.h"
#include "ServiceLocator.h"
#include "AIPaddle.h"
#include "Scoreboard.h"
#include "PauseScreen.h"
#include "GameOverScreen.h"

class Game
{
public:
    static void start();
    const static int SCREEN_WIDTH = 1024;
    const static int SCREEN_HEIGHT = 768;

    static sf::RenderWindow& getWindow();
    static GameObjectManager& getGameObjectManager();

private:
    static bool isExiting();
    static void gameLoop();

    static void showMainMenu();
    static void showSplashScreen();
    static void showPausedScreen();
    static void showOverScreen(bool isWinner);

    enum GameState {Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing,
                    GameOver, Exiting};

    static GameState gameState;
    static sf::RenderWindow mainWindow;

    static GameObjectManager gameObjectManager;

    static sf::Clock clock;

    static Scoreboard *scoreboard;
};

#endif //PROJECT_PYROS_GAME_H
