#ifndef MARK_H
#define MARK_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define W 800
#define H 600

using namespace std;

class Mark{
    public:
        virtual void draw(int x, int y) = 0;
};

class Cross : public Mark{
    private:
        sf::VertexArray cross;
    public:
        // Construct a new Cross:: Cross object avec 2 lignes qui se coupent
        Cross(){this->cross = sf::VertexArray(sf::Lines, 4);}

        void setCross(sf::VertexArray s){ cross = s; }
        sf::VertexArray getCross(){ return cross;}

        void draw(int x, int y);
};

class Dot : public Mark{
    private:
        sf::CircleShape dot;
    public:
        // Construct a new Dot : radius 90
        Dot(){}
        void setDot(sf::CircleShape s){ dot = s; }
        sf::CircleShape getDot(){ return dot; }

        void draw(int x, int y);
};


#endif