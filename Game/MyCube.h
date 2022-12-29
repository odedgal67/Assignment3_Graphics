
#ifndef GAME_MYCUBE_H
#define GAME_MYCUBE_H


#include <vector>
#include "UnitCube.h"
#include "shape.h"

class MyCube {
    public:
        std::vector<UnitCube*> cubes;
        MyCube();
        float clockwise;
        float angle;

    void addCube(Shape *&pShape);

    void RotateRightWall();

    void updateUnitCube(int i, glm::vec3 pos);

    void RotateLeftWall();

    void RotateUpperWall();

    void RotateDownWall();

    void RotateFrontWall();

    void RotateBackWall();

    void flipClockwise();

    void Randomizer();

    void DivideAngle();

    void MultiplyAngle();
};


#endif //GAME_MYCUBE_H
