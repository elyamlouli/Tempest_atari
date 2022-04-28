#ifndef TUBE
#define TUBE

static const int Tube_Circles[2][17][2] = {
    {{256, 60}, {316, 73}, {368, 108}, {403, 160}, {416, 221}, {403, 281}, {368, 334}, {315, 368}, {256, 381}, {195, 368}, {143, 334}, {108, 281}, {95, 221}, {108, 160}, {143, 108}, {195, 73}, {256, 60}},
    {{256, 255}, {264, 257}, {273, 262}, {277, 270}, {280, 279}, {277, 289}, {273, 296}, {264, 301}, {256, 303}, {247, 301}, {238, 296}, {234, 289}, {231, 279}, {234, 270}, {238, 262}, {247, 257}, {256, 255}}};
static const int tubeQuads[16][4][2] = {
    {{256, 60}, {316, 73}, {264, 257}, {256, 255}},
    {{316, 73}, {368, 108}, {273, 262}, {264, 257}},
    {{368, 108}, {403, 160}, {277, 270}, {273, 262}},
    {{403, 160}, {416, 221}, {280, 279}, {277, 270}},
    {{416, 221}, {403, 281}, {277, 289}, {280, 279}},
    {{403, 281}, {368, 334}, {273, 296}, {277, 289}}, //
    {{368, 334}, {315, 368}, {264, 301}, {273, 296}}, //
    {{315, 368}, {256, 381}, {256, 303}, {264, 301}}, //x1>x2 et y1<y2
    {{256, 381}, {195, 368}, {247, 301}, {256, 303}},
    {{195, 368}, {143, 334}, {238, 296}, {247, 301}},
    {{143, 334}, {108, 281}, {234, 289}, {238, 296}},
    {{108, 281}, {95, 221}, {231, 279}, {234, 289}},
    {{95, 221}, {108, 160}, {234, 270}, {231, 279}},
    {{108, 160}, {143, 108}, {238, 262}, {234, 270}}, //x1<x2 et y1>y2
    {{143, 108}, {195, 73}, {247, 257}, {238, 262}},  //
    {{195, 73}, {256, 60}, {256, 255}, {247, 257}}    //

};

enum Forme
{
  Tube_Circle = 0
};
class Tube
{
public:
  int tube[2][17][2];
  int tube_quads[16][4][2];
  Forme forme;

  Tube(Forme f);
  ~Tube();
  void affect_tab(Forme f);
  void affect_quads(Forme f);
};

#endif