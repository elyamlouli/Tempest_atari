#ifndef BLASTER
#define BLASTER

#include <SDL.h>
#include <cassert>
#include <iostream>
#include <cmath>
#include <memory>


#include "utils.hpp"
#include "menu.hpp"
#include "tube.hpp"

#define NUM_BLASTER_POSITIONS 7
#define MAX_NUM_BULLETS 8

/**
 * @brief
 * Classe du vaisseau
 * Il est déplaçable en utilisant les touches du pavés numérique
 * Quand il est immobile, le vaisseau se trouve toujours lié à un couloir (tube)
 */

class Blaster
{

public:
  int targetPos;
  int changingXPos;
  std::shared_ptr<Utils>utils;

  Blaster();
  ~Blaster();

  void drawTubeQuads(SDL_Renderer *renderer, int x, int y, int coef);

  void drawblaster(SDL_Renderer *renderer, std::array<std::pair<int, int>, 4> tubeQuad, int x, int y, int coef, int rect);
  void drawblaster_bleu(SDL_Renderer *renderer, std::array<std::pair<int, int>, 4> tubeQuad, int x, int y, int coef, int rect);

  void move_r(SDL_Renderer *renderer, int i, std::array<std::array<std::pair<int, int>, 4>, 16> tubeQuads, int x, int y, int coef, int rect);
  void move_l(SDL_Renderer *renderer, int i, std::array<std::array<std::pair<int, int>, 4>, 16> tubeQuads, int x, int y, int coef, int rect);
};

#endif