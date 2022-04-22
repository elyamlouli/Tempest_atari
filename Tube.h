#ifndef TUBE_H
#define TUBE_H
#include "Enemy.h"
#include "utils.hpp"
#include "blaster.hpp"
#include <SDL.h>




class Tube
{
    private : 

        int tab[2][17][2];

    public : 
        Tube();
        ~Tube();
        int tab[2][17][2] get_tab();

};

#endif

