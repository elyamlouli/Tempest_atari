#ifndef UTILS
#define UTILS

#include <vector>
#include <stdio.h>
#include <math.h>

struct Utils
{

    Utils();
    ~Utils();
    std::vector<float> WeightedMidpoint(int vec1[2],int vec2[2],float weight);
    std::vector<float> orthogonalUnitVector(int vec1[2],int vec2[2],int scalar );
    float distance(int vec1[2],int vec2[2]);
    std::vector<float> addvector(std::vector<float> vec1,std::vector<float> vec2,int scalar);


};


#endif