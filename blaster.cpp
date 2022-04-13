#include "blaster.hpp"

Blaster::Blaster()
{

}
Blaster::~Blaster()
{

}

void Blaster::defineTubeQuads()
{
    
    for(int i=0;i<(sizeof(Tube_Circles[0])/4)-1;i++)
    {
        tubeQuads[i][0][0]=Tube_Circles[0][i][0];
        tubeQuads[i][0][1]=Tube_Circles[0][i][1];
        tubeQuads[i][1][0]=Tube_Circles[0][i+1][0];
        tubeQuads[i][1][1]=Tube_Circles[0][i+1][1];
        tubeQuads[i][2][0]=Tube_Circles[1][i+1][0];
        tubeQuads[i][2][1]=Tube_Circles[1][i+1][1];
        tubeQuads[i][3][0]=Tube_Circles[1][i][0];
        tubeQuads[i][3][1]=Tube_Circles[1][i][1];
    }
    return ;
}

void Blaster::drawTubeQuads(SDL_Renderer * renderer )
{
    int  tubeQuad[4][2]={};
    for(int i =0;i<(sizeof(tubeQuads)/4);i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<2;k++)
            {
                tubeQuad[j][k] = tubeQuads[i][j][k];
            }

        }
        SDL_SetRenderDrawColor(renderer, 255,250,42,0);
        SDL_RenderDrawLine(renderer,tubeQuad[0][0],tubeQuad[0][1],tubeQuad[1][0],tubeQuad[1][1]);
        SDL_RenderDrawLine(renderer,tubeQuad[1][0],tubeQuad[1][1],tubeQuad[2][0],tubeQuad[2][1]);
        SDL_RenderDrawLine(renderer,tubeQuad[2][0],tubeQuad[2][1],tubeQuad[3][0],tubeQuad[3][1]);
        SDL_RenderDrawLine(renderer,tubeQuad[3][0],tubeQuad[3][1],tubeQuad[0][0],tubeQuad[0][1]);




        
        
        
        
    }
        

    


}