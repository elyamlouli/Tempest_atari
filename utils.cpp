#include "utils.hpp"


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