#ifndef MENU
#define MENU

#include <SDL.h>
#include <assert.h>

#include <iostream>
#include <string>
#include <cmath>

const double pi = std::acos(-1);
/**
 * @brief 
 * Classe Menu qui sert pour l'affichage du texte et le dessin des tubes
 */

class Menu
{
public:
    Menu();
    ~Menu();
    /**
     * @brief 
     * Permet l'ecriture en utilisant les fontes de hersheys
     * @param renderer 
     * @param str : chaîne de caractère à écrire 
     * @param start_x : abssice de départ
     * @param start_y : ordonnée de départ
     * @param coeff : taille de la forme 
     */
    void hershey(SDL_Renderer *renderer, std::string str, int start_x, int start_y, int coeff);

    
};

#endif