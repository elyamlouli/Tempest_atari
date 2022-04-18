#ifndef BLASTER
#define BLASTER
#include "utils.hpp"
#include "menu.hpp"

#include <SDL.h>
#include <assert.h>

#include <iostream>
#include <cmath>
//static const double pi = std::acos(-1);
#define NUM_BLASTER_POSITIONS 7
#define MAX_NUM_BULLETS 8



static int Tube_Circles[2][17][2]= {
  {
    {256, 60}, {316, 73}, {368, 108}, {403, 160}, {416, 221}, {403, 281}, {368, 334}, {315, 368}, {256, 381}, {195, 368}, {143, 334}, {108, 281}, {95, 221}, {108, 160}, {143, 108}, {195, 73}, {256, 60}
  },
  {
    {256, 255}, {264, 257}, {273, 262}, {277, 270}, {280, 279}, {277, 289}, {273, 296}, {264, 301}, {256, 303}, {247, 301}, {238, 296}, {234, 289}, {231, 279}, {234, 270}, {238, 262}, {247, 257}, {256, 255}
  }
};
static int tubeQuads[16][4][2]={
  {{256, 60}, {316, 73}, {264, 257},{256, 255}},
  {{316, 73}, {368, 108}, {273, 262},{264, 257}},
  {{368, 108}, {403, 160}, {277, 270},{273, 262}},
  {{403, 160}, {416, 221}, {280, 279},{277, 270}},
  { {416, 221}, {403, 281}, {277, 289},{280, 279}},
  {{403, 281}, {368, 334}, {273, 296},{277, 289}},//
  {{368, 334}, {315, 368}, {264, 301},{273, 296}},//
  {{315, 368}, {256, 381}, {256, 303},{264, 301}},//x1>x2 et y1<y2
  {{256, 381}, {195, 368}, {247, 301},{256, 303}},
  {{195, 368}, {143, 334}, {238, 296},{247, 301}},
  {{143, 334}, {108, 281}, {234, 289},{238, 296}},
  {{108, 281}, {95, 221}, {231, 279},{234, 289}},
  {{95, 221}, {108, 160}, {234, 270},{231, 279}},
  {{108, 160}, {143, 108}, {238, 262},{234, 270}},//x1<x2 et y1>y2
  {{143, 108}, {195, 73}, {247, 257},{238, 262}},//
  {{195, 73}, {256, 60}, {256, 255},{247, 257}} //

};


struct Blaster
{
  
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