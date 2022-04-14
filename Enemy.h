#ifndef ENEMY_H
#define ENEMY_H
#include "Sprite.h"
#include "utils.hpp"




class Enemy{



public:
    Enemy();
    ~Enemy();
    void Movement(const float& x, const float& y);
    bool isExploding(){return Explode;}
    bool isHit(){return Hit;}
    

protected:
    Point position;
    bool Expolde; 
    bool Delete;
    bool Hit;
    SpriteInfo * Info;

    bool Explode(bool isDelete);
    void DetectCollision();
};
#endif
