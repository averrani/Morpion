#ifndef BOARD_H
#define BOARD_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

#include "mark.hpp"

#define W 800
#define H 600

class Board{
    private:
        sf::VertexArray hlines; //horizontal lines
        sf::VertexArray vlines; //vertical lines 
    public:
        Board(); // constructor 
        Board drawGrid(int w, int h); 
        void display();
};


#endif