#ifndef FORME
#define FORME

#include <SDL.h>

class Forme
{
    Forme();
    ~Forme();
    void cercle(SDL_Renderer *renderer, int rayon, int centreX, int centreY);
};
#endif