#ifndef GAME
#define GAME
#include <SDL.h>
#include <assert.h>
#include "enemy.hpp"
#include "bullet.hpp"
#include <iostream>
#include "score.hpp"


class Games
{
    public:

    std::vector<Score *> lives;
    std::vector<Bullet *> bullets;
	std::vector<Enemy *> enemies;

    Score * score;
    Games();
    ~Games();
    void explode(Utils *utils);
    

};


#endif