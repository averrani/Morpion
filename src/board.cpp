#include <iostream>
#include "board.hpp"

sf::Font font;

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
    

sf::Text Board::showText(string s){

    font.loadFromFile("./data/trebuc.ttf");
    
    sf::Text text;
    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString(s);

    // set the character size
    text.setCharacterSize(35); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);

    // set the text style
    text.setStyle(sf::Text::Bold);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(W/2.0f,H/2.0f));

    return text;
}

/**
 * @brief fct that displays the board on screen and dots and crosses
 * 
 */
void Board::display(){
    
    // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(W, H), "My window");
    sf::Vector2i position;
    Game g;
    Board b;

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
            //on teste s'il y'a un clic gauche, si oui on ajoute une croix au tableau
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                position = sf::Mouse::getPosition(window);
                int x = (int)position.x / (W / 3);
                int y = (int)position.y / (H / 3);
                //teste si la case est valide(s'il n'y a pas de mark)
                if(g.isValid(x, y))
                    g.addMark(x, y, 0);
            }
            //on teste s'il y'a un clic droit, si oui on ajoute un dot au tableau
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                position = sf::Mouse::getPosition(window);
                int x = (int)position.x / (W / 3);
                int y = (int)position.y / (H / 3);
                //teste si la case est valide(s'il n'y a pas de mark)
                if(g.isValid(x, y))
                    g.addMark(x, y, 1);
            }        
            
        }
        
        // // define a 120x50 rectangle
        // sf::RectangleShape rectangle(sf::Vector2f(420, 150));
        // rectangle.setPosition(190.f, 220.f);

        //g.printArr();
        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);

        // c'est ici qu'on dessine la grille, et ses lignes
        b = drawGrid(W,H);
        window.draw(b.hlines);
        window.draw(b.vlines);

        //on affiche les marks en fonction des cases du tableau
        g.displayMarks(window);    
        
        //si l'un des joueurs a gagné
        if(g.isWinning() != 0){
            window.display(); //on affiche la fenetre pour montrer ou le dernier move a été fait
            sleep(1); // on attend 1 sec 
            window.clear(sf::Color::Black); //puis on efface l'ecran
            if(g.isWinning() == 1) //pour aficher le vainqueur
                window.draw(b.showText("Les rouges ont gagne"));
            else
                window.draw(b.showText("Les blancs ont gagne"));
            window.display();
            sleep(3); //pendant 3 sec
            window.close(); // et on ferme la fenetre
        }            

        // affichage de tout ce qu'on a dessiné
        window.display();

        
    }
}


