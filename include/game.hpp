#ifndef GAME
#define Game
#include <SDL.h>
#include <ctime>
#include <random>
#include <cassert>
#include <memory>
#include <iostream>

#include "enemy.hpp"
#include "bullet.hpp"
#include "score.hpp"
#include "menu.hpp"
#include "blaster.hpp"
#include "tube.hpp"
#include "utils.hpp"

/**
 * @brief
 * Classe game qui regroupe toutes les briques du jeu
 */
class Games
{
public:
    std::vector<Score * > lives;
    std::vector<Bullet * > bullets;
    std::vector<Enemy * > enemies;
    std::shared_ptr<Menu> menu;
    std::shared_ptr<Score>score;
    std::shared_ptr<Blaster>blaster;
    std::shared_ptr<Tube>tube;
    std::shared_ptr<Utils>utils;
    //Sound* CollisionSound;
    Games();
    ~Games();
    /**
     * @brief 
     * Permet d'afficher le menu principal
     * @param renderer 
     */
    void menu_principal(SDL_Renderer *renderer);
    
    /**
     * @brief 
     * Permet de tracer les tubes et le texte à la deuxième interface
     * @param renderer 
     * @param quad 
     */
    void menu_jeu(SDL_Renderer *renderer, int quad);
    /**
     * @brief 
     * Permet d'afficher l'interface juste après le menu principal
     * @return int 
     */
    int genere_menu();
    /**
     * @brief 
     * Fonction qui permet de détruire l'ennemi et le missile si 
     * il y a collision entre les deux
     * @param utils 
     */
    void explode(std::shared_ptr<Utils> utils);
    /**
     * @brief 
     * Permet de tracer les vies 
     * @param renderer 
     */
    void draw_lives(SDL_Renderer *renderer);
    /**
     * @brief 
     * permet de génerer les ennemies aléatoirement dont la vitesse est velocity coef
     * @param renderer 
     * @param velocity_coef 
     */
    void generate_enemies(SDL_Renderer *renderer, float velocity_coef);
    /**
     * @brief 
     * permet de génerer les missiles aléatoirement dont la vitesse est velocity coef
     * @param renderer 
     * @param velocity_coef 
     */
    void generate_bullets(SDL_Renderer *renderer, float velocity_coef);
    /**
     * @brief 
     * Permet de génerer la page de jeu et tout ce qu'il faut avec
     * @param velocity_coef 
     */
    void jouer(float velocity_coef);
    void game_over();
};

#endif