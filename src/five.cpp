#include "five.h"

five::five()
{
    this->points = 40;
    parts.push_back(cube(4,12,4));
    parts.push_back(cube(4,13,4));
    parts.push_back(cube(4,14,4));
    parts.push_back(cube(5,13,4));
}

five::~five()
{
    //dtor
}

int five::getPoints()
{
    return this->points;
}

void five::RotL(cube (&cubemap)[9][15][9])
{
    switch(state)
    {
    case 0:

        if(cubemap[parts[3].x][parts[3].y][parts[3].z-1].exists || cubemap[parts[3].x-1][parts[3].y][parts[3].z-1].exists ||
           parts[3].z-1 == 0){
           return;
           }
        parts[3].x = parts[1].x;
        parts[3].z = parts[1].z - 1;
        this->state = 3;
        break;

    case 1:

        if(cubemap[parts[3].x+1][parts[3].y][parts[3].z].exists || cubemap[parts[3].x+1][parts[3].y][parts[3].z-1].exists||
           parts[3].x+1 == 8){
           return;
           }
        parts[3].x = parts[1].x + 1;
        parts[3].z = parts[1].z;
        this->state = 0;
        break;

    case 2:

        if(cubemap[parts[3].x][parts[3].y][parts[3].z+1].exists || cubemap[parts[3].x+1][parts[3].y][parts[3].z+1].exists ||
           parts[3].z+1 == 8){
           return;
           }
        parts[3].x = parts[1].x;
        parts[3].z = parts[1].z + 1;
        this->state = 1;
        break;

    case 3:

        if(cubemap[parts[3].x-1][parts[3].y][parts[3].z].exists || cubemap[parts[3].x-1][parts[3].y][parts[3].z+1].exists||
           parts[3].x-1 == 0){
           return;
           }
        parts[3].x = parts[1].x - 1;
        parts[3].z = parts[1].z;
        this->state = 2;
        break;
    }
}


void five::RotR(cube (&cubemap)[9][15][9])
{
    switch(state)
    {
    case 0:

        if(cubemap[parts[3].x][parts[3].y][parts[3].z+1].exists || cubemap[parts[3].x-1][parts[3].y][parts[3].z+1].exists ||
           parts[3].z + 1 == 8){
           return;
           }
        parts[3].x = parts[1].x;
        parts[3].z = parts[1].z + 1;
        this->state = 1;
        break;

    case 1:

        if(cubemap[parts[3].x-1][parts[3].y][parts[3].z].exists || cubemap[parts[3].x-1][parts[3].y][parts[3].z-1].exists ||
           parts[3].x-1 == 0){
           return;
           }
        parts[3].x = parts[1].x - 1;
        parts[3].z = parts[1].z;
        this->state = 2;
        break;

    case 2:

        if(cubemap[parts[3].x][parts[3].y][parts[3].z-1].exists || cubemap[parts[3].x+1][parts[3].y][parts[3].z-1].exists ||
           parts[3].z -1 == 0){
           return;
           }
        parts[3].x = parts[1].x;
        parts[3].z = parts[1].z - 1;
        this->state = 3;
        break;

    case 3:

        if(cubemap[parts[3].x+1][parts[3].y][parts[3].z].exists || cubemap[parts[3].x+1][parts[3].y][parts[3].z+1].exists ||
           parts[3].x+1 == 8){
           return;
           }
        parts[3].x = parts[1].x + 1;
        parts[3].z = parts[1].z;
        this->state = 0;
        break;
    }
}
