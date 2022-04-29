#include <vector>
#include <iostream>
#include <SDL.h>
#include "menu.hpp"

/**
 * @brief 
 * Vecteur de vecteuur permettant de tracer les vies 
 */
const std::vector<std::vector<int>> coords = { 
      {11, 0},
      {21, 5},
      {13, 8},
      {18, 5},
      {11, 2},
      {4, 5},
      {8, 8},
      {0, 5}
    };


class Score{
private :
    int nbLives;
    int score;
    Menu * menu;
    int id;

public:
    Score();
    Score(int id);
    ~Score();
    /**
     * @brief 
     * Permet de tracer la forme d'une vie avec une translation de x et y 
     * et un coefficient coef
     * @param renderer 
     * @param coef 
     * @param x 
     * @param y 
     */
    void draw_live(SDL_Renderer* renderer,int coef,int x,int y);
    int get_nbLives();
    void set_nbLives(int i);
    int get_score();
    void set_score(int s);
    int get_id();
};