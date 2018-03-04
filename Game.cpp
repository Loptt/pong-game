//
// Created by charles on 15/02/18.
//

#include "Game.h"

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

    scoreboard = new Scoreboard(&font);

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
            clock.restart();
            break;

        case Game::Playing:

            if (scoreboard->getScore1() == 10 || scoreboard->getScore2() == 10)
            {
                gameState = Game::GameOver;
                break;
            }

            deltaTime = clock.restart().asSeconds();

            gameObjectManager.updateAll(deltaTime);
            mainWindow.clear(sf::Color(0, 0, 0));
            gameObjectManager.drawAll(mainWindow);
            mainWindow.display();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
            {
                gameState = Paused;
            }

            break;


        case Game::Paused:
            showPausedScreen();

            mainWindow.clear(sf::Color(0, 0, 0));
            gameObjectManager.drawAll(mainWindow);
            mainWindow.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            clock.restart();

            break;

        case Game::GameOver:

            showOverScreen(scoreboard->getScore1() > scoreboard->getScore2());
            scoreboard->setScore1(0);
            scoreboard->setScore2(0);

            mainWindow.clear(sf::Color(0, 0, 0));
            gameObjectManager.drawAll(mainWindow);
            mainWindow.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            clock.restart();

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

    scoreboard->setScore1(0);
    scoreboard->setScore2(0);
}

void Game::showSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.show(mainWindow);
    gameState = Game::ShowingMenu;
}

void Game::showPausedScreen()
{
    PauseScreen pauseScreen;
    PauseScreen::PauseResult result = pauseScreen.show(mainWindow);

    switch (result)
    {
        case PauseScreen::Menu:
            gameState = Game::ShowingMenu;
            break;

        case PauseScreen::Continue:
            gameState = Game::Playing;
            break;

        case PauseScreen::Exit:
            gameState = Game::Exiting;
            break;
    }

}

void Game::showOverScreen(bool isWinner)
{
    GameOverScreen gameOverScreen;
    GameOverScreen::OverResult result = gameOverScreen.show(mainWindow, isWinner);

    switch (result)
    {
        case GameOverScreen::Menu:
            gameState = Game::ShowingMenu;
            break;

        case GameOverScreen::PlayAgain:
            gameState = Game::Playing;
            break;

        case GameOverScreen::Exit:
            gameState = Game::Exiting;
            break;
    }
}

GameObjectManager &Game::getGameObjectManager()
{
    return gameObjectManager;
}

sf::RenderWindow &Game::getWindow()
{
    return mainWindow;
}

Game::GameState Game::gameState = Uninitialized;

sf::RenderWindow Game::mainWindow;
GameObjectManager Game::gameObjectManager;
sf::Clock Game::clock;
Scoreboard* Game::scoreboard;