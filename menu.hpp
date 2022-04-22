#ifndef MENU
#define MENU

#include <SDL.h>
#include <assert.h>

#include <iostream>
#include <string>
#include <cmath>
const double pi = std::acos(-1);
struct Menu 
{
    SDL_Renderer * renderer;
    Menu(SDL_Renderer * renderer);
    ~Menu();
    void hershey(SDL_Renderer * renderer, std::string str, int start_x, int start_y, int coeff);
    void start(SDL_Renderer * renderer,int x,int y,int w,int h);
    void quit(SDL_Renderer * renderer,int x,int y,int w,int h);
    void circle(SDL_Renderer * renderer, int rayon,int centreX,int centreY);
    void couloirs(SDL_Renderer * renderer,int x,int y,int rayon1,int rayon2,int nb_couloirs);
    void draw_tubes(SDL_Renderer * renderer, int start_x, int start_y, int coeff);
    

    //void print_cercle(int x, int y, int coeff);
};

#endif