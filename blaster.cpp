#include "blaster.hpp"

Blaster::Blaster()
{
    utils=new Utils();

}
Blaster::~Blaster()
{

}

/*void Blaster::defineTubeQuads()
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
}*/

void Blaster::drawTubeQuads(SDL_Renderer * renderer,int x,int y, int coef  )
{
    int  tubeQuad[4][2]={};
    for(int i =0;i<16;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<2;k++)
            {
                tubeQuad[j][k] = tubeQuads[i][j][k];
            }

        }
        SDL_SetRenderDrawColor(renderer, 0,0,255,0);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef,(x+tubeQuad[2][0])*coef,(y+tubeQuad[2][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[2][0])*coef,(y+tubeQuad[2][1])*coef,(x+tubeQuad[3][0])*coef,(y+tubeQuad[3][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[3][0])*coef,(y+tubeQuad[3][1])*coef,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef);
    
        
    }
        

    


}
void Blaster::drawblaster(SDL_Renderer * renderer,int tubeQuad[4][2],int h,int x,int y,int coef)
{
    //std::vector<float> posRimFlexible=this->utils->WeightedMidpoint(tubeQuad[0],tubeQuad[1],0.9);


   /* std::vector<float> posRimLeft = this->utils->WeightedMidpoint(tubeQuad[0],tubeQuad[1],0.8);
    std::vector<float> posRimMidLeft = this->utils->WeightedMidpoint(tubeQuad[0],tubeQuad[1],0.6);
    std::vector<float> posRimMidRight = this->utils->WeightedMidpoint(tubeQuad[0],tubeQuad[1],0.4);
    std::vector<float> posRimRight = this->utils->WeightedMidpoint(tubeQuad[0],tubeQuad[1],0.1);
    std::vector<float> toClawBack = this->utils->orthogonalUnitVector(tubeQuad[0],tubeQuad[1],10);
    std::vector<float> posClawBackOuter = this->utils->addvector(posRimFlexible,toClawBack,2);
    std::vector<float> posClawBackInner = this->utils->addvector(posRimFlexible,toClawBack,1);
    std::vector<float> posClawPointLeft = this->utils->addvector(posRimMidLeft,toClawBack,-1);
    std::vector<float> posClawPointRight = this->utils->addvector(posRimMidRight,toClawBack,-1);*/
    SDL_SetRenderDrawColor(renderer, 255,250,42,0);
    //SDL_RenderDrawLine(renderer,tubeQuad[0][0],tubeQuad[0][1],posRimFlexible[0],posRimFlexible[1]);

    //SDL_RenderDrawLine(renderer,tubeQuad[0][0],tubeQuad[0][1],posClawBackOuter[0],posClawBackOuter[1]);
    /*SDL_RenderDrawLine(renderer,posClawBackOuter[0],posClawBackOuter[1],tubeQuad[1][0],tubeQuad[1][1]);
    SDL_RenderDrawLine(renderer,tubeQuad[1][0],tubeQuad[1][1],posClawPointLeft[0],posClawPointLeft[1]);
    SDL_RenderDrawLine(renderer,posClawPointLeft[0],posClawPointLeft[1],posRimLeft[0],posRimLeft[1]);*/
    /*SDL_RenderDrawLine(renderer,posRimLeft[0],posRimLeft[1],posClawBackInner[0],posClawBackInner[1]);
    SDL_RenderDrawLine(renderer,posClawBackInner[0],posClawBackInner[1],posRimRight[0],posRimRight[1]);
    SDL_RenderDrawLine(renderer,posRimRight[0],posRimRight[1],posClawPointRight[0],posClawPointRight[1]);
    SDL_RenderDrawLine(renderer,posClawPointRight[0],posClawPointRight[1],tubeQuad[0][0],tubeQuad[0][1]);*/
    SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+tubeQuad[0][0]+h/std::tan(pi/3))*coef,(y+tubeQuad[0][1]-h/std::tan(pi/3))*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0]+h/std::tan(pi/3))*coef,(y+tubeQuad[0][1]-h/std::tan(pi/3))*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+tubeQuad[3][0])*coef,(y+tubeQuad[3][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[3][0])*coef,(y+tubeQuad[3][1])*coef,(x+tubeQuad[2][0])*coef,(y+tubeQuad[2][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[2][0])*coef,(y+tubeQuad[2][1])*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);






}
void Blaster::move_r(SDL_Renderer * renderer,int i,int tubeQuads[16][4][2],int h,int x,int y,int coef)
{
    if(i==0)
    {
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[15][0][0])*coef,(y+tubeQuads[15][0][1])*coef,(x+tubeQuads[15][0][0]+h/std::tan(pi/3))*coef,(y+tubeQuads[15][0][1]-h/std::tan(pi/3))*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[15][0][0]+h/std::tan(pi/3))*coef,(y+tubeQuads[15][0][1]-h/std::tan(pi/3))*coef,(x+tubeQuads[15][1][0])*coef,(y+tubeQuads[15][1][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[15][0][0])*coef,(y+tubeQuads[15][0][1])*coef,(x+tubeQuads[15][3][0])*coef,(y+tubeQuads[15][3][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[15][3][0])*coef,(y+tubeQuads[15][3][1])*coef,(x+tubeQuads[15][2][0])*coef,(y+tubeQuads[15][2][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[15][2][0])*coef,(y+tubeQuads[15][2][1])*coef,(x+tubeQuads[15][1][0])*coef,(y+tubeQuads[15][1][1])*coef);

    }
    else 
    {
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i-1][0][0])*coef,(y+tubeQuads[i-1][0][1])*coef,(x+tubeQuads[i-1][0][0]+h/std::tan(pi/3))*coef,(y+tubeQuads[i-1][0][1]-h/std::tan(pi/3))*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i-1][0][0]+h/std::tan(pi/3))*coef,(y+tubeQuads[i-1][0][1]-h/std::tan(pi/3))*coef,(x+tubeQuads[i-1][1][0])*coef,(y+tubeQuads[i-1][1][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i-1][0][0])*coef,(y+tubeQuads[i-1][0][1])*coef,(x+tubeQuads[i-1][3][0])*coef,(y+tubeQuads[i-1][3][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i-1][3][0])*coef,(y+tubeQuads[i-1][3][1])*coef,(x+tubeQuads[i-1][2][0])*coef,(y+tubeQuads[i-1][2][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i-1][2][0])*coef,(y+tubeQuads[i-1][2][1])*coef,(x+tubeQuads[i-1][1][0])*coef,(y+tubeQuads[i-1][1][1])*coef);
    }
    SDL_SetRenderDrawColor(renderer, 255,250,42,0);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][0][0])*coef,(y+tubeQuads[i][0][1])*coef,(x+tubeQuads[i][0][0]+h/std::tan(pi/3))*coef,(y+tubeQuads[i][0][1]-h/std::tan(pi/3))*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][0][0]+h/std::tan(pi/3))*coef,(y+tubeQuads[i][0][1]-h/std::tan(pi/3))*coef,(x+tubeQuads[i][1][0])*coef,(y+tubeQuads[i][1][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][0][0])*coef,(y+tubeQuads[i][0][1])*coef,(x+tubeQuads[i][3][0])*coef,(y+tubeQuads[i][3][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][3][0])*coef,(y+tubeQuads[i][3][1])*coef,(x+tubeQuads[i][2][0])*coef,(y+tubeQuads[i][2][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][2][0])*coef,(y+tubeQuads[i][2][1])*coef,(x+tubeQuads[i][1][0])*coef,(y+tubeQuads[i][1][1])*coef);



}

