#include "two.h"

two::two()
{
    this->points = 40;
    parts.push_back(cube(4,12,3));
    parts.push_back(cube(4,12,4));

    parts.push_back(cube(5,12,4));
    parts.push_back(cube(4,13,4));

}

two::~two()
{
    //dtor
}

int two::getPoints()
{
    return this->points;
}

void two::RotL(cube (&cubemap)[9][15][9])
{
    switch(state)
    {
    case 0:
        if(cubemap[parts[2].x ][parts[2].y][parts[2].z].exists || cubemap[parts[0].x-1][parts[0].y][parts[0].z ].exists
           || cubemap[parts[2].x-1][parts[2].y][parts[2].z+1].exists || parts[0].x -1 == 0){
           return;
           }

        parts[2].x -= 2;
        this->state = 3;
        break;

    case 1:
        if(cubemap[parts[0].x+1][parts[0].y][parts[0].z].exists || cubemap[parts[2].x][parts[2].y][parts[2].z-1].exists
           || cubemap[parts[2].x-1][parts[2].y][parts[2].z-1].exists || parts[2].z - 1 == 0){
           return;
           }
        parts[0].z -= 2;
        this->state = 0;
        break;

    case 2:
        if(cubemap[parts[0].x+1][parts[0].y][parts[0].z].exists || cubemap[parts[2].x][parts[2].y][parts[2].z+1].exists
           || cubemap[parts[0].x+1][parts[0].y][parts[0].z-1].exists || parts[0].x+1 == 8){
           return;
           }

        parts[2].x += 2;
        this->state = 1;
        break;

    case 3:
        if(cubemap[parts[0].x -1][parts[0].y][parts[0].z].exists || cubemap[parts[2].x][parts[2].y][parts[2].z +1].exists
           || cubemap[parts[2].x+1][parts[2].y][parts[2].z+1].exists || parts[2].z+1 == 8){
           return;
           }

        parts[0].z += 2;
        this->state = 2;
        break;
    }
}


void two::RotR(cube (&cubemap)[9][15][9])
{
    switch(state)
    {
    case 0:

        if(cubemap[parts[0].x + 1][parts[0].y][parts[0].z].exists || cubemap[parts[2].x][parts[2].y][parts[2].z + 1].exists
           || cubemap[parts[2].x-1][parts[2].y][parts[2].z+1].exists || parts[2].z+1 == 8){
           return;
           }
        parts[0].z += 2;
        this->state = 1;
        break;

    case 1:

        if(cubemap[parts[2].x ][parts[2].y][parts[2].z +1].exists || cubemap[parts[0].x-1][parts[0].y][parts[0].z ].exists
           || cubemap[parts[0].x-1][parts[2].y][parts[2].z-1].exists || parts[0].x-1 == 0){
           return;
           }

        parts[2].x -= 2;
        this->state = 2;
        break;

    case 2:
        if(cubemap[parts[0].x - 1][parts[0].y][parts[0].z].exists || cubemap[parts[2].x][parts[2].y][parts[2].z - 1].exists
           || cubemap[parts[2].x+1][parts[2].y][parts[2].z-1].exists || parts[2].z-1 == 0){
           return;
           }

        parts[0].z -= 2;
        this->state = 3;
        break;

    case 3:
        if(cubemap[parts[2].x ][parts[2].y][parts[2].z - 1].exists || cubemap[parts[0].x+1][parts[0].y][parts[0].z ].exists
           || cubemap[parts[0].x+1][parts[2].y][parts[2].z+1].exists || parts[0].x+1 == 8){
           return;
           }

        parts[2].x += 2;
        this->state = 0;
        break;
    }
}
