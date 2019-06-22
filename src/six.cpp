#include "six.h"

six::six()
{
    parts.push_back(cube(4,12,4));
    parts.push_back(cube(4,13,4));
    parts.push_back(cube(4,14,4));
    parts.push_back(cube(5,12,4));
    parts.push_back(cube(5,14,4));
}

six::~six()
{
    //dtor
}


void six::RotL(cube (&cubemap)[9][12][9])
{
    //TBC
}


void six::RotR(cube (&cubemap)[9][12][9])
{
    //TBC
}
