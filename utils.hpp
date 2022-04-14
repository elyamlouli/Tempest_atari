#ifndef UTILS
#define UTILS

#include <vector>
#include <stdio.h>
#include <math.h>


struct Point{
    float x; 
    float y; 

    Point(){}
    Point(float x_, float y_): x(x_), y(y_) {}
    Point operator-(Point p)
    {
        this->x -= p.x; 
        this->y -= p.y;
        return *this;
    }
};

struct Utils
{

    Utils();
    ~Utils();
    std::vector<float> WeightedMidpoint(int vec1[2],int vec2[2],float weight);
    std::vector<float> orthogonalUnitVector(int vec1[2],int vec2[2],int scalar );
    float distance(int vec1[2],int vec2[2]);
    std::vector<float> addvector(std::vector<float> vec1,std::vector<float> vec2,int scalar);
    // centre du tube qui dépend du shape du tube 
    Point TubeCenter (int tubeShape[][][]);      




};


#endif