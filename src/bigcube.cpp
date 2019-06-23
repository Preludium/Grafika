#include "bigcube.h"

bigcube::bigcube()
{
   parts.push_back(cube(4,10,4));
   parts.push_back(cube(4,10,5));
   parts.push_back(cube(5,10,4));
   parts.push_back(cube(5,10,5));
   parts.push_back(cube(4,11,4));
   parts.push_back(cube(4,11,5));
   parts.push_back(cube(5,11,4));
   parts.push_back(cube(5,11,5));
}

bigcube::~bigcube()
{
    //dtor
}
void bigcube::RotL(cube (&cubemap)[9][12][9])
{
    //tu niczego sie nie spodziewamy
}


void bigcube::RotR(cube (&cubemap)[9][12][9])
{
    //tu niczego sie nie spodziewamy
}
