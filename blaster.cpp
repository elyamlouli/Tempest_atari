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
void Blaster::drawblaster(SDL_Renderer * renderer,int tubeQuad[4][2],int x,int y,int coef,int rect)
{
    /*std::vector<float> vec = utils->mid_two_points(tubeQuad[0][0],tubeQuad[0][1],tubeQuad[1][0],tubeQuad[1][1]);
    this->xPos = vec[0];
    this->yPos = vec[1];*/
    //std::cout<<"xPos : "<<xPos<<"yPos : "<<yPos<<std::endl;
    if(tubeQuad[0][1] < tubeQuad[1][1] && tubeQuad[0][0] < tubeQuad[1][0])
    {
        int x1 = tubeQuad[0][0]+rect;
        int y1=tubeQuad[0][1]-rect;
        int x2= tubeQuad[1][0]+rect;
        int y2= tubeQuad[1][1]-rect;
        SDL_SetRenderDrawColor(renderer, 255,250,42,0);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+x1)*coef,(y+y1)*coef);
        SDL_RenderDrawLine(renderer,(x+x1)*coef,(y+y1)*coef,(x+x2)*coef,(y+y2)*coef);
        SDL_RenderDrawLine(renderer,(x+x2)*coef,(y+y2)*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);


    }
    else if(tubeQuad[0][0] > tubeQuad[1][0] && tubeQuad[0][1] > tubeQuad[1][1])
    {
       
        int x1 = tubeQuad[0][0]-rect;
        int y1=tubeQuad[0][1]+rect;
        int x2= tubeQuad[1][0]-rect;
        int y2= tubeQuad[1][1]+rect;
        SDL_SetRenderDrawColor(renderer, 255,250,42,0);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+x1)*coef,(y+y1)*coef);
        SDL_RenderDrawLine(renderer,(x+x1)*coef,(y+y1)*coef,(x+x2)*coef,(y+y2)*coef);
        SDL_RenderDrawLine(renderer,(x+x2)*coef,(y+y2)*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);

    }
    


    else if(tubeQuad[0][0] > tubeQuad[1][0])
    {
        
        int x1 = tubeQuad[0][0]+rect;
        int y1=tubeQuad[0][1]+rect;
        int x2= tubeQuad[1][0]+rect;
        int y2= tubeQuad[1][1]+rect;
        SDL_SetRenderDrawColor(renderer, 255,250,42,0);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+x1)*coef,(y+y1)*coef);
        SDL_RenderDrawLine(renderer,(x+x1)*coef,(y+y1)*coef,(x+x2)*coef,(y+y2)*coef);
        SDL_RenderDrawLine(renderer,(x+x2)*coef,(y+y2)*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);
        


    }
    else{
        

        int x1 = tubeQuad[0][0]-rect;
        int y1=tubeQuad[0][1]-rect;
        int x2= tubeQuad[1][0]-rect;
        int y2= tubeQuad[1][1]-rect;
        SDL_SetRenderDrawColor(renderer, 255,250,42,0);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+x1)*coef,(y+y1)*coef);
        SDL_RenderDrawLine(renderer,(x+x1)*coef,(y+y1)*coef,(x+x2)*coef,(y+y2)*coef);
        SDL_RenderDrawLine(renderer,(x+x2)*coef,(y+y2)*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);

    }
    SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+tubeQuad[3][0])*coef,(y+tubeQuad[3][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[3][0])*coef,(y+tubeQuad[3][1])*coef,(x+tubeQuad[2][0])*coef,(y+tubeQuad[2][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[2][0])*coef,(y+tubeQuad[2][1])*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);


}
void Blaster::drawblaster_bleu(SDL_Renderer * renderer,int tubeQuad[4][2],int x,int y,int coef,int rect)
{
    if(tubeQuad[0][1] < tubeQuad[1][1] && tubeQuad[0][0] < tubeQuad[1][0])
    {
        int x1 = tubeQuad[0][0]+rect;
        int y1=tubeQuad[0][1]-rect;
        int x2= tubeQuad[1][0]+rect;
        int y2= tubeQuad[1][1]-rect;
         SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+x1)*coef,(y+y1)*coef);
        SDL_RenderDrawLine(renderer,(x+x1)*coef,(y+y1)*coef,(x+x2)*coef,(y+y2)*coef);
        SDL_RenderDrawLine(renderer,(x+x2)*coef,(y+y2)*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);


    }
    else if(tubeQuad[0][0] > tubeQuad[1][0] && tubeQuad[0][1] > tubeQuad[1][1])
    {
        
        int x1 = tubeQuad[0][0]-rect;
        int y1=tubeQuad[0][1]+rect;
        int x2= tubeQuad[1][0]-rect;
        int y2= tubeQuad[1][1]+rect;
         SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+x1)*coef,(y+y1)*coef);
        SDL_RenderDrawLine(renderer,(x+x1)*coef,(y+y1)*coef,(x+x2)*coef,(y+y2)*coef);
        SDL_RenderDrawLine(renderer,(x+x2)*coef,(y+y2)*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);

    }
    


    else if(tubeQuad[0][0] > tubeQuad[1][0])
    {
       
        int x1 = tubeQuad[0][0]+rect;
        int y1=tubeQuad[0][1]+rect;
        int x2= tubeQuad[1][0]+rect;
        int y2= tubeQuad[1][1]+rect;
         SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+x1)*coef,(y+y1)*coef);
        SDL_RenderDrawLine(renderer,(x+x1)*coef,(y+y1)*coef,(x+x2)*coef,(y+y2)*coef);
        SDL_RenderDrawLine(renderer,(x+x2)*coef,(y+y2)*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);
        


    }
    else{
        

        int x1 = tubeQuad[0][0]-rect;
        int y1=tubeQuad[0][1]-rect;
        int x2= tubeQuad[1][0]-rect;
        int y2= tubeQuad[1][1]-rect;
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+x1)*coef,(y+y1)*coef);
        SDL_RenderDrawLine(renderer,(x+x1)*coef,(y+y1)*coef,(x+x2)*coef,(y+y2)*coef);
        SDL_RenderDrawLine(renderer,(x+x2)*coef,(y+y2)*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);

    }
    SDL_SetRenderDrawColor(renderer, 0,0,255,0);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+tubeQuad[3][0])*coef,(y+tubeQuad[3][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[3][0])*coef,(y+tubeQuad[3][1])*coef,(x+tubeQuad[2][0])*coef,(y+tubeQuad[2][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[2][0])*coef,(y+tubeQuad[2][1])*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);

}

/*
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
    //SDL_SetRenderDrawColor(renderer, 255,250,42,0);
    //SDL_RenderDrawLine(renderer,tubeQuad[0][0],tubeQuad[0][1],posRimFlexible[0],posRimFlexible[1]);

    //SDL_RenderDrawLine(renderer,tubeQuad[0][0],tubeQuad[0][1],posClawBackOuter[0],posClawBackOuter[1]);
    /*SDL_RenderDrawLine(renderer,posClawBackOuter[0],posClawBackOuter[1],tubeQuad[1][0],tubeQuad[1][1]);
    SDL_RenderDrawLine(renderer,tubeQuad[1][0],tubeQuad[1][1],posClawPointLeft[0],posClawPointLeft[1]);
    SDL_RenderDrawLine(renderer,posClawPointLeft[0],posClawPointLeft[1],posRimLeft[0],posRimLeft[1]);*/
    /*SDL_RenderDrawLine(renderer,posRimLeft[0],posRimLeft[1],posClawBackInner[0],posClawBackInner[1]);
    SDL_RenderDrawLine(renderer,posClawBackInner[0],posClawBackInner[1],posRimRight[0],posRimRight[1]);
    SDL_RenderDrawLine(renderer,posRimRight[0],posRimRight[1],posClawPointRight[0],posClawPointRight[1]);
    
    SDL_RenderDrawLine(renderer,posClawPointRight[0],posClawPointRight[1],tubeQuad[0][0],tubeQuad[0][1]);*/

    /*std::vector<float> vec = this->utils->triangle_apartir_de_deux_points(tubeQuad[0][0],tubeQuad[0][1],tubeQuad[1][0],tubeQuad[1][1]);
    //std::cout<<vec[0]<<std::endl;
    //SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+tubeQuad[0][0]+h/std::tan(pi/3))*coef,(y+tubeQuad[0][1]-h/std::tan(pi/3))*coef);
    //SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0]+h/std::tan(pi/3))*coef,(y+tubeQuad[0][1]-h/std::tan(pi/3))*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);
    float d1= utils->distance(vec[0],vec[1],tubeQuad[1][0],tubeQuad[1][1]);
    float d2= utils->distance(tubeQuad[0][0],tubeQuad[0][1],tubeQuad[1][0],tubeQuad[1][1])/2;
    float pyt= sqrt(d1*d1+d2*d2);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+vec[0])*coef,(y+vec[1])*coef);
    SDL_RenderDrawLine(renderer,(x+vec[0])*coef,(y+vec[1])*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[0][0])*coef,(y+tubeQuad[0][1])*coef,(x+tubeQuad[3][0])*coef,(y+tubeQuad[3][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[3][0])*coef,(y+tubeQuad[3][1])*coef,(x+tubeQuad[2][0])*coef,(y+tubeQuad[2][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuad[2][0])*coef,(y+tubeQuad[2][1])*coef,(x+tubeQuad[1][0])*coef,(y+tubeQuad[1][1])*coef);






}*/
void Blaster::move_r(SDL_Renderer * renderer,int i,int tubeQuads[16][4][2],int x,int y,int coef,int rect)
{
    
    /*std::vector<float> vec = this->utils->triangle_apartir_de_deux_points(tubeQuads[i][0][0],tubeQuads[i][0][1],tubeQuads[i][1][0],tubeQuads[i][1][1]);
    float d1= utils->distance(vec[0],vec[1],tubeQuads[i][1][0],tubeQuads[i][1][1]);
    float d2= utils->distance(tubeQuads[i][0][0],tubeQuads[i][0][1],tubeQuads[i][1][0],tubeQuads[i][1][1])/2;
    float pyt= sqrt(d1*d1+d2*d2);*/
    if(i==0)
    {
        
        /*vec = this->utils->triangle_apartir_de_deux_points(tubeQuads[15][0][0],tubeQuads[15][0][1],tubeQuads[15][1][0],tubeQuads[15][1][1]);
        d1 = utils->distance(vec[0],vec[1],tubeQuads[15][1][0],tubeQuads[15][1][1]);
        d2=utils->distance(tubeQuads[15][0][0],tubeQuads[15][0][1],tubeQuads[15][1][0],tubeQuads[15][1][1])/2;
        pyt= sqrt(d1*d1+d2*d2);
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[15][0][0])*coef,(y+tubeQuads[15][0][1])*coef,(x+vec[0])*coef,(y+vec[1])*coef);
        SDL_RenderDrawLine(renderer,(x+vec[0])*coef,(y+vec[1])*coef,(x+tubeQuads[15][1][0])*coef,(y+tubeQuads[15][1][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[15][0][0])*coef,(y+tubeQuads[15][0][1])*coef,(x+tubeQuads[15][3][0])*coef,(y+tubeQuads[15][3][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[15][3][0])*coef,(y+tubeQuads[15][3][1])*coef,(x+tubeQuads[15][2][0])*coef,(y+tubeQuads[15][2][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[15][2][0])*coef,(y+tubeQuads[15][2][1])*coef,(x+tubeQuads[15][1][0])*coef,(y+tubeQuads[15][1][1])*coef);*/
        this->drawblaster_bleu(renderer,tubeQuads[15],x,y,coef,rect);

    }
    else 
    {
        /*vec = this->utils->triangle_apartir_de_deux_points(tubeQuads[i-1][0][0],tubeQuads[i-1][0][1],tubeQuads[i-1][1][0],tubeQuads[i-1][1][1]);
        d1 = utils->distance(vec[0],vec[1],tubeQuads[i-1][1][0],tubeQuads[i-1][1][1]);
        d2=utils->distance(tubeQuads[i-1][0][0],tubeQuads[i-1][0][1],tubeQuads[i-1][1][0],tubeQuads[i-1][1][1])/2;
        pyt= sqrt(d1*d1+d2*d2);
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i-1][0][0])*coef,(y+tubeQuads[i-1][0][1])*coef,(x+vec[0])*coef,(y+vec[1])*coef);
        SDL_RenderDrawLine(renderer,(x+vec[0])*coef,(y+vec[1])*coef,(x+tubeQuads[i-1][1][0])*coef,(y+tubeQuads[i-1][1][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i-1][0][0])*coef,(y+tubeQuads[i-1][0][1])*coef,(x+tubeQuads[i-1][3][0])*coef,(y+tubeQuads[i-1][3][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i-1][3][0])*coef,(y+tubeQuads[i-1][3][1])*coef,(x+tubeQuads[i-1][2][0])*coef,(y+tubeQuads[i-1][2][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i-1][2][0])*coef,(y+tubeQuads[i-1][2][1])*coef,(x+tubeQuads[i-1][1][0])*coef,(y+tubeQuads[i-1][1][1])*coef);*/
        this->drawblaster_bleu(renderer,tubeQuads[i-1],x,y,coef,rect);

    }

    /*vec = this->utils->triangle_apartir_de_deux_points(tubeQuads[i][0][0],tubeQuads[i][0][1],tubeQuads[i][1][0],tubeQuads[i][1][1]);
    d1 = utils->distance(vec[0],vec[1],tubeQuads[i][1][0],tubeQuads[i][1][1]);
    d2=utils->distance(tubeQuads[i][0][0],tubeQuads[i][0][1],tubeQuads[i][1][0],tubeQuads[i][1][1])/2;
    pyt= sqrt(d1*d1+d2*d2);
    SDL_SetRenderDrawColor(renderer, 255,250,42,0);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][0][0])*coef,(y+tubeQuads[i][0][1])*coef,(x+vec[0])*coef,(y+vec[1])*coef);
    SDL_RenderDrawLine(renderer,(x+vec[0])*coef,(y+vec[1])*coef,(x+tubeQuads[i][1][0])*coef,(y+tubeQuads[i][1][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][0][0])*coef,(y+tubeQuads[i][0][1])*coef,(x+tubeQuads[i][3][0])*coef,(y+tubeQuads[i][3][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][3][0])*coef,(y+tubeQuads[i][3][1])*coef,(x+tubeQuads[i][2][0])*coef,(y+tubeQuads[i][2][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][2][0])*coef,(y+tubeQuads[i][2][1])*coef,(x+tubeQuads[i][1][0])*coef,(y+tubeQuads[i][1][1])*coef);
*/

    /*std::vector<float> vec = utils->mid_two_points(tubeQuads[i][0][0],tubeQuads[i][0][1],tubeQuads[i][1][0],tubeQuads[i][1][1]);
    this->xPos = vec[0];
    this->yPos = vec[1];
    std::cout<<"xPos : "<<xPos<<"yPos : "<<yPos<<std::endl;*/
    this->drawblaster(renderer,tubeQuads[i],x,y,coef,rect);


}


void Blaster::move_l(SDL_Renderer * renderer,int i,int tubeQuads[16][4][2],int x,int y,int coef,int rect)
{
    /*std::vector<float> vec = this->utils->triangle_apartir_de_deux_points(tubeQuads[i][0][0],tubeQuads[i][0][1],tubeQuads[i][1][0],tubeQuads[i][1][1]);
    float d1= utils->distance(vec[0],vec[1],tubeQuads[i][1][0],tubeQuads[i][1][1]);
    float d2= utils->distance(tubeQuads[i][0][0],tubeQuads[i][0][1],tubeQuads[i][1][0],tubeQuads[i][1][1])/2;
    float pyt= sqrt(d1*d1+d2*d2);*/
    if(i==15)
    {
        /*
        vec = this->utils->triangle_apartir_de_deux_points(tubeQuads[0][0][0],tubeQuads[0][0][1],tubeQuads[0][1][0],tubeQuads[0][1][1]);
        d1 = utils->distance(vec[0],vec[1],tubeQuads[0][1][0],tubeQuads[0][1][1]);
        d2=utils->distance(tubeQuads[0][0][0],tubeQuads[0][0][1],tubeQuads[0][1][0],tubeQuads[0][1][1])/2;
        pyt= sqrt(d1*d1+d2*d2);
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[0][0][0])*coef,(y+tubeQuads[0][0][1])*coef,(x+vec[0])*coef,(y+vec[1])*coef);
        SDL_RenderDrawLine(renderer,(x+vec[0])*coef,(y+vec[1])*coef,(x+tubeQuads[0][1][0])*coef,(y+tubeQuads[0][1][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[0][0][0])*coef,(y+tubeQuads[0][0][1])*coef,(x+tubeQuads[0][3][0])*coef,(y+tubeQuads[0][3][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[0][3][0])*coef,(y+tubeQuads[0][3][1])*coef,(x+tubeQuads[0][2][0])*coef,(y+tubeQuads[0][2][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[0][2][0])*coef,(y+tubeQuads[0][2][1])*coef,(x+tubeQuads[0][1][0])*coef,(y+tubeQuads[0][1][1])*coef);
*/
        this->drawblaster_bleu(renderer,tubeQuads[0],x,y,coef,rect);
    }
    else 
    {
        /*vec = this->utils->triangle_apartir_de_deux_points(tubeQuads[i+1][0][0],tubeQuads[i+1][0][1],tubeQuads[i+1][1][0],tubeQuads[i+1][1][1]);
        d1 = utils->distance(vec[0],vec[1],tubeQuads[i+1][1][0],tubeQuads[i+1][1][1]);
        d2=utils->distance(tubeQuads[i+1][0][0],tubeQuads[i+1][0][1],tubeQuads[i+1][1][0],tubeQuads[i+1][1][1])/2;
        pyt= sqrt(d1*d1+d2*d2);
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i+1][0][0])*coef,(y+tubeQuads[i+1][0][1])*coef,(x+vec[0])*coef,(y+vec[1])*coef);
        SDL_RenderDrawLine(renderer,(x+vec[0])*coef,(y+vec[1])*coef,(x+tubeQuads[i+1][1][0])*coef,(y+tubeQuads[i+1][1][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i+1][0][0])*coef,(y+tubeQuads[i+1][0][1])*coef,(x+tubeQuads[i+1][3][0])*coef,(y+tubeQuads[i+1][3][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i+1][3][0])*coef,(y+tubeQuads[i+1][3][1])*coef,(x+tubeQuads[i+1][2][0])*coef,(y+tubeQuads[i+1][2][1])*coef);
        SDL_RenderDrawLine(renderer,(x+tubeQuads[i+1][2][0])*coef,(y+tubeQuads[i+1][2][1])*coef,(x+tubeQuads[i+1][1][0])*coef,(y+tubeQuads[i+1][1][1])*coef);
        */
       this->drawblaster_bleu(renderer,tubeQuads[i+1],x,y,coef,rect);
    }
    /*
    vec = this->utils->triangle_apartir_de_deux_points(tubeQuads[i][0][0],tubeQuads[i][0][1],tubeQuads[i][1][0],tubeQuads[i][1][1]);
    d1 = utils->distance(vec[0],vec[1],tubeQuads[i][1][0],tubeQuads[i][1][1]);
    d2=utils->distance(tubeQuads[i][0][0],tubeQuads[i][0][1],tubeQuads[i][1][0],tubeQuads[i][1][1])/2;
    pyt= sqrt(d1*d1+d2*d2);
    SDL_SetRenderDrawColor(renderer, 255,250,42,0);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][0][0])*coef,(y+tubeQuads[i][0][1])*coef,(x+vec[0])*coef,(y+vec[1])*coef);
    SDL_RenderDrawLine(renderer,(x+vec[0])*coef,(y+vec[1])*coef,(x+tubeQuads[i][1][0])*coef,(y+tubeQuads[i][1][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][0][0])*coef,(y+tubeQuads[i][0][1])*coef,(x+tubeQuads[i][3][0])*coef,(y+tubeQuads[i][3][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][3][0])*coef,(y+tubeQuads[i][3][1])*coef,(x+tubeQuads[i][2][0])*coef,(y+tubeQuads[i][2][1])*coef);
    SDL_RenderDrawLine(renderer,(x+tubeQuads[i][2][0])*coef,(y+tubeQuads[i][2][1])*coef,(x+tubeQuads[i][1][0])*coef,(y+tubeQuads[i][1][1])*coef);
*/
    /*std::vector<float> vec = utils->mid_two_points(tubeQuads[i][0][0],tubeQuads[i][0][1],tubeQuads[i][1][0],tubeQuads[i][1][1]);
    xPos = vec[0];
    yPos = vec[1];*/
    this->drawblaster(renderer,tubeQuads[i],x,y,coef,rect);


}


