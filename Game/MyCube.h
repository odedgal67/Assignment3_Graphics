
#ifndef GAME_MYCUBE_H
#define GAME_MYCUBE_H


#include <vector>
#include "UnitCube.h"
#include "shape.h"

class MyCube {
    public:
        std::vector<UnitCube*> cubes;
        MyCube();
        int clockwise;

    void addCube(Shape *&pShape);

    void RotateRightWall();

    void updateUnitCube(int i, glm::vec3 pos);

    void RotateLeftWall();

    void RotateUpperWall();

    void RotateDownWall();

    void RotateFrontWall();

    void RotateBackWall();

    void flipClockwise();
};


#endif //GAME_MYCUBE_H
