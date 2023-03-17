#include <iostream>
#include "game.hpp"
#include "mark.hpp"

/**
 * @brief Construct a new Game:: initialise les cases du tableau a 0
 * 
 */
Game::Game(){
    for(int i=0; i<9; i++){
        moves[i] = 0;
    }
}

/**
 * @brief teste if position given is valid for placing a cross/dot 
 * 
 * @param x position x de la case a tester
 * @param y position y de la case a tester
 * @return true si la case contient 0
 * @return false sinon
 */
bool Game::isValid(int x, int y){
    if(moves[x+y*3] == 0)
        return 1;
    else return 0;
}

/**
 * @brief modifie la case du tableau correspondante apres l'ajout d'une mark
 * 
 * @param x coordonnée x de la case ajoutée
 * @param y coordonnée y de la case ajoutée
 * @param type 0 pour une cross, 1 pour une dot
 */
void Game::addMark(int x, int y, bool type){
    moves[x+3*y] = type + 1;
}

/**
 * @brief Tool, affiche le tableau moves
 * 
 */
void Game::printArr(){
    for(int i=0; i<9; i++){
        cout << moves[i] << "   " ;
    }
    cout << endl;
}

/**
 * @brief dessine et affiche les cases en focntion du tableau moves
 * 
 */
void Game::displayMarks(sf::RenderWindow &window){
    for(int i=0; i<9; i++){
        if(moves[i] == 1){
            Cross c;
            c.draw((i%3) * W / 3, (i/3) * H / 3);
            window.draw(c.getCross());
        }
        if(moves[i] == 2){
            Dot d;
            d.draw(i%3, i/3);
            window.draw(d.getDot());
        }
    }
}

/**
 * @brief test de verification de fin de partie
 * 
 * @return int 1 pour les cross, 2 pour les dot et 0 pour continuer la partie
 */
int Game::isWinning(){
    for(int i=0; i<9; i++){
        int x = i/3;
        // verifie si les colonnes sont egales et si elles contiennent une mark
        if(moves[x] == moves[x+3] && moves[x+3] == moves[x+6] && moves[x] != 0){
            if(moves[x] == 1)
                return 1;
            else return 2;
        }
        // verifie si les lignes sont egales, si elles sont sur la même ligne et si elles contiennent une mark
        if(moves[i] == moves[i+1] && moves[i+1] == moves[i+2] && (i%3) == 0 && moves[i] != 0){
            if(moves[i] == 1)
                return 1;
            else return 2;
        }
        // verifie si les diagonales sont egales et si elles contiennent une mark
        if(moves[0] == moves[4] && moves[4] == moves[8] && moves[0] != 0){
            if(moves[0] == 1)
                return 1;
            else return 2;
        }
        // verifie si les diagonales sont egales et si elles contiennent une mark
        if(moves[2] == moves[4] && moves[4] == moves[6] && moves[2] != 0){
            if(moves[2] == 1)
                return 1;
            else return 2;
        }
    }
    return 0;
}