#ifndef GAME
#define GAME
#include <SDL.h>
#include <assert.h>
#include <iostream>
#include <vector>
//#include "tube.hpp"
#include "blaster.hpp"
#include "enemy.hpp"
#include "bullet.hpp"

class Game{
private:
    SDL_Renderer *renderer;
    SDL_Window *window;
    Tube *tube;
    Blaster *blaster;
    std::vector<Enemy* > enemies;
    std::vector<Bullet* > bullets;

    int lives;
    int score;
    int level;


public:
    Game();
    Game(SDL_Window *window, SDL_Renderer *renderer);
    ~Game();
    void explode();
    

};


#endif