//
// Created by charles on 26/02/18.
//

#include "Scoreboard.h"
#include "Game.h"
#include <cassert>
#include <iostream>

Scoreboard::Scoreboard(sf::Font *font)
{
    load("images/Scorebackground.png");
    assert(getIsLoaded());

    getSprite().setOrigin(getWidth()/2,getHeight()/2);
    setPosition(getWidth()/2, Game::SCREEN_HEIGHT/2);

    score1 = 0;
    score2 = 0;
    maxScore = 10;

    //Convert integer to character
    char charScore1 = score1 + 0x30;
    char charScore2 = score2 + 0x30;

    //Set all fonts
    title.setFont(*font);
    textPlayer1.setFont(*font);
    textPlayer2.setFont(*font);
    textScore1.setFont(*font);
    textScore2.setFont(*font);

    //Configure title text
    title.setCharacterSize(20);
    title.setString("Score");
    title.setFillColor(sf::Color::White);

    //Configure text player
    textPlayer1.setString("P1:");
    textPlayer2.setString("P2:");
    textPlayer1.setCharacterSize(27);
    textPlayer2.setCharacterSize(27);
    textPlayer1.setFillColor(sf::Color::White);
    textPlayer2.setFillColor(sf::Color::White);

    //Configure Number score
    textScore1.setString(charScore1);
    textScore2.setString(charScore2);
    textScore1.setCharacterSize(27);
    textScore2.setCharacterSize(27);
    textScore1.setFillColor(sf::Color::White);
    textScore2.setFillColor(sf::Color::White);

    //Set position of scoreboard
    sf::FloatRect titleBoundingRect = title.getLocalBounds();
    title.setOrigin(titleBoundingRect.width/2, titleBoundingRect.height/2);
    title.setPosition(getWidth()/2, Game::SCREEN_HEIGHT/2-50);

    //Set other positions relative to title
    textPlayer1.setPosition(title.getPosition().x-27,title.getPosition().y+25);
    textScore1.setPosition(title.getPosition().x+10,title.getPosition().y+25);

    textPlayer2.setPosition(title.getPosition().x-27,title.getPosition().y+60);
    textScore2.setPosition(title.getPosition().x+10,title.getPosition().y+60);
}

Scoreboard::~Scoreboard()
{

}

void Scoreboard::update(float elapsedTime)
{
    //Convert integer to char
    char charScore1 = score1 + 0x30;
    char charScore2 = score2 + 0x30;

    textScore1.setString(charScore1);
    textScore2.setString(charScore2);

}

void Scoreboard::draw(sf::RenderWindow *window)
{
    window->draw(getSprite());
    window->draw(title);
    window->draw(textScore2);
    window->draw(textScore1);
    window->draw(textPlayer2);
    window->draw(textPlayer1);
}

void Scoreboard::setScore1(int score1)
{
    this->score1 = score1;
}

void Scoreboard::setScore2(int score2)
{
    this->score2 = score2;
}

void Scoreboard::incrementScore1()
{
    score1++;
}

void Scoreboard::incrementScore2()
{
    score2++;
}

int Scoreboard::getScore1()
{
    return score1;
}

int Scoreboard::getScore2()
{
    return score2;
}
