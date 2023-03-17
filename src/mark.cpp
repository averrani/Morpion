#include <iostream>
#include "mark.hpp"



/**
 * @brief dessine une cross
 * 
 * @param x coordonnées x de la cross
 * @param y coordonnées y de la cross
 * @return Cross dessinée
 */
void Cross::draw(int x, int y){
    this->cross[0].position = sf::Vector2f(x, y);
    this->cross[1].position = sf::Vector2f(x+(W/3), y+(H/3));

    this->cross[2].position = sf::Vector2f(x, y+(H/3));
    this->cross[3].position = sf::Vector2f(x+(W/3), y);

    cross[0].color = sf::Color::Red;
    cross[1].color = sf::Color::Red;
    cross[2].color = sf::Color::Red;
    cross[3].color = sf::Color::Red;
}

/**
 * @brief dessine le dot
 * 
 * @param x coordonnées x de la dot
 * @param y coordonnées y de la dot
 * @return Dot dessinée
 */
void Dot::draw(int x, int y){
    this->dot.setRadius(90);
    this->dot.setFillColor(sf::Color(0, 0, 0));
    this->dot.setOutlineThickness(5);
    this->dot.setOutlineColor(sf::Color(250, 250, 250));

    this->dot.setPosition(40+(x*W/3), 10+(y*H/3));
}
