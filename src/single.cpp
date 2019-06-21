#include "single.h"

Single::Single()
{

}


void Single::RotL()
{
    //tu niczego sie nie spodziewamy
}


void Single::RotR()
{
    //tu niczego sie nie spodziewamy
}


void Single::MovLR(int dir, std::vector<cube> &mPos, cube (&cubemap)[9][12][9])
{
    if(!cubemap[mPos[0].x + dir][mPos[0].y][mPos[0].z].exists)
    {    
        cubemap[mPos[0].x + dir][mPos[0].y][mPos[0].z].exists = true;
        cubemap[mPos[0].x][mPos[0].y][mPos[0].z].exists = false;
        cubemap[mPos[0].x + dir][mPos[0].y][mPos[0].z].texture = cubemap[mPos[0].x][mPos[0].y][mPos[0].z].texture;
        mPos[0].x += dir;
    }
}

void Single::MovUD(int dir, std::vector<cube> &mPos, cube (&cubemap)[9][12][9])
{
    if(!cubemap[mPos[0].x][mPos[0].y][mPos[0].z + dir].exists)
    {    
        cubemap[mPos[0].x][mPos[0].y][mPos[0].z + dir].exists = true;
        cubemap[mPos[0].x][mPos[0].y][mPos[0].z].exists = false;
        cubemap[mPos[0].x][mPos[0].y][mPos[0].z + dir].texture = cubemap[mPos[0].x][mPos[0].y][mPos[0].z].texture;
        mPos[0].z += dir;
    }
}


bool Single::falling()
{

}