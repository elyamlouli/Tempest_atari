#include "../include/tube.hpp"

Tube::Tube(Forme f) : forme(f)
{
}

Tube::~Tube()
{
}

void Tube::affect_quads(Forme f)
{
    if (f == 0)
    {
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                this->tube_quads[i][j].first = tubeQuads[i][j].first;
                this->tube_quads[i][j].second = tubeQuads[i][j].second;
            }
        }
    }
}
