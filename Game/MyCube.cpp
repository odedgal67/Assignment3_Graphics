
#include "MyCube.h"
#include "glm/gtc/matrix_transform.inl"
#include <random>
#include <unistd.h>

MyCube::MyCube()
{
    this->clockwise = 1.0f;
    this->angle = -90.0f;
}

void MyCube::addCube(Shape *&pShape)
{
    cubes.push_back(dynamic_cast<UnitCube*>(pShape));
}

void MyCube::RotateRightWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->x <= 1.008 && cube->x >= 0.992)  // 1 is the x-coordinate of the right wall
        {
            float delta_degree = angle*clockwise;
            glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), delta_degree, glm::vec3(1.0f,0.0f,0.0f));
            glm::vec3 newPos = glm::vec3(rotationMatrix * glm::vec4(cube->x, cube->y, cube->z, 1.0f));
            glm::vec3 originalCubePos = glm::vec3(cube->x, cube->y, cube->z);
            newPos.x = 1.0f;

            glm::vec3 translationVector = newPos-originalCubePos;
            cube->MyTranslate(translationVector,0);
            cube->MyRotate(delta_degree, glm::vec3(1.0f,0.0f,0.0f), 0);
            cube->updateCube(newPos);
        }
    }
}

void MyCube::RotateLeftWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->x >= -1.008 && cube->x <= -0.992)  // 1 is the x-coordinate of the right wall
        {
            float delta_degree = angle*clockwise;
            glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), delta_degree, glm::vec3(1.0f,0.0f,0.0f));
            glm::vec3 newPos = glm::vec3(rotationMatrix * glm::vec4(cube->x, cube->y, cube->z, 1.0f));
            glm::vec3 originalCubePos = glm::vec3(cube->x, cube->y, cube->z);
            newPos.x = -1.0f;

            glm::vec3 translationVector = newPos-originalCubePos;
            cube->MyTranslate(translationVector,0);
            cube->MyRotate(delta_degree, glm::vec3(1.0f,0.0f,0.0f), 0);
            cube->updateCube(newPos);
        }
    }
}

void MyCube::updateUnitCube(int index, glm::vec3 pos) {
    cubes[index]->updateCube(pos);

}

void MyCube::RotateUpperWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->y <= 1.008 && cube->y >= 0.992)  // 1 is the x-coordinate of the right wall
        {
            float delta_degree = angle*clockwise;
            glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), delta_degree, glm::vec3(0.0f,1.0f,0.0f));
            glm::vec3 newPos = glm::vec3(rotationMatrix * glm::vec4(cube->x, cube->y, cube->z, 1.0f));
            glm::vec3 originalCubePos = glm::vec3(cube->x, cube->y, cube->z);
            newPos.y = 1.0f;

            glm::vec3 translationVector = newPos-originalCubePos;
            cube->MyTranslate(translationVector,0);
            cube->MyRotate(delta_degree, glm::vec3(0.0f,1.0f,0.0f), 0);
            cube->updateCube(newPos);
        }
    }
}

void MyCube::RotateDownWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->y >= -1.008 && cube->y <= -0.992)  // 1 is the x-coordinate of the right wall
        {
            float delta_degree = angle*clockwise;
            glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), delta_degree, glm::vec3(0.0f,1.0f,0.0f));
            glm::vec3 newPos = glm::vec3(rotationMatrix * glm::vec4(cube->x, cube->y, cube->z, 1.0f));
            glm::vec3 originalCubePos = glm::vec3(cube->x, cube->y, cube->z);
            newPos.y = -1.0f;
            glm::vec3 translationVector = newPos-originalCubePos;
            cube->MyTranslate(translationVector,0);
            cube->MyRotate(delta_degree, glm::vec3(0.0f,1.0f,0.0f), 0);
            cube->updateCube(newPos);
        }
    }
}

void MyCube::RotateFrontWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->z <= 1.008 && cube->z >= 0.992)  // 1 is the x-coordinate of the right wall
        {
            float delta_degree = angle*clockwise;
            glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), delta_degree, glm::vec3(0.0f,0.0f,1.0f));
            glm::vec3 newPos = glm::vec3(rotationMatrix * glm::vec4(cube->x, cube->y, cube->z, 1.0f));
            glm::vec3 originalCubePos = glm::vec3(cube->x, cube->y, cube->z);
            newPos.z = 1.0f;
            glm::vec3 translationVector = newPos-originalCubePos;
            cube->MyTranslate(translationVector,0);
            cube->MyRotate(delta_degree, glm::vec3(0.0f,0.0f,1.0f), 0);
            cube->updateCube(newPos);
        }
    }
}

void MyCube::RotateBackWall() {
    for(UnitCube* cube : cubes)
    {
        if (cube->z >= -1.008 && cube->z <= -0.992)  // 1 is the x-coordinate of the right wall
        {
            float delta_degree = angle*clockwise;
            glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), delta_degree, glm::vec3(0.0f,0.0f,1.0f));
            glm::vec3 newPos = glm::vec3(rotationMatrix * glm::vec4(cube->x, cube->y, cube->z, 1.0f));
            glm::vec3 originalCubePos = glm::vec3(cube->x, cube->y, cube->z);
            newPos.z = -1.0f;

            glm::vec3 translationVector = newPos-originalCubePos;
            cube->MyTranslate(translationVector,0);
            cube->MyRotate(delta_degree, glm::vec3(0.0f,0.0f,1.0f), 0);
            cube->updateCube(newPos);
        }
    }
}



void MyCube::flipClockwise() {
    this->clockwise = -1.0f*clockwise;
}

void MyCube::Randomizer() {
    for(int i=0; i<100; i++)
    {
        // Create a random number generator
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> dis(1, 6);

        // Choose a random number between 1 and 6
        int option = dis(gen);

        //Choose random rotation
        switch (option)
        {
            case 1:
                RotateRightWall();
                break;
            case 2:
                RotateLeftWall();
                break;
            case 3:
                RotateUpperWall();
                break;
            case 4:
                RotateDownWall();
                break;
            case 5:
                RotateFrontWall();
                break;
            case 6:
                RotateBackWall();
                break;
        }
    }


}

void MyCube::DivideAngle() {
    this->angle = -1.0f*std::fmax(-1.0f*this->angle/2.0f, 1.0f);
}

void MyCube::MultiplyAngle() {
    this->angle = -1.0f*std::fmin(-1.0f*this->angle*2.0f, 180.0f);
}
