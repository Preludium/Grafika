#include "two.h"

two::two()
{
    parts.push_back(cube(4,10,3));
    parts.push_back(cube(4,10,4));

    parts.push_back(cube(5,10,4));
    parts.push_back(cube(4,11,4));

}

two::~two()
{
    //dtor
}


void two::RotL(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:
        parts[2].x -= 2;
        this->state = 3;
        break;

    case 1:

        parts[0].z -= 2;
        this->state = 0;
        break;

    case 2:
        parts[2].x += 2;
        this->state = 1;
        break;

    case 3:
        parts[0].z += 2;
        this->state = 2;
        break;
    }
}


void two::RotR(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:

        parts[0].z += 2;
        this->state = 1;
        break;

    case 1:

        parts[2].x -= 2;
        this->state = 2;
        break;

    case 2:
        parts[0].z -= 2;
        this->state = 3;
        break;

    case 3:
        parts[2].x += 2;
        this->state = 0;
        break;
    }
}
