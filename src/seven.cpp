#include "seven.h"

seven::seven()
{
    parts.push_back(cube(3,12,3));
    parts.push_back(cube(3,12,4));
    parts.push_back(cube(4,12,4));
    parts.push_back(cube(5,12,4));
    parts.push_back(cube(5,12,5));
}

seven::~seven()
{
    //dtor
}

void seven::RotL(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:

        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z + 1;
        parts[4].x = parts[3].x - 1;
        parts[4].z = parts[3].z;

        parts[1].x = parts[2].x;
        parts[1].z = parts[2].z - 1;
        parts[0].x = parts[1].x + 1;
        parts[0].z = parts[1].z;

        this->state = 1;
        break;

    case 1:

        parts[3].x = parts[2].x + 1;
        parts[3].z = parts[2].z;
        parts[4].x = parts[3].x;
        parts[4].z = parts[3].z + 1;

        parts[1].x = parts[2].x - 1;
        parts[1].z = parts[2].z;
        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z - 1;


        this->state = 2;
        break;

    case 2:

        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z + 1;
        parts[4].x = parts[3].x - 1;
        parts[4].z = parts[3].z;

        parts[1].x = parts[2].x;
        parts[1].z = parts[2].z - 1;
        parts[0].x = parts[1].x + 1;
        parts[0].z = parts[1].z;

        this->state = 3;
        break;

    case 3:

        parts[3].x = parts[2].x + 1;
        parts[3].z = parts[2].z;
        parts[4].x = parts[3].x;
        parts[4].z = parts[3].z + 1;

        parts[1].x = parts[2].x - 1;
        parts[1].z = parts[2].z;
        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z - 1;


        this->state = 0;
        break;
    }
}


void seven::RotR(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:

        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z + 1;
        parts[4].x = parts[3].x - 1;
        parts[4].z = parts[3].z;

        parts[1].x = parts[2].x;
        parts[1].z = parts[2].z - 1;
        parts[0].x = parts[1].x + 1;
        parts[0].z = parts[1].z;

        this->state = 1;
        break;

    case 1:

        parts[3].x = parts[2].x + 1;
        parts[3].z = parts[2].z;
        parts[4].x = parts[3].x;
        parts[4].z = parts[3].z + 1;

        parts[1].x = parts[2].x - 1;
        parts[1].z = parts[2].z;
        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z - 1;


        this->state = 2;
        break;

    case 2:

        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z + 1;
        parts[4].x = parts[3].x - 1;
        parts[4].z = parts[3].z;

        parts[1].x = parts[2].x;
        parts[1].z = parts[2].z - 1;
        parts[0].x = parts[1].x + 1;
        parts[0].z = parts[1].z;

        this->state = 3;
        break;

    case 3:

        parts[3].x = parts[2].x + 1;
        parts[3].z = parts[2].z;
        parts[4].x = parts[3].x;
        parts[4].z = parts[3].z + 1;

        parts[1].x = parts[2].x - 1;
        parts[1].z = parts[2].z;
        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z - 1;


        this->state = 0;
        break;







    }
}
