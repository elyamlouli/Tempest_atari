#ifndef BULLET
#define BULLET

#include <SDL.h>
#include <assert.h>

#include <iostream>

struct Bullet{

    SDL_Renderer * renderer;
    Bullet();
    ~Bullet();

    void draw_bullet(SDL_Renderer * renderer,float x,float y,int x_,int y_,int coef, int rayon);

};

#endif