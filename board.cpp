#include <iostream>
#include "board.hpp"

/**
 * @brief Construct a new Board:: 2 lignes verticales et 2 horizontales
 * 
 */
Board::Board(){
    this->hlines = sf::VertexArray (sf::Lines, 4);
    this->vlines = sf::VertexArray (sf::Lines, 4);
}

/**
 * @brief draw the board by placing vectors
 * 
 * @param w width of the board
 * @param h height of the board
 */
Board Board::drawGrid(int w, int h){    
    Board b;    
    //on trace les lignes horizontales
    b.hlines[0].position = sf::Vector2f(W, H/3);
    b.hlines[1].position = sf::Vector2f(0, H/3);

    b.hlines[2].position = sf::Vector2f(W, 2*H/3);
    b.hlines[3].position = sf::Vector2f(0, 2*H/3);

    //on trace les lignes verticales
    b.vlines[0].position = sf::Vector2f(W/3, 0);
    b.vlines[1].position = sf::Vector2f(W/3, H);

    b.vlines[2].position = sf::Vector2f(2*W/3, 0);
    b.vlines[3].position = sf::Vector2f(2*W/3, H);
    
    return b;

}

/**
 * @brief fct that displays the board on screen and dots and crosses
 * 
 */
void Board::display(){
    
    // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(W, H), "My window");
    Board b;
    Cross c;
    Dot d;
    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {   
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        while (window.pollEvent(event))
        {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
                window.close();
            //on teste s'il y'a un clic gauche, si oui on place une croix
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                c.place(window);
            }
            //on teste s'il y'a un clic droit, si oui on place un cercle
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                d.place(window);
            }
            
        }

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);

        // c'est ici qu'on dessine la grille, et ses lignes
        b = drawGrid(W,H);
        window.draw(b.hlines);
        window.draw(b.vlines);

        //on dessine les cross et dot
        window.draw(c.getCross());
        window.draw(d.getDot());        

        // affichage de tout ce qu'on a dessiné
        window.display();
    }
}


