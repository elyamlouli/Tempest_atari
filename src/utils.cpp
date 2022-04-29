#include "../include/utils.hpp"

Utils::Utils()
{
    this->time = 0;
}
Utils::~Utils()
{
}
double Utils::get_time()
{
    return time;
}

void Utils::set_time(int t)
{
    time = t;
}
float Utils::distance(int vec1[2], int vec2[2])
{
    const int x1 = vec1[0];
    const int y1 = vec1[1];
    const int x2 = vec2[0];
    const int y2 = vec2[1];
    return sqrt(((y2 - y1) * (y2 - y1)) + ((x2 - x1) * (x2 - x1)));
}
float Utils::distance(int x1, int y1, int x2, int y2)
{
    return sqrt(((y2 - y1) * (y2 - y1)) + ((x2 - x1) * (x2 - x1)));
}

std::vector<float> Utils::mid_two_points(int x1, int y1, int x2, int y2)
{
    float x = (static_cast<float>(x1) + static_cast<float>(x2)) / 2;
    float y = (static_cast<float>(y1) + static_cast<float>(y2)) / 2;
    std::vector<float> vec = {};
    vec.push_back(x);
    vec.push_back(y);
    return vec;
}

std::pair<double, double> Utils::find_position(std::array<std::pair<int, int>, 4> tubeQuad, int ax, int ay, int scale, float profondeur)
{
    std::pair<double, double> D;
    double new_ax, new_ay;
    int window_x;
    int window_y;
    if (tubeQuad[0].first < tubeQuad[1].first && tubeQuad[0].second < tubeQuad[1].second)
    {
        window_x = 523;
        window_y = 563;
    }
    else if (tubeQuad[0].first > tubeQuad[1].first && tubeQuad[0].second < tubeQuad[1].second)
    {
        window_x = 517;
        window_y = 570;
    }
    else if (tubeQuad[0].first < tubeQuad[1].first && tubeQuad[0].second > tubeQuad[1].second)
    {
        window_x = 512;
        window_y = 558;
    }
    else
    {
        window_x = 520;
        window_y = 570;
    }

    int ABx = tubeQuad[1].first * scale - tubeQuad[0].first * scale;
    int ABy = tubeQuad[1].second * scale - tubeQuad[0].second * scale;
    double normAB = sqrt(ABx * ABx + ABy * ABy);
    double ux = ABx / normAB;
    double uy = ABy / normAB;

    new_ax = (ux * ax - uy * ay + (tubeQuad[0].first + tubeQuad[1].first) * scale / 2 - window_x) * profondeur + window_x;
    new_ay = (uy * ax + ux * ay + (tubeQuad[0].second + tubeQuad[1].second) * scale / 2 - window_y) * profondeur + window_y;
    D.first = new_ax;
    D.second = new_ay;
    return D;
}

std::pair<double, double> UtilsEnemy::find_position(std::array<std::pair<int, int>, 4> tubeQuad, int ax, int ay, int scale, float profondeur)
{
    std::pair<double, double> D;
    double new_ax, new_ay;
    std::vector<float> vec = this->mid_two_points(tubeQuad[0].first * scale, tubeQuad[0].second * scale, tubeQuad[1].first * scale, tubeQuad[1].second * scale);
    int CDx = tubeQuad[3].first * scale - tubeQuad[2].first * scale;
    int CDy = tubeQuad[3].second * scale - tubeQuad[2].second * scale;
    double normCD = sqrt(CDx * CDx + CDy * CDy);
    double ux = CDx / normCD;
    double uy = CDy / normCD;

    new_ax = (uy * ax - ux * ay + (tubeQuad[2].first + tubeQuad[3].first) * scale / 2 - vec[0]) * profondeur + vec[0];
    new_ay = (ux * ax + uy * ay + (tubeQuad[2].second + tubeQuad[3].second) * scale / 2 - vec[1]) * profondeur + vec[1];

    D.first = new_ax;
    D.second = new_ay;
    return D;
}
UtilsEnemy::UtilsEnemy()
{
}
UtilsEnemy::~UtilsEnemy()
{
}
