#include <iostream>
#include "mark.hpp"

#define W 800
#define H 600

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
}

/**
 * @brief on place une croix en fonction de l'endroit ou on a cliqué
 * 
 * @param window coordonnées de l'endroit ou on a cliqué
 * @return Cross on retourne une croix avec des coordonnées modifies
 */
void Cross::place(sf::RenderWindow& window){

    sf::Vector2i position = sf::Mouse::getPosition(window);
    int x = (int)position.x / (W / 3);
    int y = (int)position.y / (H / 3);
    // cout << "x : " << x << "     y : " << y <<endl << flush;
    this->draw(x * W / 3, y * H / 3);
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

/**
 * @brief on place un cercle en fonction de l'endroit ou on a cliqué
 * 
 * @param window coordonnées de l'endroit ou on a cliqué
 * @return Dot on retourne un dot avec des coordonnées modifies
 */
void Dot::place(sf::RenderWindow& window){
    sf::Vector2i position = sf::Mouse::getPosition(window);
    int x = (int)position.x / (W / 3);
    int y = (int)position.y / (H / 3);
    // cout << "x : " << x << "     y : " << y <<endl << flush;
    this->draw(x, y);
}