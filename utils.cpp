#include "utils.hpp"
#include <iterator>


Utils::Utils()
{

}
Utils::~Utils()
{

}
std::vector<float> Utils::WeightedMidpoint(int vec1[2],int vec2[2],float weight)
{
    const int x1= vec1[0];
    const int y1 =vec1[1];
    const int x2 = vec2[0];
    const int y2 = vec2[1];
    std::vector<float> vec(x1*(1-weight) + x2*weight, y1*(1-weight) +y2*weight);
    return vec;
}
float Utils::distance(int vec1[2],int vec2[2])
{
    const int x1= vec1[0];
    const int y1 =vec1[1];
    const int x2 = vec2[0];
    const int y2 = vec2[1];
    return  sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1)));

}
std::vector<float> Utils::orthogonalUnitVector(int vec1[2],int vec2[2],int scalar )
{
    const int x1= vec1[0];
    const int y1 =vec1[1];
    const int x2 = vec2[0];
    const int y2 = vec2[1];
    const float x = (x2-x1) /this->distance(vec1,vec2)*scalar;
    const float y = (y2-y1)/this->distance(vec1,vec2)*scalar;
    std::vector<float> vec (x,y);
    return vec;

}
std::vector<float> Utils::addvector(std::vector<float> vec1,std::vector<float> vec2,int scalar )
{
    const float x1= vec1[0];
    const float y1 =vec1[1];
    const float x2 = vec2[0];
    const float y2 = vec2[1];
    std::vector<float> vec(x1+x2*scalar,y1+y2*scalar);
    return vec;

}
Point Utils::TubeCenter(int tubeShape[][][])
{
    Point *g;
    int x = tubeShape[1][0][0];
    int y = tubeShape[1][0][1];
    // std::size en c++17
    for(auto i = 1; i < std::size(tubeShape[1])-1; i++)
    {
        x += tubeShape[1][i][0];
        y += tubeShape[1][i][1];
    }
    x /= std::size(tubeShape[1])-1;
    y /= std::size(tubeShape[1])-1;
    g->x = x;
    g->y = y;
    return *g;
}

Drawlives(SDL_Renderer * renderer, int start_x, int start_y, int coeff)
{
    int i=0;
        for ( i = 0; i < std::size(coords)-1;i++)
        {
            SDL_RenderDrawLine(renderer, (coords[i][0]+start_x)*coeff, (coords[i][1]+start_y)*coeff, (coords[i+1][0]+start_x)*coeff, (coords[i+1][1]+start_y)*coeff);
        }
        SDL_RenderDrawLine(renderer, (coords[i][0]+start_x)*coeff, (coords[i][1]+start_y)*coeff, (coords[0][0]+start_x)*coeff, (coords[0][1]+start_y)*coeff);
}
