#include "enemy.hpp"
#define DEPTH_TUBE_COEF 0.07


Enemy::Enemy(int quad,int id) :quad(quad),id(id)
{
    utils = std::shared_ptr<Utils>(new Utils());
    tube = std::shared_ptr<Tube>(new Tube(Tube_Circle));
    utils_enemy = std::shared_ptr<UtilsEnemy>(new UtilsEnemy());    
    this->profondeur=DEPTH_TUBE_COEF;
    this->z=1;
    pos_xinit=15;
    pos_yinit=15;
    this->ennemies++;
    temp=0;
    tab_vivants[id]=1;
    alive = true;
    quad_suivant=quad+1;
    //tube = new Tube(Tube_Circle);
    //tube->affect_quads(Tube_Circle);
    //i=0;
   
    
    //this->profondeur=1;

    

}
Enemy::~Enemy() 
{
    
    
}
bool Enemy::get_alive()
{
    return alive;
}
void Enemy::set_alive(bool b)
{
    alive=b;
}
std::vector<int> Enemy::get_tab_vivants()
{
    std::vector<int>vec ;
    for(int i=0;i<4;i++)
    {
        vec.push_back(tab_vivants[i]);
    }
    return vec;
    

}
void Enemy::set_tab_vivants(int i)
{
    tab_vivants[i]=0;
}
std::pair<double,double> Enemy::get_position()
{
    return this->position;
}
int Enemy::get_id()
{
    return id;
}
int Enemy::get_quad()
{
    return this->quad;
}
    
double Enemy::get_ennemies()
{
    return this->ennemies;
}

float Enemy::get_profondeur()
{
    return this->profondeur;
}


void Enemy::draw_flipper(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, 255,0,0,0);
    SDL_RenderDrawLine (renderer,(this->position.first-5), (this->position.second-5), (this->position.first), (this->position.second) );
    SDL_RenderDrawLine (renderer, (this->position.first), (this->position.second),(this->position.first+5), (this->position.second+5) );
    SDL_RenderDrawLine (renderer, (this->position.first), (this->position.second),(this->position.first+5), (this->position.second-5));
    SDL_RenderDrawLine (renderer, (this->position.first), (this->position.second),(this->position.first-5), (this->position.second+5 ));
    
}
void Enemy::move(std::array<std::pair<int,int>,4> tubeQuad,int scale,float velocity_coef)
{
    this->position = this->utils_enemy->find_position(tubeQuad,this->pos_xinit,this->pos_yinit,scale,this->profondeur);
    std::vector<float> vec =utils->mid_two_points(tubeQuad[0].first*scale,tubeQuad[0].second*scale,tubeQuad[1].first*scale,tubeQuad[1].second*scale)  ;
    /*if(fabs(utils->distance(this->position.first,this->position.second,vec[0],vec[1]))<=0.03)
    {
        std::cout<<"hi";
        this->profondeur = -1;
    }*/
    /*
    this->position.first = this->position.first/ this->profondeur;
    this->position.second = this->position.second/ this->profondeur;*/
    

    
    this->z -= velocity_coef;
    if (z >= 0)
        profondeur= (1 - DEPTH_TUBE_COEF) * sqrt(z);
    else 
        profondeur = 0;

    
    

}
void Enemy::set_quad_suivant(int i)
{
    quad_suivant=i;
}
int Enemy::get_i()
{
    return i;
}
void Enemy::set_quad(int i)
{
    this->quad=i;
}
void Enemy::move_circle(SDL_Renderer *renderer,int scale,int tubeQuads[16][4][2],float velocity_coef)
{
    
    //std::cout<<tube->tube_quads[this->quad+i][0][0]<<std::endl;
    if(this->quad<15)
    {
        this->position.first = tubeQuads[this->quad+1][0][0]*scale;
        printf("%i\n",quad+i);
        this->position.second = tubeQuads[this->quad+1][0][1]*scale;
        set_quad(quad+1);
        
        
        
    }
    else if(this->quad==15)
    {
        
        this->position.first = tube->tube_quads[0][0].first*scale;
        this->position.second = tube->tube_quads[0][0].second*scale;
        set_quad(0);
        
    }
    
    
}



