//
// Created by charles on 2/17/18.
//

#include "MainMenu.h"
#include "ServiceLocator.h"
#include <iostream>

#include <iostream>

MainMenu::MenuResult MainMenu::show(sf::RenderWindow &window)
{
    sf::Texture texture;

    if (!texture.loadFromFile("images/Mainmenu.png"))
    {
        return Nothing;
    }

    sf::Sprite sprite(texture);

    MenuItem playButton;
    playButton.action = Play;
    playButton.button.setSize(sf::Vector2f(1024, 235));
    playButton.button.setPosition(sf::Vector2f(0,145));

    MenuItem exitButton;
    exitButton.action = Exit;
    exitButton.button.setSize(sf::Vector2f(1024, 235));
    exitButton.button.setPosition(sf::Vector2f(0,383));

    menuItems.push_back(playButton);
    menuItems.push_back(exitButton);

    window.draw(sprite);
    window.display();

    return getMenuResponse(&window);
}

MainMenu::MenuResult MainMenu::handleClick(sf::Vector2i mousePos)
{
    std::list<MenuItem>::iterator it;

    for (it = menuItems.begin(); it != menuItems.end() ; ++it)
    {
        if ((*it).button.isButtonClicked(mousePos))
        {
            return (*it).action;
        }
    }

    return Nothing;
}

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow *window)
{
    sf::Event menuEvent;

    while (true)
    {
        while (window->pollEvent(menuEvent))
        {
            if (menuEvent.type == sf::Event::MouseButtonPressed)
            {
                //if(ServiceLocator::getAudio()->isSongPlaying())
                //  ServiceLocator::getAudio()->stopAllSounds();

                return handleClick(sf::Mouse::getPosition(window));

            }

            if (menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}
