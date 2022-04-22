#include "tube.hpp"

Tube::Tube(Forme f):forme(f)
{

}
Tube::~Tube()
{

}
void Tube::affect_tab(Forme f)
{
    if(f==0)
    {
        for(int i =0;i<2;i++)
        {
            for(int j=0;j<17;j++)
            {
                for(int k=0;k<2;k++)
                {
                    this->tube[i][j][k]= Tube_Circles[i][j][k];

                }
            }
        }

    }
    
    
        
    
}

void Tube::affect_quads(Forme f)
{
    if(f==0)
    {
        for(int i =0;i<16;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<2;k++)
                {
                    this->tube_quads[i][j][k]= tubeQuads[i][j][k];

                }
            }
        }

    }


}
