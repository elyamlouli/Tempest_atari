#ifndef ENEMY_H
#define ENEMY_H
#define FLIPPER_POS 7 
#define MAX_Z_POS 120 
#include "Sprite.h"
#include "utils.hpp"
#include <cmath>




class Enemy{
public:
    Enemy();
    ~Enemy();
    void Movement(const float& x, const float& y);
    bool isExploding(){return Explode;}
    bool isHit(){return Hit;}
    

protected:
    //Point position;
    int xPos;
    int zPos;
    int xVel; // À voir ça sert à quoi 
    int xPosInTubeQuad;
    int tubeQuadIdx;
    bool Expolde; 
    bool Delete;
    bool Hit;
    SpriteInfo * Info;

    bool Explode(bool isDelete);
    void DetectCollision();
};
#endif
