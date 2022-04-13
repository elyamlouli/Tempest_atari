#ifndef BLASTER
#define BLASTER

#include <SDL.h>
#include <assert.h>

#include <iostream>

static int Tube_Circles[2][17][2]= {
  {
    {256, 60}, {316, 73}, {368, 108}, {403, 160}, {416, 221}, {403, 281}, {368, 334}, {315, 368}, {256, 381}, {195, 368}, {143, 334}, {108, 281}, {95, 221}, {108, 160}, {143, 108}, {195, 73}, {256, 60}
  },
  {
    {256, 255}, {264, 257}, {273, 262}, {277, 270}, {280, 279}, {277, 289}, {273, 296}, {264, 301}, {256, 303}, {247, 301}, {238, 296}, {234, 289}, {231, 279}, {234, 270}, {238, 262}, {247, 257}, {256, 255}
  }
};
static int tubeQuads[(sizeof(Tube_Circles[0])/4)-1][4][2]={};

class Blaster
{
    private :
        SDL_Renderer * renderer;
        int xPos;
        int targetPos;
        int changingXPos;

    public :
    Blaster();
    ~Blaster();

    void defineTubeQuads();
    void drawTubeQuads(SDL_Renderer * renderer );

    //void drawblaster(SDL_Renderer * renderer);
};

#endif