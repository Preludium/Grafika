#include "seven.h"

seven::seven()
{
    parts.push_back(cube(3,12,3));
    parts.push_back(cube(3,12,4));
    parts.push_back(cube(4,12,4));
    parts.push_back(cube(5,12,4));
    parts.push_back(cube(5,12,5));
}

seven::~seven()
{
    //dtor
}

void seven::RotL(cube (&cubemap)[9][12][9])
{
    //TBC
}


void seven::RotR(cube (&cubemap)[9][12][9])
{
    //TBC
}
