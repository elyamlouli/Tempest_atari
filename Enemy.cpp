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
{}

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
double Enemy::get_velocity()
{
    return this->velocity;
}
std::pair<double,double> Enemy::getPosition()
{
    return std::make_pair(this->position.first, this->position.second);
}

void Enemy::draw_flipper(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255,0,0,0);
    SDL_RenderDrawLine (renderer,(this->position.first-5)*1/this->profondeur, (this->position.second-5)*1/this->profondeur, (this->position.first+5)*1/this->profondeur, (this->position.second+5)*1/this->profondeur );
    SDL_RenderDrawLine (renderer,(this->position.first-5)*1/this->profondeur, (this->position.second-5)*1/this->profondeur, (this->position.first-4)*1/this->profondeur, (this->position.second)*1/this->profondeur );
    SDL_RenderDrawLine (renderer,(this->position.first-4)*1/this->profondeur, (this->position.second)*1/this->profondeur, (this->position.first-5)*1/this->profondeur, (this->position.second+5)*1/this->profondeur );
    SDL_RenderDrawLine (renderer,(this->position.first-5)*1/this->profondeur, (this->position.second+5)*1/this->profondeur, (this->position.first+5)*1/this->profondeur, (this->position.second-5)*1/this->profondeur );
    SDL_RenderDrawLine (renderer,(this->position.first+5)*1/this->profondeur, (this->position.second-5)*1/this->profondeur, (this->position.first+4)*1/this->profondeur, (this->position.second)*1/this->profondeur );
    SDL_RenderDrawLine (renderer,(this->position.first+4)*1/this->profondeur, (this->position.second)*1/this->profondeur, (this->position.first+5)*1/this->profondeur, (this->position.second+5)*1/this->profondeur );
    
}
void Enemy::move(int tubeQuad[4][2],int scale,float velocity_coef)
{
    this->position = this->utils->find_position_enemy(tubeQuad,this->pos_xinit,this->pos_yinit,scale,this->profondeur);
    this->profondeur -= velocity_coef;
    std::cout << profondeur << std::endl;
}


// void draw(Utils * utils)
// {
//     std::pair<double, double> RR = utils->vect(tubeQuad[0][0], tubeQuad[3], 1);
//     std::pair<double, double> RL = utils->vect(tubeQuad[1], tubeQuad[2], 1);
//     std::pair<double, double> PPR = utils->addvector(tubeQuad[0], RR, 1);



    
// }
