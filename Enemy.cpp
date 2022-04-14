#include "Enemy.h"


void Enemy::Movement(const float x, const float y)
{
    position.x += x;
    position.y += y;
}