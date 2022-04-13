#ifndef TUBE_H
#define TUBE_H
#include "Enemy.h"
#include <SDL.h>


struct Point{
    float x; 
    float y; 

    Point(){}
    Point(float x_, float y_): x{x_}, y{y_} {}
    Point operator-(Point p)
    {
        this->x -= p.x; 
        this->y -= p.y;
        return *this;
    }
    Point operator=(Point p)
    {
        this->x == p.x;
        this->y == p.y;
        return *this;
    }
};

class Tube{
private:
    // a et d ceux du haut
    // b et c ceux du bas
    Point a, b, c, d;
    SDL_Color color;
    bool selected;

public:
    Tube();
    Tube(Point a_, Point b_, Point c_, Point d_);
    void draw(SDL_Renderer * renderer, int start_x, int start_y, int coeff);
    
};

#endif