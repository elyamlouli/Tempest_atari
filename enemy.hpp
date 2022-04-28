#ifndef ENEMY_H
#define ENEMY_H

#include <SDL.h>
#include <utility>
#include <algorithm>

#include "utils.hpp"
#include "tube.hpp"

class Enemy
{
private:
    SDL_Renderer *renderer;
    Tube *tube;
    Utils *utils;
    std::pair<double, double> position; //
    float profondeur;
    float z;
    int pos_xinit;
    int pos_yinit;
    double ennemies;
    int quad;
    int quad_suivant;
    int id;
    int temp;
    int tab_vivants[4];
    bool alive;
    int i;

public:
    Enemy(int quad, int id);
    ~Enemy();
    std::vector<int> get_tab_vivants();
    void set_tab_vivants(int id);
    void draw_flipper(SDL_Renderer *renderer);
    //int getPosition();
    void move(int tubeQuad[4][2], int scale, float velocity_coef);
    double get_ennemies();
    float get_profondeur();
    int get_quad();
    int get_id();
    int get_temp();
    std::pair<double, double> get_position();
    bool get_alive();
    void set_alive(bool b);
    void move_circle(SDL_Renderer *renderer, int scale);
    void set_quad_suivant(int i);
    int get_i();
    //void move_enemies(SDL_Renderer * renderer_game,float velocity_coef,Enemy *enemy);
};

#endif