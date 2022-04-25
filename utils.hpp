#ifndef UTILS
#define UTILS

#include <vector>
#include <stdio.h>
#include <math.h>
#include <iostream>

struct Utils
{

    Utils();
    ~Utils();
    std::vector<float> WeightedMidpoint(int vec1[2],int vec2[2],float weight);
    std::vector<float> orthogonalUnitVector(int vec1[2],int vec2[2],int scalar );
    float distance(int vec1[2],int vec2[2]);
    float distance(int x1,int y1,int x2,int y2);
    std::vector<float> mid_two_points(int x1,int y1,int x2,int y2);
    //std::vector<float> addvector(std::vector<float> vec1,std::vector<float> vec2,int scalar);
    std::vector<float> triangle_apartir_de_deux_points(int x1,int y1,int x2,int y2);
    std::pair<double, double> find_position(int tubeQuad[4][2], int ax, int ay,int scale,float profondeur,bool middle);
    std::pair<double, double> find_position_enemy(int tubeQuad[4][2], int ax, int ay,int scale,float profondeur);
    std::pair<double, double> vect(std::pair<double, double> a , std::pair<double, double> b, int scalar );
    //std::pair<double, double> addvector(std::pair<double, double> a , std::pair<double, double> b,int scalar);
    std::vector<float> vect(int a[2] , int b[2], int scalar);
    std::vector<float> addvector(int vec1[2],std::vector<float> vec2,int scalar);
    float distanceBetweenPoints(std::pair<float,float> a,std::pair<float,float> b );
    float theta(int p1[2], int p2[2], int p3[2]);

};


#endif