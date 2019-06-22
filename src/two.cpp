#include "two.h"

two::two()
{
    parts.push_back(cube(4,12,3));
    parts.push_back(cube(4,12,4));

    parts.push_back(cube(5,12,4));
    parts.push_back(cube(4,13,4));

}

two::~two()
{
    //dtor
}


void two::RotL(cube (&cubemap)[9][12][9])
{
    //TBC
}


void two::RotR(cube (&cubemap)[9][12][9])
{
    //TBC
}
