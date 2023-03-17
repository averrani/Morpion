#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class Game{
    private:
        // chaque valeur du tab indique ce qu'elle contient
        // 0 pour vide, 1 pour une cross, 2 pour un dot
        int moves[9];
    public:
        Game();
        
        bool isValid(int x, int y);
        void addMark(int x, int y, bool type); 
        void printArr();
        void displayMarks(sf::RenderWindow &window);

        int isWinning();
};

 












#endif