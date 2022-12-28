
#ifndef GAME_UNITCUBE_H
#define GAME_UNITCUBE_H
#include "shape.h"


class UnitCube : public Shape
{
public:
    int x;
    int y;
    int z;

    void updateCube(glm::vec3 pos);
    UnitCube(int type, int mode);
};


#endif //GAME_UNITCUBE_H
