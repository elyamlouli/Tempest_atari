#include "utils.hpp"
#include <cmath>


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
    std::vector<float> vec;
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
float Utils::distance(int x1,int y1,int x2,int y2)
{
    return sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1)));
}
std::vector<float> Utils::orthogonalUnitVector(int vec1[2],int vec2[2],int scalar )
{
    const int x1= vec1[0];
    const int y1 =vec1[1];
    const int x2 = vec2[0];
    const int y2 = vec2[1];
    const float x = (x2-x1) /this->distance(vec1,vec2)*scalar;
    const float y = (y2-y1)/this->distance(vec1,vec2)*scalar;
    std::vector<float> vec;
    vec.push_back(x);
    vec.push_back(y);
    return vec;

}
// std::vector<float> Utils::addvector(std::vector<float> vec1,std::vector<float> vec2,int scalar )
// {
//     const float x1= vec1[0];
//     const float y1 =vec1[1];
//     const float x2 = vec2[0];
//     const float y2 = vec2[1];
//     std::vector<float> vec;
//     vec.push_back(x1+x2*scalar);
//     vec.push_back(y1+y2*scalar);
//     return vec;

// }

std::pair<double, double> Utils::vect(std::pair<double, double> a , std::pair<double, double> b, int scalar = 1)
{
    std::pair<double, double> vec = std::make_pair((b.first-a.first)*scalar, (b.second-a.second)*scalar);
    return vec;
}
std::vector<float> Utils::vect(int a[2] , int b[2], int scalar = 1)
{
    std::vector<float> vec ;
    vec.push_back((b[0]-a[0])*scalar); 
    vec.push_back((b[1]-a[1])*scalar);
    return vec;
}
std::vector<float> Utils::triangle_apartir_de_deux_points(int x1,int y1,int x2,int y2)
{
    float x_1 = static_cast<float> (x1);
    float x_2 = static_cast<float> (x2);
    float y_1 = static_cast<float> (y1);
    float y_2 = static_cast<float> (y2);

    
    //std::cout<< "y_1 "<<y_1<<"y_2 "<<y_2<<std::endl;
    float findx_1,findy_1,findx_2,findy_2;
    float sidelength1 = x_1-x_2;
    float sidelength2 = y_1-y_2;

    float sidelength = sqrt(sidelength1*sidelength1+ sidelength2*sidelength2);
    

    //point median
    float tempx,tempy;
    tempx = (x_1+x_2)/2;
    tempy = (y_1+y_2)/2;

    if (fabs(x_1 - x_2) < 0.001)       //  Vertical 
    { 

        findy_1 = tempy;
        findy_2 = tempy;

        float temp_len = sqrt(3.0) / 2 * sidelength;

        findx_1 = tempx + temp_len;
        findx_2 = tempx - temp_len;
        
    }
    else if (fabs(y_1 - y_2) < 0.001)    //  En parallèle 
    { 

        findx_1 = tempx;
        findx_2 = tempx;

        float temp_len = sqrt(3.0) / 2 * sidelength;

        findy_1 = tempy + temp_len;
        findy_2 = tempy - temp_len;
        

    }
    //pente 
    else{
        float k,k1;
        float b,b1;
        k= (y_2-y_1) / (x_2-x_1);
        std::cout<< "y_2-y_1  "<<y_2-y_1<<std::endl;
        std::cout<< "x_2-x_1 "<<x_2-x_1<<std::endl;
        std::cout<< "k  "<<(y_2-y_1)/(x_2-x_1)<<std::endl;
        b= y_1 -k*x_1;
        

        k1 = -1/k;
        b1= tempy - k1*tempx;

        float db;
        db = 2* k1*(b1 -tempy) - 2* tempx;

        float da;
        da = k1*k1 +1;

        float dc;
        dc = tempx*tempx + (b1 -tempy)*(b1 -tempy) - (3.0 /4) * sidelength* sidelength;

        float dx;
        dx = db * db -4 *da*dc;
        dx = sqrt(db*db -4 *da*dc);

        float xa,xb,ya,yb;
        xa = ((-db+dx)/(2*da));
        xb = ((-db -dx)/(2*da));

        ya = xa*k1 +b1;
        yb= xb * k1 +b1;
        

        if(x1>x2 )
        {
            findx_1=xb;
            findy_1=yb;
            findx_2=xa;
            findy_2=ya;
            
        } 
        

        else{
            
            findx_1=xa;
            findy_1=ya;
            findx_2=xb;
            findy_2= yb;
            
        }

    }
    std::cout<< "x_1  "<<findx_1<<std::endl;
    
    std::vector<float> vec ;
    vec.push_back(findx_1);
    vec.push_back(findy_1);
    vec.push_back(findx_2);
    vec.push_back(findy_2);
    
    return vec;


}

std::vector<float> Utils::mid_two_points(int x1,int y1,int x2,int y2)
{
    float x =  (static_cast<float> (x1) + static_cast<float> (x2))/2;
    float y = (static_cast<float> (y1) + static_cast<float> (y2))/2;
    std::vector<float> vec ;
    vec.push_back(x);
    vec.push_back(y);
    return vec;
}
std::pair<double, double> Utils::find_position(int tubeQuad[4][2], int ax, int ay,int scale,float profondeur,bool middle)
{
    std::pair<double, double> D;
    double new_ax,new_ay;
    int window_x ;
    int window_y ;
    if(tubeQuad[0][0]<tubeQuad[1][0] && tubeQuad[0][1]<tubeQuad[1][1] )
    {
        window_x = 523;
        window_y = 563;

    }
    else if(tubeQuad[0][0]>tubeQuad[1][0] && tubeQuad[0][1]<tubeQuad[1][1])
    {
        window_x = 517;
        window_y = 570;

    }
    else if(tubeQuad[0][0]<tubeQuad[1][0] && tubeQuad[0][1]>tubeQuad[1][1])
    {
        window_x = 512;
        window_y = 558;

    }
    else{
        window_x = 520;
        window_y = 570;

    }
    

    int ABx = tubeQuad[1][0]*scale - tubeQuad[0][0]*scale;
    int ABy = tubeQuad[1][1]*scale - tubeQuad[0][1]*scale;
    double normAB = sqrt(ABx * ABx + ABy * ABy);
    double ux = ABx / normAB;
    double uy = ABy / normAB;

    if (middle) {
        new_ax =  (ux * ax - uy * ay + (tubeQuad[0][0] + tubeQuad[1][0])*scale/2 - window_x) *profondeur+ window_x;
        new_ay = (uy * ax + ux * ay + (tubeQuad[0][1] + tubeQuad[1][1])*scale/2 - window_y)*profondeur + window_y;
    }

    else {
        new_ax =  (ux * ax - uy * ay + tubeQuad[0][0]*scale- window_x) + window_x;
        new_ay = (uy * ax + ux * ay + tubeQuad[0][1]*scale - window_y) + window_y;
    }
    D.first= new_ax;
    D.second = new_ay;
    return D;

}
std::pair<double, double> Utils::find_position_enemy(int tubeQuad[4][2], int ax, int ay,int scale,float profondeur)
{
    std::pair<double, double> D;
    double new_ax,new_ay;
    std::vector<float> vec =this->mid_two_points(tubeQuad[0][0]*scale,tubeQuad[0][1]*scale,tubeQuad[1][0]*scale,tubeQuad[1][1]*scale)  ;
    
   
    

    int CDx = tubeQuad[3][0]*scale - tubeQuad[2][0]*scale;
    int CDy = tubeQuad[3][1]*scale - tubeQuad[2][1]*scale;
    double normCD = sqrt(CDx * CDx + CDy * CDy);
    double ux = CDx / normCD;
    double uy = CDy / normCD;

    
    new_ax =  (uy * ax - ux * ay + (tubeQuad[2][0] + tubeQuad[3][0])*scale/2 - vec[0])*profondeur+ vec[0];
    new_ay = (ux * ax + uy * ay + (tubeQuad[2][1] + tubeQuad[3][1])*scale/2 - vec[1])*profondeur + vec[1];
    

    
    D.first= new_ax;
    D.second = new_ay;
    return D;

}

std::pair<double, double> addvector(std::pair<double, double> a , std::pair<double, double> b,int scalar)
{
    std::pair<double, double> vec = vec = std::make_pair(b.first+a.first*scalar, b.second+a.second*scalar);
    return vec;
}

std::vector<float> addvector(int vec1[2],std::vector<float> vec2,int scalar)
{
    const float x1= vec1[0];
    const float y1 =vec1[1];
    const float x2 = vec2[0];
    const float y2 = vec2[1];
    std::vector<float> vec;
    vec.push_back(x1+x2*scalar);
    vec.push_back(y1+y2*scalar);
    return vec;

}

// float theta(point1, point2, point3) {
//     const a = Util.distanceBetweenPoints(point1, point2);
//     const b = Util.distanceBetweenPoints(point2, point3);
//     const c = Util.distanceBetweenPoints(point1, point3);
//     float numerator = Math.pow(a, 2) + Math.pow(b, 2) - Math.pow(c, 2);
//     float denominator = 2 * a * b;
//     return Math.acos(numerator/denominator);
// }