
#include "MyCube.h"
#define M_PI           3.14159265358979323846
MyCube::MyCube()
{
    this->clockwise = 1;
}

void MyCube::addCube(Shape *&pShape)
{
    cubes.push_back(dynamic_cast<UnitCube*>(pShape));
}

void MyCube::RotateRightWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->x == 1)  // 1 is the x-coordinate of the right wall
        {
            int newY = cube->z*clockwise;
            int newZ = -cube->y*clockwise;
            cube->MyTranslate(glm::vec3(0, (newY-cube->y), (newZ-cube->z)),0);
            cube->MyRotate(-90*clockwise, glm::vec3(1,0,0), 0);
            cube->y = newY;
            cube->z = newZ;
        }
    }
}

void MyCube::RotateLeftWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->x == -1)  // -1 is the x-coordinate of the left wall
        {
            int newY = cube->z*clockwise;
            int newZ = -cube->y*clockwise;
            cube->MyTranslate(glm::vec3(0, (newY-cube->y), (newZ-cube->z)),0);
            cube->MyRotate(-90*clockwise, glm::vec3(1,0,0), 0);
            cube->y = newY;
            cube->z = newZ;
        }
    }
}

void MyCube::updateUnitCube(int index, glm::vec3 pos) {
    cubes[index]->updateCube(pos);

}

void MyCube::RotateUpperWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->y == 1)  // -1 is the x-coordinate of the left wall
        {
            int newX = -cube->z*clockwise;
            int newZ = cube->x*clockwise;
            cube->MyTranslate(glm::vec3((newX-cube->x),0 , (newZ-cube->z)),0);
            cube->MyRotate(-90*clockwise, glm::vec3(0,1,0), 0);
            cube->x = newX;
            cube->z = newZ;
        }
    }
}

void MyCube::RotateDownWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->y == -1)  // -1 is the x-coordinate of the left wall
        {
            int newX = -cube->z*clockwise;
            int newZ = cube->x*clockwise;
            cube->MyTranslate(glm::vec3((newX-cube->x),0 , (newZ-cube->z)),0);
            cube->MyRotate(-90*clockwise, glm::vec3(0,1,0), 0);
            cube->x = newX;
            cube->z = newZ;
        }
    }
}

void MyCube::RotateFrontWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->z == 1)  // -1 is the x-coordinate of the left wall
        {
            int newX = cube->y*clockwise;
            int newY = -cube->x*clockwise;
            cube->MyTranslate(glm::vec3((newX-cube->x),(newY-cube->y) , 0),0);
            cube->MyRotate(-90*clockwise, glm::vec3(0,0,1), 0);
            cube->x = newX;
            cube->y = newY;
        }
    }
}

void MyCube::RotateBackWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->z == -1)  // -1 is the x-coordinate of the left wall
        {
            int newX = cube->y*clockwise;
            int newY = -cube->x*clockwise;
            cube->MyTranslate(glm::vec3((newX-cube->x),(newY-cube->y) , 0),0);
            cube->MyRotate(-90*clockwise, glm::vec3(0,0,1), 0);
            cube->x = newX;
            cube->y = newY;
        }
    }
}

void MyCube::flipClockwise() {
    this->clockwise = -1*clockwise;
}
