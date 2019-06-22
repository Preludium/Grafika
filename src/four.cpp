#include "four.h"

four::four()
{
    parts.push_back(cube(3,12,4));
    parts.push_back(cube(4,12,4));
    parts.push_back(cube(4,13,4));
    parts.push_back(cube(4,13,5));
}

four::~four()
{
    //dtor
}


void four::RotL(cube (&cubemap)[9][12][9])
{
    //TBC
}


void four::RotR(cube (&cubemap)[9][12][9])
{
    //TBC
}
