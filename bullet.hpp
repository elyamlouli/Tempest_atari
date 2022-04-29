#ifndef BULLET
#define BULLET

#include <SDL.h>
#include <cassert>
#include <iostream>
#include <memory>
#include "utils.hpp"
/**
 * @brief
 * Classe des missiles envoyés par le blaster pour tuer les ennemies 
 */

class Bullet
{
private:
    bool vivant_bullet;
    std::pair<double, double> P;
    float profondeur;

public:
    std::shared_ptr<Utils>utils;
    int quad;
    float dist;
    Bullet(int quad);
    ~Bullet();
    void draw_bullet(SDL_Renderer *renderer, int radius);
    /**
     * @brief 
     * Déplacer le missiles dans un tube à la vitesse velocity_coef
     * @param tubeQuad 
     * @param scale 
     * @param velocity_coef 
     */
    void move(std::array<std::pair<int,int>,4> tubeQuad, int scale, float velocity_coef);

    void set_bullet(bool b);
    bool get_bullet();
    void set_P(std::pair<double, double>p);
    std::pair<double, double> get_P();
    float get_profondeur();
    void set_profondeur(float p);
};

#endif