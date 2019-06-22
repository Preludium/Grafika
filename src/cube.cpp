#include "cube.h"

cube::cube(int x, int y, int z,  unsigned int tex)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->texture = tex;
}


cube::cube(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}


cube::cube()
{

}
