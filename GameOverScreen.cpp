//
// Created by charles on 3/2/18.
//

#include "GameOverScreen.h"
#include "Game.h"

GameOverScreen::GameOverScreen()
{
    font.loadFromFile("fonts/LifeIsOkay.otf");

    text.setFont(font);
    text.setString("You Won");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(100);
    text.setPosition(360,200);

    sf::Vector2f buttonSize(400,100);

    OverItem againButton;
    againButton.action = PlayAgain;
    againButton.button.configureText("Play Again",sf::Color::Black,40, &font);
    againButton.button.setSize(buttonSize);
    againButton.button.setPosition(Game::SCREEN_WIDTH/2-buttonSize.x/2,400);
    againButton.button.setColor(sf::Color::White);
    againButton.button.updateButton();

    OverItem menuButton;
    menuButton.action = Menu;
    menuButton.button.configureText("Return to Menu",sf::Color::Black,40, &font);
    menuButton.button.setSize(buttonSize);
    menuButton.button.setPosition(Game::SCREEN_WIDTH/2-buttonSize.x/2,520);
    menuButton.button.setColor(sf::Color::White);
    menuButton.button.updateButton();

    overItems.push_back(againButton);
    overItems.push_back(menuButton);
}

GameOverScreen::OverResult GameOverScreen::show(sf::RenderWindow &window, bool isWinner)
{
    if (isWinner)
    {
        text.setString("You Won!");
        text.setPosition(340,200);
    }
    else
    {
        text.setString("You Lost!");
        text.setPosition(320,200);
    }

    window.draw(text);

    std::list<OverItem>::iterator it;

    for (it = overItems.begin(); it != overItems.end(); ++it)
    {
        (*it).button.draw(&window);
    }

    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    return getResponse(&window);
}

GameOverScreen::OverResult GameOverScreen::handleClick(sf::Vector2i mousePos)
{
    std::list<OverItem>::iterator it;

    for (it = overItems.begin(); it != overItems.end() ; ++it)
    {
        if ((*it).button.isButtonClicked(mousePos))
        {
            return (*it).action;
        }
    }

    return Nothing;
}

GameOverScreen::OverResult GameOverScreen::getResponse(sf::RenderWindow *window){
    sf::Event menuEvent;

    while (true)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            return handleClick(sf::Mouse::getPosition(*window));
        }

        while (window->pollEvent(menuEvent))
        {
            if (menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}
