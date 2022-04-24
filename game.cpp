#include "game.hpp"



Game::Game()
{}

Game::Game(SDL_Window *window, SDL_Renderer *renderer): window(window), renderer(renderer)
{
    score = 0;
    level = 1;
    lives = 5;
}

Game::~Game()
{}

void Game::explode()
{
    for (auto & enemy : this->enemies)
    {
        for( auto &bullet:bullets)
        {
            if ((enemy->getPosition().first ==  bullet->getPosition().first) && (enemy->getPosition().second ==  bullet->getPosition().second))
            {
                delete bullet;
                delete enemy;
                score += 150;
            }

        }
    }
}
