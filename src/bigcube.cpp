#include "bigcube.h"

bigcube::bigcube()
{
    this->points = 80;
    parts.push_back(cube(4,12,4));
    parts.push_back(cube(4,12,5));
    parts.push_back(cube(5,12,4));
    parts.push_back(cube(5,12,5));
    parts.push_back(cube(4,13,4));
    parts.push_back(cube(4,13,5));
    parts.push_back(cube(5,13,4));
    parts.push_back(cube(5,13,5));
}

int bigcube::getPoints()
{
    return this->points;
}

bigcube::~bigcube()
{
    //dtor
}
void bigcube::RotL(cube (&cubemap)[9][15][9])
{
    //tu niczego sie nie spodziewamy
}


void bigcube::RotR(cube (&cubemap)[9][15][9])
{
    //tu niczego sie nie spodziewamy
}
