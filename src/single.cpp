#include "single.h"

Single::Single()
{
    this->points = 10;
    parts.push_back(cube(4,11,4));
}

int Single::getPoints()
{
    return this->points;
}


void Single::RotL(cube (&cubemap)[9][12][9])
{
    //tu niczego sie nie spodziewamy
}


void Single::RotR(cube (&cubemap)[9][12][9])
{
    //tu niczego sie nie spodziewamy
}
