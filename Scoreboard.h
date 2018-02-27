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
    Scoreboard();
    ~Scoreboard() override;

    void update(float elapsedTime) override;
    void draw(sf::RenderWindow &window);

private:
    int score1;
    int score2;

    sf::Text title;

    sf::Text textPlayer1;
    sf::Text textPlayer2;

    sf::Text textScore1;
    sf::Text textScore2;
};


#endif //PONG_GAME_SCOREBOARD_H
