#ifndef ENEMY_H
#define ENEMY_H

#include <SDL.h>
#include <utility>
#include <algorithm>
#include <memory>
#include "tube.hpp"
#include "utils.hpp"

/**
 * @brief 
 * Classe de l'ennemi qui sort du centre de la map pour se diriger en ligne droite vers 
 * le bout du tube, il est mort si il y a collision avec le missile.
 */
class Enemy
{
private:
    std::shared_ptr<Tube>tube;
    std::shared_ptr<Utils>utils;
    std::shared_ptr<UtilsEnemy>utils_enemy;
    std::pair<double, double> position; 
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
    double get_ennemies();
    float get_profondeur();
    int get_quad();
    int get_id();
    int get_temp();
    std::pair<double, double> get_position();
    bool get_alive();
    void set_tab_vivants(int id);
    void set_alive(bool b);
    void set_quad_suivant(int i);
    int get_i();
    void set_quad(int i);
    void move_circle(SDL_Renderer *renderer, int scale, int tubeQuads[16][4][2], float velocity_coef);
    void draw_flipper(SDL_Renderer *renderer);
    void move(std::array<std::pair<int,int>,4> tubeQuad, int scale, float velocity_coef);
};

#endif