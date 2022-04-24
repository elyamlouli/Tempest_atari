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
    double velocity;
    int pos_xinit;
    int pos_yinit;
    double time;
    int quad;
    
    




public:
    Enemy(int quad);
    ~Enemy();
    void draw_flipper(SDL_Renderer *renderer);
    std::pair<double,double> getPosition();
    void move(int tubeQuad[4][2],int scale,float velocity_coef);
    double get_time();
    float get_profondeur();
    int get_quad();
    double get_velocity();

};


#endif 