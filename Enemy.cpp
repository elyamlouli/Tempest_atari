#include "enemy.hpp"

Enemy::Enemy(int quad) :quad(quad)
{
    utils = new Utils();
    this->profondeur=1;
    pos_xinit=15;
    pos_yinit=15;
    this->time++;
    

}
Enemy::~Enemy() 
{
    
}
int Enemy::get_quad()
{
    return this->quad;
}
    
double Enemy::get_time()
{
    return this->time;
}
float Enemy::get_profondeur()
{
    return this->profondeur;
}


void Enemy::draw_flipper(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255,0,0,0);
    SDL_RenderDrawLine (renderer,this->position.first-5, this->position.second-5, this->position.first+5, this->position.second+5 );
    SDL_RenderDrawLine (renderer,this->position.first-5, this->position.second+5, this->position.first+5, this->position.second-5 );
    
}
void Enemy::move(int tubeQuad[4][2],int scale,float velocity_coef)
{
    this->position = this->utils->find_position_enemy(tubeQuad,this->pos_xinit,this->pos_yinit,scale,this->profondeur);
    this->profondeur -= velocity_coef;

}

/*Enemy::getPosition()
{
    return position;
}*/
