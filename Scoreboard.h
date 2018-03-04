//
// Created by charles on 26/02/18.
//

#ifndef PONG_GAME_SCOREBOARD_H
#define PONG_GAME_SCOREBOARD_H

#include <SFML/Graphics.hpp>
#include "VisibleGameObject.h"

class Scoreboard : public VisibleGameObject
{
public:
    Scoreboard(sf::Font* font);
    ~Scoreboard() override;

    void setScore1(int score1);
    void setScore2(int score2);
    int getScore1();
    int getScore2();

    void incrementScore1();
    void incrementScore2();

    void update(float elapsedTime) override;
    void draw(sf::RenderWindow *window) override;

private:
    int score1;
    int score2;
    int maxScore;

    sf::Text title;

    sf::Text textPlayer1;
    sf::Text textPlayer2;

    sf::Text textScore1;
    sf::Text textScore2;
};


#endif //PONG_GAME_SCOREBOARD_H
