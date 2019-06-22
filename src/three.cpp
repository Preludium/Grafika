#include "three.h"

three::three()
{
    parts.push_back(cube(3,12,4));
    parts.push_back(cube(4,12,4));
    parts.push_back(cube(4,13,4));
    parts.push_back(cube(5,13,4));
}

three::~three()
{
    //dtor
}

void three::RotL()
{
    //TBC
}


void three::RotR()
{
    //TBC
}
