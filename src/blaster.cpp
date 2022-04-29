#include "../include/blaster.hpp"

Blaster::Blaster()
{

    utils = std::shared_ptr<Utils>(new Utils());
}
Blaster::~Blaster()
{
}

void Blaster::drawTubeQuads(SDL_Renderer *renderer, int x, int y, int coef)
{
    std::array<std::pair<int, int>, 4> tubeQuad;
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            tubeQuad[j].first = tubeQuads[i][j].first;
            tubeQuad[j].second = tubeQuads[i][j].second;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef, (x + tubeQuad[2].first) * coef, (y + tubeQuad[2].second) * coef);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[2].first) * coef, (y + tubeQuad[2].second) * coef, (x + tubeQuad[3].first) * coef, (y + tubeQuad[3].second) * coef);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[3].first) * coef, (y + tubeQuad[3].second) * coef, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef);
    }
}
void Blaster::drawblaster(SDL_Renderer *renderer, std::array<std::pair<int, int>, 4> tubeQuad, int x, int y, int coef, int rect)
{

    if (tubeQuad[0].second < tubeQuad[1].second && tubeQuad[0].first < tubeQuad[1].first)
    {
        int x1 = tubeQuad[0].first + rect;
        int y1 = tubeQuad[0].second - rect;
        int x2 = tubeQuad[1].first + rect;
        int y2 = tubeQuad[1].second - rect;
        SDL_SetRenderDrawColor(renderer, 255, 250, 42, 0);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + x1) * coef, (y + y1) * coef);
        SDL_RenderDrawLine(renderer, (x + x1) * coef, (y + y1) * coef, (x + x2) * coef, (y + y2) * coef);
        SDL_RenderDrawLine(renderer, (x + x2) * coef, (y + y2) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
    }
    else if (tubeQuad[0].first > tubeQuad[1].first && tubeQuad[0].second > tubeQuad[1].second)
    {

        int x1 = tubeQuad[0].first - rect;
        int y1 = tubeQuad[0].second + rect;
        int x2 = tubeQuad[1].first - rect;
        int y2 = tubeQuad[1].second + rect;
        SDL_SetRenderDrawColor(renderer, 255, 250, 42, 0);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + x1) * coef, (y + y1) * coef);
        SDL_RenderDrawLine(renderer, (x + x1) * coef, (y + y1) * coef, (x + x2) * coef, (y + y2) * coef);
        SDL_RenderDrawLine(renderer, (x + x2) * coef, (y + y2) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
    }

    else if (tubeQuad[0].first > tubeQuad[1].first)
    {

        int x1 = tubeQuad[0].first + rect;
        int y1 = tubeQuad[0].second + rect;
        int x2 = tubeQuad[1].first + rect;
        int y2 = tubeQuad[1].second + rect;
        SDL_SetRenderDrawColor(renderer, 255, 250, 42, 0);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + x1) * coef, (y + y1) * coef);
        SDL_RenderDrawLine(renderer, (x + x1) * coef, (y + y1) * coef, (x + x2) * coef, (y + y2) * coef);
        SDL_RenderDrawLine(renderer, (x + x2) * coef, (y + y2) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
    }
    else
    {

        int x1 = tubeQuad[0].first - rect;
        int y1 = tubeQuad[0].second - rect;
        int x2 = tubeQuad[1].first - rect;
        int y2 = tubeQuad[1].second - rect;
        SDL_SetRenderDrawColor(renderer, 255, 250, 42, 0);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + x1) * coef, (y + y1) * coef);
        SDL_RenderDrawLine(renderer, (x + x1) * coef, (y + y1) * coef, (x + x2) * coef, (y + y2) * coef);
        SDL_RenderDrawLine(renderer, (x + x2) * coef, (y + y2) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
    }
    SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + tubeQuad[3].first) * coef, (y + tubeQuad[3].second) * coef);
    SDL_RenderDrawLine(renderer, (x + tubeQuad[3].first) * coef, (y + tubeQuad[3].second) * coef, (x + tubeQuad[2].first) * coef, (y + tubeQuad[2].second) * coef);
    SDL_RenderDrawLine(renderer, (x + tubeQuad[2].first) * coef, (y + tubeQuad[2].second) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first * coef), (y + tubeQuad[0].second) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
    SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first * coef), (y + tubeQuad[0].second) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
}
void Blaster::drawblaster_bleu(SDL_Renderer *renderer, std::array<std::pair<int, int>, 4> tubeQuad, int x, int y, int coef, int rect)
{
    if (tubeQuad[0].second < tubeQuad[1].second && tubeQuad[0].first < tubeQuad[1].first)
    {
        int x1 = tubeQuad[0].first + rect;
        int y1 = tubeQuad[0].second - rect;
        int x2 = tubeQuad[1].first + rect;
        int y2 = tubeQuad[1].second - rect;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + x1) * coef, (y + y1) * coef);
        SDL_RenderDrawLine(renderer, (x + x1) * coef, (y + y1) * coef, (x + x2) * coef, (y + y2) * coef);
        SDL_RenderDrawLine(renderer, (x + x2) * coef, (y + y2) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
    }
    else if (tubeQuad[0].first > tubeQuad[1].first && tubeQuad[0].second > tubeQuad[1].second)
    {

        int x1 = tubeQuad[0].first - rect;
        int y1 = tubeQuad[0].second + rect;
        int x2 = tubeQuad[1].first - rect;
        int y2 = tubeQuad[1].second + rect;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + x1) * coef, (y + y1) * coef);
        SDL_RenderDrawLine(renderer, (x + x1) * coef, (y + y1) * coef, (x + x2) * coef, (y + y2) * coef);
        SDL_RenderDrawLine(renderer, (x + x2) * coef, (y + y2) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
    }

    else if (tubeQuad[0].first > tubeQuad[1].first)
    {

        int x1 = tubeQuad[0].first + rect;
        int y1 = tubeQuad[0].second + rect;
        int x2 = tubeQuad[1].first + rect;
        int y2 = tubeQuad[1].second + rect;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + x1) * coef, (y + y1) * coef);
        SDL_RenderDrawLine(renderer, (x + x1) * coef, (y + y1) * coef, (x + x2) * coef, (y + y2) * coef);
        SDL_RenderDrawLine(renderer, (x + x2) * coef, (y + y2) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
    }
    else
    {

        int x1 = tubeQuad[0].first - rect;
        int y1 = tubeQuad[0].second - rect;
        int x2 = tubeQuad[1].first - rect;
        int y2 = tubeQuad[1].second - rect;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + x1) * coef, (y + y1) * coef);
        SDL_RenderDrawLine(renderer, (x + x1) * coef, (y + y1) * coef, (x + x2) * coef, (y + y2) * coef);
        SDL_RenderDrawLine(renderer, (x + x2) * coef, (y + y2) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
    SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + tubeQuad[3].first) * coef, (y + tubeQuad[3].second) * coef);
    SDL_RenderDrawLine(renderer, (x + tubeQuad[3].first) * coef, (y + tubeQuad[3].second) * coef, (x + tubeQuad[2].first) * coef, (y + tubeQuad[2].second) * coef);
    SDL_RenderDrawLine(renderer, (x + tubeQuad[2].first) * coef, (y + tubeQuad[2].second) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
    SDL_RenderDrawLine(renderer, (x + tubeQuad[0].first) * coef, (y + tubeQuad[0].second) * coef, (x + tubeQuad[1].first) * coef, (y + tubeQuad[1].second) * coef);
}

void Blaster::move_r(SDL_Renderer *renderer, int i, std::array<std::array<std::pair<int, int>, 4>, 16> tubeQuads, int x, int y, int coef, int rect)
{

    if (i == 0)
    {
        this->drawblaster_bleu(renderer, tubeQuads[15], x, y, coef, rect);
    }
    else
    {
        this->drawblaster(renderer, tubeQuads[i], x, y, coef, rect);
    }
}

void Blaster::move_l(SDL_Renderer *renderer, int i, std::array<std::array<std::pair<int, int>, 4>, 16> tubeQuads, int x, int y, int coef, int rect)
{

    if (i == 15)
    {

        this->drawblaster_bleu(renderer, tubeQuads[0], x, y, coef, rect);
    }
    else
    {
        this->drawblaster_bleu(renderer, tubeQuads[i + 1], x, y, coef, rect);
    }

    this->drawblaster(renderer, tubeQuads[i], x, y, coef, rect);
}
