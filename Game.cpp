//
// Created by charles on 15/02/18.
//


#include <iostream>
#include <cassert>
#include "Game.h"
#include "SFMLSoundProvider.h"
#include "ServiceLocator.h"
#include "AIPaddle.h"
#include "Scoreboard.h"

void Game::start()
{
    if (gameState != Uninitialized)
        return;

    //Create window
    mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pong", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    font.loadFromFile("fonts/LifeIsOkay.otf");

    //Paddle moved by the player
    PlayerPaddle *player1 = new PlayerPaddle();
    player1->setPosition(SCREEN_WIDTH/2-40, 700);

    //Ball used in the game
    GameBall *ball = new GameBall();
    ball->setPosition(SCREEN_WIDTH/2, (SCREEN_HEIGHT/2)-15);

    //Paddle used by the computer
    AIPaddle *player2 = new AIPaddle();
    player2->setPosition(SCREEN_WIDTH/2-40, 40);

    Scoreboard *scoreboard = new Scoreboard(&font);

    //Add objects to the Object manager class
    gameObjectManager.add("Paddle1", player1);
    gameObjectManager.add("Paddle2", player2);
    gameObjectManager.add("Ball", ball);
    gameObjectManager.add("scoreboard", scoreboard);

    SFMLSoundProvider soundProvider;
    ServiceLocator::registerServiceLocator(&soundProvider);
    ServiceLocator::getAudio()->playSong("audio/Soundtrack.ogg",true);

    gameState = Game::ShowingSplash;

    while (!isExiting())
    {
        gameLoop();
    }

    mainWindow.close();
}

bool Game::isExiting()
{
    return gameState == Game::Exiting;
}

void Game::gameLoop()
{
    float deltaTime;

    sf::Event currentEvent;
    switch (gameState)
    {
        case Game::ShowingSplash:
            showSplashScreen();
            break;

        case Game::ShowingMenu:
            showMainMenu();
            break;

        case Game::Playing:


            deltaTime = clock.restart().asSeconds();

            gameObjectManager.updateAll(deltaTime);
            mainWindow.clear(sf::Color(0, 0, 0));
            gameObjectManager.drawAll(mainWindow);
            mainWindow.display();

            break;

        default:
            assert(true);
            break;
    }

    while (mainWindow.pollEvent(currentEvent))
    {
        if (currentEvent.type == sf::Event::Closed)
        {
            gameState = Game::Exiting;
        }
    }
}

void Game::showMainMenu()
{
    MainMenu menu;
    MainMenu::MenuResult result = menu.show(mainWindow);

    switch (result)
    {
        case MainMenu::Exit:
            gameState = Game::Exiting;
            break;
        case MainMenu::Play:
            gameState = Game::Playing;
            break;
    }
}

void Game::showSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.show(mainWindow);
    gameState = Game::ShowingMenu;
}

sf::RenderWindow &Game::getWindow()
{
    return mainWindow;
}

Game::GameState Game::gameState = Uninitialized;

GameObjectManager &Game::getGameObjectManager()
{
    return gameObjectManager;
}

sf::RenderWindow Game::mainWindow;
GameObjectManager Game::gameObjectManager;
sf::Clock Game::clock;