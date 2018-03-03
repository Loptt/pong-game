//
// Created by charles on 1/03/18.
//

#include "PauseScreen.h"
#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>

PauseScreen::PauseScreen()
{
    font.loadFromFile("fonts/LifeIsOkay.otf");

    pauseText.setFont(font);
    pauseText.setString("Paused");
    pauseText.setFillColor(sf::Color::White);
    pauseText.setCharacterSize(100);
    pauseText.setPosition(360,200);

    sf::Vector2f buttonSize(400,100);

    PauseItem continueButton;
    continueButton.action = Continue;
    continueButton.button.configureText("Continue",sf::Color::Black,40, &font);
    continueButton.button.setSize(buttonSize);
    continueButton.button.setPosition(Game::SCREEN_WIDTH/2-buttonSize.x/2,400);
    continueButton.button.setColor(sf::Color::White);
    continueButton.button.updateButton();

    PauseItem exitButton;
    exitButton.action = Exit;
    exitButton.button.configureText("Return to Menu",sf::Color::Black,40, &font);
    exitButton.button.setSize(buttonSize);
    exitButton.button.setPosition(Game::SCREEN_WIDTH/2-buttonSize.x/2,520);
    exitButton.button.setColor(sf::Color::White);
    exitButton.button.updateButton();

    pauseItems.push_back(continueButton);
    pauseItems.push_back(exitButton);
}

PauseScreen::PauseResult PauseScreen::show(sf::RenderWindow &window)
{
    window.draw(pauseText);

    std::list<PauseItem>::iterator it;

    for (it = pauseItems.begin(); it != pauseItems.end(); ++it)
    {
        (*it).button.draw(&window);
    }

    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    return getPauseResponse(&window);

}

PauseScreen::PauseResult PauseScreen::handleClick(sf::Vector2i mousePos)
{
    std::list<PauseItem>::iterator it;

    for (it = pauseItems.begin(); it != pauseItems.end() ; ++it)
    {
        if ((*it).button.isButtonClicked(mousePos))
        {
            return (*it).action;
        }
    }

    return Nothing;
}

PauseScreen::PauseResult PauseScreen::getPauseResponse(sf::RenderWindow *window)
{
    sf::Event menuEvent;

    while (true)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            //if(ServiceLocator::getAudio()->isSongPlaying())
            //  ServiceLocator::getAudio()->stopAllSounds();

            return handleClick(sf::Mouse::getPosition(*window));

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
        {
            std::cout << "P pressed" << std::endl;
            return PauseScreen::Continue;
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
