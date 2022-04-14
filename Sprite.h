#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

// un sprite est tout élément graphique qui peut se déplacer sur l'écran
struct SpriteInfo {
    int width;
    int height;
    SDL_Surface* Surface;
    SDL_Rect *Rect;
    ~SpriteInfo()
    {
        SDL_FreeSurface(Surface);
        delete[] Rect;
    }


};

struct TextureInfo {
    int width;
    int height;  
    SDL_Surface* Surface;
    


};

#endif