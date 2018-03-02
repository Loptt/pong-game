//
// Created by charles on 1/03/18.
//

#include "PauseScreen.h"
#include <iostream>

PauseScreen::PauseScreen()
{
    font.loadFromFile("fonts/LifeIsOkay.otf");

    pauseText.setFont(font);
    pauseText.setString("Paused");
    pauseText.setFillColor(sf::Color::White);
    pauseText.setCharacterSize(50);
    pauseText.setPosition(200,200);

    sf::Vector2f buttonSize(400,200);

    PauseItem continueButton;
    continueButton.action = Continue;
    continueButton.button.configureText("Continue","fonts/LifeIsOkay.otf",sf::Color::Black,40);
    continueButton.button.setSize(buttonSize);
    continueButton.button.setPosition(200,400);
    continueButton.button.setColor(sf::Color::White);
    continueButton.button.updateButton();

    PauseItem exitButton;
    exitButton.action = Exit;
    exitButton.button.configureText("Exit","fonts/LifeIsOkay.otf",sf::Color::Black,40);
    exitButton.button.setSize(buttonSize);
    exitButton.button.setPosition(200,400);
    exitButton.button.setColor(sf::Color::White);
    exitButton.button.updateButton();

    pauseItems.push_back(continueButton);
    pauseItems.push_back(exitButton);
}

PauseScreen::PauseResult PauseScreen::show(sf::RenderWindow &window)
{
    window.draw(pauseText);

    std::list<PauseItem>::iterator it;

    for (it = pauseItems.begin(); it != pauseItems.end() ; ++it)
    {
        std::cout << "pause draw" << std::endl;
        (*it).button.draw(&window);
    }
    window.display();

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
        while (window->pollEvent(menuEvent))
        {
            if (menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}
