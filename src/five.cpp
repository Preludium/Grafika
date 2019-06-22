#include "five.h"

five::five()
{
    parts.push_back(cube(4,12,4));
    parts.push_back(cube(4,13,4));
    parts.push_back(cube(4,14,4));
    parts.push_back(cube(5,13,4));
}

five::~five()
{
    //dtor
}

void five::RotL(cube (&cubemap)[9][12][9])
{
    //TBC
}


void five::RotR(cube (&cubemap)[9][12][9])
{
    //TBC
}
