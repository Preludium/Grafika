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
    switch(state)
    {
    case 0:
        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z + 1;
        parts[3].x = parts[2].x + 1;
        parts[3].z = parts[2].z;
        this->state = 3;
        break;

    case 1:

        parts[0].x = parts[1].x - 1;
        parts[0].z = parts[1].z;
        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z + 1;
        this->state = 0;
        break;

    case 2:

        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z - 1;
        parts[3].x = parts[2].x - 1;
        parts[3].z = parts[2].z;
        this->state = 1;
        break;

    case 3:
        parts[0].x = parts[1].x + 1;
        parts[0].z = parts[1].z;
        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z - 1;
        this->state = 2;
        break;
    }
}


void four::RotR(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:

        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z - 1;
        parts[3].x = parts[2].x - 1;
        parts[3].z = parts[2].z;
        this->state = 1;
        break;

    case 1:

        parts[0].x = parts[1].x + 1;
        parts[0].z = parts[1].z;
        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z - 1;
        this->state = 2;
        break;

    case 2:

        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z + 1;
        parts[3].x = parts[2].x + 1;
        parts[3].z = parts[2].z;
        this->state = 3;
        break;

    case 3:

        parts[0].x = parts[1].x - 1;
        parts[0].z = parts[1].z;
        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z + 1;
        this->state = 0;
        break;
    }
}
