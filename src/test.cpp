#include "test.h"

test::test()
{
    this->points = 10;
    // parts.push_back(cube(4,9,4));
    // parts.push_back(cube(4,10,4));
    // parts.push_back(cube(4,11,4));
    // parts.push_back(cube(5,10,4));
    for (int i = 1; i < 8; ++i)
    {
        for (int j = 1; j < 8; ++j)
        {
            parts.push_back(cube(i, 11, j));
        }
    }
}

test::~test()
{
    //dtor
}

int test::getPoints()
{
    return this->points;
}

void test::RotL(cube (&cubemap)[9][12][9])
{
    
}


void test::RotR(cube (&cubemap)[9][12][9])
{
    
}
