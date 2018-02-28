//
// Created by charles on 6/02/18.
//

#include "Button.h"
#include <iostream>


Button::Button()
{

}

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
    body.setPosition(position);
    body.setSize(size);
    body.setFillColor(color);

    font.loadFromFile("Fonts/arial.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
}

Button::~Button()
{

}

void Button::setSize(sf::Vector2f size)
{
    body.setSize(size);
}

void Button::setPosition(sf::Vector2f pos)
{
    body.setPosition(pos);
}

void Button::setText(std::string message)
{
    text.setString(message);
}

void Button::setColor(sf::Color color)
{
    body.setFillColor(color);
}

void Button::draw(sf::RenderWindow *window)
{
    window->draw(body);
    window->draw(text);
}

bool Button::isButtonClicked(sf::Vector2i mousePos)
{
    if(mousePos.x > body.getPosition().x && mousePos.x < body.getPosition().x + body.getSize().x)
    {
        if (mousePos.y > body.getPosition().y && mousePos.y < body.getPosition().y + body.getSize().y)
        {
            return true;
        }
    }

    return false;
}

void Button::updateButton()
{
    sf::Vector2f position = body.getPosition();
    sf::Vector2f size = body.getSize();

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(position.x+(size.x/2.0f),position.y+(size.y/2.0f)));

}
