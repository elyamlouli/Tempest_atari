#include "Tube.h"
#include <SDL.h>


Tube(Point a_, Point b_, Point c_, Point d_):a{a_}, b{b_}, c{c_}, d{d_} {}

Tube::draw(SDL_Renderer * renderer, int start_x, int start_y, int coeff)
{
    int old_x = start_x + a.x*coeff;  
    int old_y = start_y + a.y*coeff;
    int old_u = start_x + b.x*coeff;  
    int old_v = start_y + b.y*coeff;
    int new_x = start_x + d.x*coeff; 
    int new_y = start_y + d.y*coeff;
    int new_u = start_x + c.x*coeff;  
    int new_v = start_y + c.y*coeff;
    SDL_RenderDrawLine(renderer, old_x, old_y, new_x, new_y);
    SDL_RenderDrawLine(renderer, old_x, old_y, old_u, old_v);
    SDL_RenderDrawLine(renderer, old_u, old_v, new_u, new_v);
    SDL_RenderDrawLine(renderer, new_x, new_y, new_u, new_v);
    
}
