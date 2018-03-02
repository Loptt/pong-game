//
// Created by charles on 6/02/18.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unistd.h>

class Button
{
public:

    Button(sf::Vector2f size, sf::Vector2f pos, sf::Color);
    Button();
    ~Button();

    void setSize(sf::Vector2f size);
    void setColor(sf::Color);
    void setPosition(sf::Vector2f pos);
    void setPosition(int x, int y);
    void setText(std::string message);
    void setFontFile(std::string fileName);
    void setTextColor(sf::Color color);
    void setTextSize(int size);
    void configureText(std::string message, std::string fileName, sf::Color color, int size);

    void updateButton();

    bool isButtonClicked(sf::Vector2i);
    void draw(sf::RenderWindow *window);

private:
    sf::RectangleShape body;
    sf::Font font;
    sf::Text text;
};


#endif //BUTTON_H
