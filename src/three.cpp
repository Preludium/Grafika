#include "three.h"

three::three()
{
    this->points = 40;
    parts.push_back(cube(3,10,4));
    parts.push_back(cube(4,10,4));
    parts.push_back(cube(4,11,4));
    parts.push_back(cube(5,11,4));
}

three::~three()
{
    //dtor
}

int three::getPoints()
{
    return this->points;
}

void three::RotL(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:

        if(cubemap[parts[0].x][parts[0].y][parts[0].z+1].exists || cubemap[parts[1].x][parts[1].y][parts[1].z+1].exists
           || cubemap[parts[2].x][parts[2].y][parts[2].z-1].exists || cubemap[parts[3].x][parts[3].y][parts[3].z-1].exists ||
           parts[1].z-1 == 0 || parts[1].z+1 == 8 ){
           return;
           }
        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z + 1;
        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z - 1;
        this->state = 3;
        break;

    case 1:

        if(cubemap[parts[0].x-1][parts[0].y][parts[0].z].exists || cubemap[parts[1].x-1][parts[1].y][parts[1].z].exists
           || cubemap[parts[2].x+1][parts[2].y][parts[2].z].exists || cubemap[parts[3].x+1][parts[3].y][parts[3].z].exists ||
           parts[0].x-1 == 0 || parts[0].x+1 == 8 ){
           return;
           }

        parts[0].x = parts[1].x - 1;
        parts[0].z = parts[1].z;
        parts[3].x = parts[2].x + 1;
        parts[3].z = parts[2].z ;
        this->state = 0;
        break;

    case 2:

        if(cubemap[parts[0].x][parts[0].y][parts[0].z-1].exists || cubemap[parts[1].x][parts[1].y][parts[1].z-1].exists
           || cubemap[parts[2].x][parts[2].y][parts[2].z+1].exists || cubemap[parts[3].x][parts[3].y][parts[3].z+1].exists ||
           parts[0].z-1 == 0 || parts[0].z+1 == 8){
           return;
           }

        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z - 1;
        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z + 1;
        this->state = 1;
        break;

    case 3:

        if(cubemap[parts[0].x+1][parts[0].y][parts[0].z].exists || cubemap[parts[1].x+1][parts[1].y][parts[1].z].exists
           || cubemap[parts[2].x-1][parts[2].y][parts[2].z].exists || cubemap[parts[3].x-1][parts[3].y][parts[3].z].exists ||
           parts[0].x-1 == 0 || parts[0].x+1 == 8){
           return;
           }

        parts[0].x = parts[1].x + 1;
        parts[0].z = parts[1].z;
        parts[3].x = parts[2].x - 1;
        parts[3].z = parts[2].z ;
        this->state = 2;
        break;
    }
}


void three::RotR(cube (&cubemap)[9][12][9])
{
    switch(state)
    {
    case 0:

        if(cubemap[parts[0].x][parts[0].y][parts[0].z-1].exists || cubemap[parts[1].x][parts[1].y][parts[1].z-1].exists
           || cubemap[parts[2].x][parts[2].y][parts[2].z+1].exists || cubemap[parts[3].x][parts[3].y][parts[3].z+1].exists ||
           parts[0].z-1 == 0 || parts[0].z+1 == 8){
           return;
           }


        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z - 1;
        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z + 1;
        this->state = 1;
        break;

    case 1:

        if(cubemap[parts[0].x+1][parts[0].y][parts[0].z].exists || cubemap[parts[1].x+1][parts[1].y][parts[1].z].exists
           || cubemap[parts[2].x-1][parts[2].y][parts[2].z].exists || cubemap[parts[3].x-1][parts[3].y][parts[3].z].exists ||
           parts[0].x-1 == 0 || parts[0].x+1 == 8){
           return;
           }

        parts[0].x = parts[1].x + 1;
        parts[0].z = parts[1].z;
        parts[3].x = parts[2].x - 1;
        parts[3].z = parts[2].z ;
        this->state = 2;
        break;

    case 2:

        if(cubemap[parts[0].x][parts[0].y][parts[0].z+1].exists || cubemap[parts[1].x][parts[1].y][parts[1].z+1].exists
           || cubemap[parts[2].x][parts[2].y][parts[2].z-1].exists || cubemap[parts[3].x][parts[3].y][parts[3].z-1].exists ||
           parts[0].z-1 == 0 || parts[0].z+1 == 8 ){
           return;
           }

        parts[0].x = parts[1].x;
        parts[0].z = parts[1].z + 1;
        parts[3].x = parts[2].x;
        parts[3].z = parts[2].z - 1;
        this->state = 3;
        break;

    case 3:

        if(cubemap[parts[0].x-1][parts[0].y][parts[0].z].exists || cubemap[parts[1].x-1][parts[1].y][parts[1].z].exists
           || cubemap[parts[2].x+1][parts[2].y][parts[2].z].exists || cubemap[parts[3].x+1][parts[3].y][parts[3].z].exists ||
           parts[0].x-1 == 0 || parts[0].x+1 == 8 ){
           return;
           }

        parts[0].x = parts[1].x - 1;
        parts[0].z = parts[1].z;
        parts[3].x = parts[2].x + 1;
        parts[3].z = parts[2].z ;
        this->state = 0;
        break;
    }
}
