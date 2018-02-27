//
// Created by charles on 26/02/18.
//

#include "Scoreboard.h"
#include "Game.h"
#include <cassert>

Scoreboard::Scoreboard()
{
    sf::Font font;
    font.loadFromFile("fonts/LifeIsOkay.otf");

    title.setFont(font);
    title.setCharacterSize(20);

    textPlayer1.setFont(font);
    textPlayer2.setFont(font);
    textScore1.setFont(font);
    textScore2.setFont(font);

    textPlayer1.setString("Player 1");
    textPlayer2.setString("Player 2");

    score1 = 0;
    score2 = 0;

    char charScore1 = score1 + 0x30;
    char charScore2 = score2 + 0x30;

    textScore1.setString(charScore1);
    textScore2.setString(charScore2);

    load("images/Scorebackground.png");
    assert(getIsLoaded());

    getSprite().setOrigin(getWidth()/2,getHeight()/2);

    setPosition(getWidth()/2, Game::SCREEN_HEIGHT/2);

    sf::FloatRect titleBoundingRect = title.getLocalBounds();
    title.setOrigin(titleBoundingRect.width/2, titleBoundingRect.height/2);
    title.setPosition(getWidth()/2, Game::SCREEN_HEIGHT/2+50);
}

Scoreboard::~Scoreboard()
{

}

void Scoreboard::update(float elapsedTime)
{

}

void Scoreboard::draw(sf::RenderWindow &window)
{
    window.draw(getSprite());
    //window.draw(title);
}
