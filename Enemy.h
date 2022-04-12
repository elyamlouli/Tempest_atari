#ifndef ENEMY_H
#define ENEMY_H


struct Point{
    float x; 
    float y; 

    Point(){}
    Point(float x_, float y_): x{x_}, y{y_} {}
    Point operator-(Point p)
    {
        this->x -= p.x; 
        this->y -= p.y;
        return *this;
    }
};

class Enemy{
private:
    Point position;


public:
    Enemy();
    ~Enemy();
    void Movement(const float& x, const float& y);


};
