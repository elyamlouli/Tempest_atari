#include "Tube.h"
#include <SDL.h>


//Tube::Tube(Point* a_, Point* b_, Point* c_, Point* d_):a(a_), b(b_), c(c_), d(d_) {}

Tube::Tube(Point a_, Point b_, Point c_, Point d_):a(a_), b(b_), c(c_), d(d_) {}
Tube::Tube(int i)
{
    Point a;
    a.x = tubeQuads[i][0][0];
    a.y = tubeQuads[i][0][1];
    Point d;
    d.x = tubeQuads[i][1][0];
    d.y = tubeQuads[i][1][1];
    Point c;
    c.x = tubeQuads[i][2][0];
    c.y = tubeQuads[i][2][1];
    Point b;
    b.x = tubeQuads[i][3][0];
    b.y = tubeQuads[i][3][1];
}
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
