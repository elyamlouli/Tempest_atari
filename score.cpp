#include "score.hpp"

Score::Score()
{
    nbLives = 4;
    score = 0;
}

Score::~Score()
{
}

int Score::get_nbLives()
{
    return nbLives;
}
int Score::get_score()
{
    return score;
}
void Score::set_score(int s)
{
    this->score = s;
}

void Score::draw_live(SDL_Renderer *renderer, int coef, int x, int y)
{
    SDL_SetRenderDrawColor(renderer, 255, 250, 42, 0);
    int i;
    for (i = 0; i < coords.size() - 1; i++)
    {
        SDL_RenderDrawLine(renderer, coords[i][0] * coef + x, coords[i][1] * coef + y, coords[i + 1][0] * coef + x, coords[i + 1][1] * coef + y);
    }
    SDL_RenderDrawLine(renderer, coords[i][0] * coef + x, coords[i][1] * coef + y, coords[0][0] * coef + x, coords[0][1] * coef + y);
}

void Score::draw_score(std::string str, int start_x, int start_y, int coeff)
{
    SDL_SetRenderDrawColor(renderer, 54, 244, 11, 0);
    menu->hershey(renderer, str, start_x, start_y, coeff);
}