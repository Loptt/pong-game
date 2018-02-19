//
// Created by charles on 2/17/18.
//

#include "SplashScreen.h"

void SplashScreen::show(sf::RenderWindow &window)
{
    sf::Texture background;

    if (!background.loadFromFile("Splashscreen.png"))
    {
        return;
    }

    sf::Sprite sprite(background);

    window.draw(sprite);
    window.display();

    sf::Event event;

    while (true)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed
                || event.type == sf::Event::MouseButtonPressed
                || event.type == sf::Event::Closed)
            {
                return;
            }
        }

    }
}
