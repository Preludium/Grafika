#include "six.h"

six::six()
{
    this->points = 50;
    parts.push_back(cube(4,9,4));
    parts.push_back(cube(4,10,4));
    parts.push_back(cube(4,11,4));
    parts.push_back(cube(5,9,4));
    parts.push_back(cube(5,11,4));
}

six::~six()
{
    //dtor
}

int six::getPoints()
{
    return this->points;
}

void six::RotL(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:
        parts[3].x = parts[0].x;
        parts[3].z = parts[0].z - 1;
        parts[4].x = parts[2].x;
        parts[4].z = parts[2].z - 1;
        this->state = 3;
        break;

    case 1:

        parts[3].x = parts[0].x + 1;
        parts[3].z = parts[0].z;
        parts[4].x = parts[2].x + 1;
        parts[4].z = parts[2].z;
        this->state = 0;
        break;

    case 2:

        parts[3].x = parts[0].x;
        parts[3].z = parts[0].z + 1;
        parts[4].x = parts[2].x;
        parts[4].z = parts[2].z + 1;
        this->state = 1;
        break;

    case 3:
        parts[3].x = parts[0].x - 1;
        parts[3].z = parts[0].z;
        parts[4].x = parts[2].x - 1;
        parts[4].z = parts[2].z;
        this->state = 2;
        break;
    }
}


void six::RotR(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:

        parts[3].x = parts[0].x;
        parts[3].z = parts[0].z + 1;
        parts[4].x = parts[2].x;
        parts[4].z = parts[2].z + 1;
        this->state = 1;
        break;

    case 1:

        parts[3].x = parts[0].x - 1;
        parts[3].z = parts[0].z;
        parts[4].x = parts[2].x - 1;
        parts[4].z = parts[2].z;
        this->state = 2;
        break;

    case 2:

        parts[3].x = parts[0].x;
        parts[3].z = parts[0].z - 1;
        parts[4].x = parts[2].x;
        parts[4].z = parts[2].z - 1;
        this->state = 3;
        break;

    case 3:

        parts[3].x = parts[0].x + 1;
        parts[3].z = parts[0].z;
        parts[4].x = parts[2].x + 1;
        parts[4].z = parts[2].z;
        this->state = 0;
        break;
    }
}
