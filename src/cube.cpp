#include "cube.h"

cube::cube(int x, int y, int z,  GLuint tex)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->texture = tex;
}

cube::cube()
{

}

void cube::decreaseY()
{
    this->y = this->y - 1;
}