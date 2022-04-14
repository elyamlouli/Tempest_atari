#ifndef TUBE_H
#define TUBE_H
#include "Enemy.h"
#include "utils.hpp"
#include "blaster.hpp"
#include <SDL.h>




class Tube{
private:
    // a et d ceux du haut
    // b et c ceux du bas
    Point a, b, c, d;
    SDL_Color color;
    bool selected;
    // l'indice utilisé dans le tab tubQuads
    int idx;


public:
    Tube();
    Tube(Point a_, Point b_, Point c_, Point d_);
    Tube(int i);
    void draw(SDL_Renderer * renderer, int start_x, int start_y, int coeff);
    
};

#endif