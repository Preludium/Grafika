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


void four::RotL()
{
    //TBC
}


void four::RotR()
{
    //TBC
}
