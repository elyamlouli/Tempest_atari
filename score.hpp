#ifndef SCORE
#define SCORE

#include <SDL.h>
#include <vector>
#include <iostream>

#include "menu.hpp"

class Score
{
private:
    int nbLives;
    SDL_Renderer *renderer;
    int score;
    Menu *menu;

    std::vector<std::vector<int>> coords = {
    {11, 0},
    {21, 5},
    {13, 8},
    {18, 5},
    {11, 2},
    {4, 5},
    {8, 8},
    {0, 5}};

public:
    Score();
    void draw_live(SDL_Renderer *renderer, int coef, int x, int y);
    void draw_score(std::string str, int start_x, int start_y, int coeff);
    int get_nbLives();
    int get_score();
    void set_score(int s);
    ~Score();
};

#endif // SCORE