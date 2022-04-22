#ifndef ENEMY_H
#define ENEMY_H

#include "tube.hpp"
#include <SDL.h>
#include <utility>
#include "utils.hpp"


class Enemy{
private:

    SDL_Renderer * renderer;
    Tube * tube;
    Utils * utils;
    std::pair<double,double> position;
    float profondeur;
    int pos_xinit;
    int pos_yinit;
    
    




public:
    Enemy();
    ~Enemy();
    void draw_flipper(SDL_Renderer *renderer);
    //int getPosition();
    void move(int tubeQuad[4][2],int scale,float velocity_coef);
    


};


#endif 