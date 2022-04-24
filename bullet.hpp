#ifndef BULLET
#define BULLET

#include <SDL.h>
#include <assert.h>
#include <iostream>
#include "utils.hpp"

class Bullet{
public:
    SDL_Renderer * renderer;
    Utils * utils;
    float profondeur;
    int quad;
    std::pair<double,double> P;
    float dist;
    Bullet(int quad);
    ~Bullet();
    void draw_bullet(SDL_Renderer * renderer, int radius);
    void move(int tubeQuad[4][2],int scale,float velocity_coef);
    std::pair<double,double> getPosition ();
};

#endif