#include "five.h"

five::five()
{
    this->points = 40;
    parts.push_back(cube(4,9,4));
    parts.push_back(cube(4,10,4));
    parts.push_back(cube(4,11,4));
    parts.push_back(cube(5,10,4));
}

five::~five()
{
    //dtor
}

int five::getPoints()
{
    return this->points;
}

void five::RotL(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:
        parts[3].x = parts[1].x;
        parts[3].z = parts[1].z - 1;
        this->state = 3;
        break;

    case 1:

        parts[3].x = parts[1].x + 1;
        parts[3].z = parts[1].z;
        this->state = 0;
        break;

    case 2:

        parts[3].x = parts[1].x;
        parts[3].z = parts[1].z + 1;
        this->state = 1;
        break;

    case 3:
        parts[3].x = parts[1].x - 1;
        parts[3].z = parts[1].z;
        this->state = 2;
        break;
    }
}


void five::RotR(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:

        parts[3].x = parts[1].x;
        parts[3].z = parts[1].z + 1;
        this->state = 1;
        break;

    case 1:

        parts[3].x = parts[1].x - 1;
        parts[3].z = parts[1].z;
        this->state = 2;
        break;

    case 2:

        parts[3].x = parts[1].x;
        parts[3].z = parts[1].z - 1;
        this->state = 3;
        break;

    case 3:

        parts[3].x = parts[1].x + 1;
        parts[3].z = parts[1].z;
        this->state = 0;
        break;
    }
}
