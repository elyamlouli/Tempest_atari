#ifndef UTILS
#define UTILS

#include <vector>
#include <math.h>
#include <iostream>
#include <SDL.h>
#include <array>

/**
 * @brief
 * Classe contenant toute les fonctions qui vont être utiles par la suite
 */
class Utils
{
private:
    double time;

public:
    Utils();
    ~Utils();
    // Possible d'intégrer template

    /**
     * @brief
     * Fonction permettant de calculer la distance entre deux vecteurs ou deux points
     * @param vec1
     * @param vec2
     * @return float
     */
    float distance(int vec1[2], int vec2[2]);
    float distance(int x1, int y1, int x2, int y2);

    /**
     * @brief
     * Fonction permettant de calculer le centre du vecteur reliant entre le point (x1, y1)
     * et le point (x2, y2)
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     * @return std::vector<float>
     */
    std::vector<float> mid_two_points(int x1, int y1, int x2, int y2);
    /**
     * @brief
     * Fonction permettant de chercher la nouvelle position en utilisant
     * la matrice de rotation et l'homothétie comme expliqué dans l'énoncé
     * @param tubeQuad
     * @param ax
     * @param ay
     * @param scale
     * @param profondeur
     * @return std::pair<double, double>
     */
    std::pair<double, double> find_position(std::array<std::pair<int, int>, 4> tubeQuad, int ax, int ay, int scale, float profondeur);
    /**
     * @brief
     * Fonction permettant d'ecrire la chaîne de caractère STR en utilisant les fentes de hersheys
     * @param renderer
     * @param str
     * @param start_x
     * @param start_y
     * @param coeff
     */
    void hershey(SDL_Renderer *renderer, std::string str, int start_x, int start_y, int coeff);
    double get_time();
    void set_time(int t);
};

/**
 * @brief
 * Classe dérivée de la classe Utils permettant de surcharger la fonction find_position pour un ennemi
 */
class UtilsEnemy : public Utils
{
public:
    UtilsEnemy();
    ~UtilsEnemy();
    std::pair<double, double> find_position(std::array<std::pair<int, int>, 4> tubeQuad, int ax, int ay, int scale, float profondeur);
};

#endif