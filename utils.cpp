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
    //std::cout<<"x1"<<x1<<std::endl;
    const int y1 =vec1[1];
    //std::cout<<"y1"<<y1<<std::endl;
    const int x2 = vec2[0];
    //std::cout<<"x2"<<x2<<std::endl;
    const int y2 = vec2[1];
    //std::cout<<"x2"<<y2<<std::endl;
    std::vector<float> vec={};
    vec.push_back(x1*(1-weight) + x2*weight);
    vec.push_back(y1*(1-weight) +y2*weight);
    //std::cout<<"-------------------------"<<std::endl;
    //std::cout<<"("<<x1*(1-weight) + x2*weight<<", "<<y1*(1-weight) +y2*weight<<")"<<std::endl;
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
    std::vector<float> vec={};
    vec.push_back(x);
    vec.push_back(y);
    return vec;

}
std::vector<float> Utils::addvector(std::vector<float> vec1,std::vector<float> vec2,int scalar )
{
    const float x1= vec1[0];
    const float y1 =vec1[1];
    const float x2 = vec2[0];
    const float y2 = vec2[1];
    std::vector<float> vec={};
    vec.push_back(x1+x2*scalar);
    vec.push_back(y1+y2*scalar);
    return vec;

}