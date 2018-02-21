//
// Created by charles on 15/02/18.
//


#include "Game.h"
#include "GameBall.h"


void Game::start()
{
    if (gameState != Uninitialized)
        return;

    mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pong", sf::Style::Titlebar | sf::Style::Close);

    PlayerPaddle *player1 = new PlayerPaddle();
    player1->setPosition(sf::Vector2f(SCREEN_WIDTH/2-40, 700));
    gameObjectManager.add("Paddle1", player1);

    GameBall *ball = new GameBall();
    ball->setPosition(sf::Vector2f(SCREEN_WIDTH/2, (SCREEN_HEIGHT/2)-15));
    gameObjectManager.add("Ball", ball);

    gameState = Game::ShowingSplash;

    clock.restart();

    while (!isExiting())
    {
        gameLoop();
        clock.restart();
    }

    mainWindow.close();
}

bool Game::isExiting()
{
    return gameState == Game::Exiting;
}

void Game::gameLoop()
{
    sf::Event currentEvent;
    while (mainWindow.pollEvent(currentEvent))
    {
        switch (gameState)
        {
            case Game::ShowingSplash:
                showSplashScreen();
                break;

            case Game::ShowingMenu:
                showMainMenu();
                break;

            case Game::Playing:

                mainWindow.clear(sf::Color(0,0,0));
                gameObjectManager.updateAll();
                gameObjectManager.drawAll(mainWindow);
                mainWindow.display();

                if (currentEvent.type == sf::Event::Closed)
                {
                    gameState = Game::Exiting;
                }

                break;
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

Game::GameState Game::gameState = Uninitialized;

sf::RenderWindow &Game::getWindow()
{
    return mainWindow;
}

sf::RenderWindow Game::mainWindow;
GameObjectManager Game::gameObjectManager;