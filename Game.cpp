//
// Created by charles on 15/02/18.
//


#include "Game.h"


void Game::start()
{
    if (gameState != Uninitialized)
        return;

    mainWindow.create(sf::VideoMode(1024, 768, 32), "Pyros", sf::Style::Titlebar | sf::Style::Close);

    player1.load("paddle.png");
    player1.setPosition(sf::Vector2f(1024/2-40, 700));

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
                player1.draw(mainWindow);
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
sf::RenderWindow Game::mainWindow;
PlayerPaddle Game::player1;