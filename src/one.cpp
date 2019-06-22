#include "one.h"

one::one()
{
   parts.push_back(cube(4,12,4));
   parts.push_back(cube(4,13,4));

   parts.push_back(cube(5,13,4));
   parts.push_back(cube(5,14,4));

}

one::~one()
{
    //dtor
}
void one::RotL(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:

            parts[2].x = parts[1].x ;
            parts[2].z = parts[1].z - 1;
            parts[3].x = parts[2].x;
            parts[3].z = parts[2].z;



        this->state = 3;
        break;

    case 1:

            parts[2].x = parts[1].x +1;
            parts[2].z = parts[1].z ;
            parts[3].x = parts[2].x;
            parts[3].z = parts[2].z;


        this->state = 0;
        break;

    case 2:

            parts[2].x = parts[1].x ;
            parts[2].z = parts[1].z + 1;
            parts[3].x = parts[2].x;
            parts[3].z = parts[2].z;

        this->state = 1;
        break;

    case 3:

            parts[2].x = parts[1].x -1;
            parts[2].z = parts[1].z ;
            parts[3].x = parts[2].x;
            parts[3].z = parts[2].z;


        this->state = 2;
        break;
    }
}


void one::RotR(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:

            parts[2].x = parts[1].x ;
            parts[2].z = parts[1].z + 1;
            parts[3].x = parts[2].x;
            parts[3].z = parts[2].z;



        this->state = 1;
        break;

    case 1:

            parts[2].x = parts[1].x -1;
            parts[2].z = parts[1].z ;
            parts[3].x = parts[2].x;
            parts[3].z = parts[2].z;


        this->state = 2;
        break;

    case 2:

            parts[2].x = parts[1].x ;
            parts[2].z = parts[1].z - 1;
            parts[3].x = parts[2].x;
            parts[3].z = parts[2].z;

        this->state = 3;
        break;

    case 3:

            parts[2].x = parts[1].x +1;
            parts[2].z = parts[1].z ;
            parts[3].x = parts[2].x;
            parts[3].z = parts[2].z;


        this->state = 0;
        break;
    }
}
