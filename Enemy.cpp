#include "Enemy.h"

Enemy::Enemy(int xPos_, int xVel_, )
{
    xPos = xPos_;
    xVel = xVel_;
    zPos = MAX_Z_POS;
    xPosInTubeQuad = xPos % FLIPPER_POS;
    tubeQuadIdx = floor(xPos / FLIPPER_POS);


}


// void Enemy::Movement(const float x, const float y)
// {
//     position.x += x;
//     position.y += y;
// }
void move()
{
    
}