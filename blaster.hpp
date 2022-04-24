#ifndef BLASTER
#define BLASTER
#include "utils.hpp"
#include "menu.hpp"
#include <SDL.h>
#include <assert.h>
#include <iostream>
#include <cmath>
#include "tube.hpp"
//static const double pi = std::acos(-1);
#define NUM_BLASTER_POSITIONS 7
#define MAX_NUM_BULLETS 8




class Blaster
{
  public:
  
  //static float xPos;
  //static float yPos ;
  
   
    SDL_Renderer * renderer;
    
    
    int targetPos;
    int changingXPos;
    Utils *utils;

    
    Blaster();
    ~Blaster();

    //void defineTubeQuads();
    void drawTubeQuads(SDL_Renderer * renderer,int x,int y, int coef );
    void drawblaster(SDL_Renderer * renderer,int tubeQuad[4][2],int x,int y,int coef,int rect);
    void drawblaster_bleu(SDL_Renderer * renderer,int tubeQuad[4][2],int x,int y,int coef,int rect);

    //void drawblaster(SDL_Renderer * renderer,int tubeQuad[4][2],int h,int x,int y,int coef);
    void move_r(SDL_Renderer * renderer,int i,int tubeQuads[16][4][2],int x,int y,int coef,int rect);
    void move_l(SDL_Renderer * renderer,int i,int tubeQuads[16][4][2],int x,int y,int coef,int rect);
};

#endif