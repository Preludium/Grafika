#include "six.h"

six::six()
{
    this->points = 50;
    parts.push_back(cube(5,12,3));
    parts.push_back(cube(5,12,4));
    parts.push_back(cube(5,12,5));
    parts.push_back(cube(4,12,5));
    parts.push_back(cube(3,12,5));
}

six::~six()
{
    //dtor
}

int six::getPoints()
{
    return this->points;
}

void six::RotL(cube (&cubemap)[9][15][9])
{
    switch(state)
    {
    case 0:
        if(parts[2].z + 1 == 8 || parts[2].z + 2 == 8)
            return;
        for(int i = parts[2].z+2; i >= parts[2].z-2; --i){
            if(cubemap[parts[2].x][parts[2].y][i].exists || cubemap[parts[2].x-1][parts[2].y][i].exists || cubemap[parts[2].x-2][parts[2].y][i].exists)
                return;
        }
        parts[0].x = parts[2].x - 2;
        parts[0].z = parts[2].z;

        parts[1].x = parts[2].x - 1;
        parts[1].z = parts[2].z;

        parts[3].x = parts[2].x ;
        parts[3].z = parts[2].z + 1;

        parts[4].x = parts[2].x ;
        parts[4].z = parts[2].z + 2;


        this->state = 3;
        break;

    case 1:
        if(parts[2].x - 1 == 0 || parts[2].x - 2 == 0)
            return;
        for(int i = parts[2].x+2; i >= parts[2].x-2; --i){
            if(cubemap[i][parts[2].y][parts[2].z].exists || cubemap[i][parts[2].y][parts[2].z-1].exists || cubemap[i][parts[2].y][parts[2].z-2].exists)
                return;
        }
        parts[0].x = parts[2].x ;
        parts[0].z = parts[2].z- 2;

        parts[1].x = parts[2].x ;
        parts[1].z = parts[2].z- 1;

        parts[3].x = parts[2].x - 1;
        parts[3].z = parts[2].z ;

        parts[4].x = parts[2].x - 2;
        parts[4].z = parts[2].z;

        this->state = 0;
        break;

    case 2:
        if(parts[2].z - 1 == 0 || parts[2].z - 2 == 0)
            return;
        for(int i = parts[2].z+2; i >= parts[2].z-2; --i){
            if(cubemap[parts[2].x][parts[2].y][i].exists || cubemap[parts[2].x+1][parts[2].y][i].exists || cubemap[parts[2].x+2][parts[2].y][i].exists)
                return;
        }
        parts[0].x = parts[2].x + 2;
        parts[0].z = parts[2].z;

        parts[1].x = parts[2].x + 1;
        parts[1].z = parts[2].z;

        parts[3].x = parts[2].x ;
        parts[3].z = parts[2].z - 1;

        parts[4].x = parts[2].x ;
        parts[4].z = parts[2].z - 2;

        this->state = 1;
        break;

    case 3:
        if(parts[2].x + 1 == 8 || parts[2].x + 2 == 8)
            return;
         for(int i = parts[2].x+2; i >= parts[2].x-2; --i){
            if(cubemap[i][parts[2].y][parts[2].z].exists || cubemap[i][parts[2].y][parts[2].z+1].exists || cubemap[i][parts[2].y][parts[2].z+2].exists)
                return;
        }
        parts[0].x = parts[2].x ;
        parts[0].z = parts[2].z+ 2;

        parts[1].x = parts[2].x ;
        parts[1].z = parts[2].z+ 1;

        parts[3].x = parts[2].x + 1;
        parts[3].z = parts[2].z ;

        parts[4].x = parts[2].x + 2;
        parts[4].z = parts[2].z;
        this->state = 2;
        break;
    }
}


void six::RotR(cube (&cubemap)[9][15][9])
{
    switch(state)
    {
    case 0:
        if(parts[2].x + 1 == 8 || parts[2].x + 2 == 8)
            return;

        for(int i = parts[2].x+2; i >= parts[2].x-2; --i){
            if(cubemap[i][parts[2].y][parts[2].z].exists || cubemap[i][parts[2].y][parts[2].z-1].exists || cubemap[i][parts[2].y][parts[2].z-2].exists)
                return;
        }

        parts[0].x = parts[2].x + 2;
        parts[0].z = parts[2].z;

        parts[1].x = parts[2].x + 1;
        parts[1].z = parts[2].z;

        parts[3].x = parts[2].x ;
        parts[3].z = parts[2].z - 1;

        parts[4].x = parts[2].x ;
        parts[4].z = parts[2].z - 2;


        this->state = 1;
        break;

    case 1:
        if(parts[2].z + 1 == 8 || parts[2].z + 2 == 8)
            return;
        for(int i = parts[2].z+2; i >= parts[2].z-2; --i){
            if(cubemap[parts[2].x][parts[2].y][i].exists || cubemap[parts[2].x+1][parts[2].y][i].exists || cubemap[parts[2].x+2][parts[2].y][i].exists)
                return;
        }

        parts[0].x = parts[2].x ;
        parts[0].z = parts[2].z+ 2;

        parts[1].x = parts[2].x ;
        parts[1].z = parts[2].z+ 1;

        parts[3].x = parts[2].x + 1;
        parts[3].z = parts[2].z ;

        parts[4].x = parts[2].x + 2;
        parts[4].z = parts[2].z;


        this->state = 2;
        break;

    case 2:

        if(parts[2].x - 1 == 0 || parts[2].x - 2 == 0)
            return;
        for(int i = parts[2].x+2; i >= parts[2].x-2; --i){
            if(cubemap[i][parts[2].y][parts[2].z].exists || cubemap[i][parts[2].y][parts[2].z+1].exists || cubemap[i][parts[2].y][parts[2].z+2].exists)
                return;
        }

        parts[0].x = parts[2].x - 2;
        parts[0].z = parts[2].z;

        parts[1].x = parts[2].x - 1;
        parts[1].z = parts[2].z;

        parts[3].x = parts[2].x ;
        parts[3].z = parts[2].z + 1;

        parts[4].x = parts[2].x ;
        parts[4].z = parts[2].z + 2;


        this->state = 3;
        break;

    case 3:

        if(parts[2].z - 1 == 0 || parts[2].z - 2 == 0)
            return;
        for(int i = parts[2].z+2; i >= parts[2].z-2; --i){
            if(cubemap[parts[2].x][parts[2].y][i].exists || cubemap[parts[2].x-1][parts[2].y][i].exists || cubemap[parts[2].x-2][parts[2].y][i].exists)
                return;
        }

        parts[0].x = parts[2].x ;
        parts[0].z = parts[2].z- 2;

        parts[1].x = parts[2].x ;
        parts[1].z = parts[2].z- 1;

        parts[3].x = parts[2].x - 1;
        parts[3].z = parts[2].z ;

        parts[4].x = parts[2].x - 2;
        parts[4].z = parts[2].z;


        this->state = 0;
        break;
    }
}
