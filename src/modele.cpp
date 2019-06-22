#include "modele.h"

Model::Model()
{
    //ctor
}

void Model::MovLR(int dir, std::vector<cube> &mPos, cube (&cubemap)[9][12][9])
{
    bool doMove = true;
    for (int i = 0; i < mPos.size(); ++i)
    {
        if (cubemap[mPos[i].x + dir][mPos[i].y][mPos[i].z].exists)
        {
            doMove = false;
            break;
        }
    }
    if (doMove)
    {
        for (int i = 0; i < mPos.size(); ++i)
        {
            cubemap[mPos[i].x + dir][mPos[i].y][mPos[i].z].exists = true;
            cubemap[mPos[i].x][mPos[i].y][mPos[i].z].exists = false;
            cubemap[mPos[i].x + dir][mPos[i].y][mPos[i].z].texture = cubemap[mPos[i].x][mPos[i].y][mPos[i].z].texture;
            mPos[i].x += dir;
        }
    }
}

void Model::MovUD(int dir, std::vector<cube> &mPos, cube (&cubemap)[9][12][9])
{
    bool doMove = true;
    for (int i = 0; i < mPos.size(); ++i)
    {
        if (cubemap[mPos[i].x][mPos[i].y][mPos[i].z + dir].exists)
        {
            doMove = false;
            break;
        }
    }
    if (doMove)
    {
        for (int i = 0; i < mPos.size(); ++i)
        {
            cubemap[mPos[i].x][mPos[i].y][mPos[i].z + dir].exists = true;
            cubemap[mPos[i].x][mPos[i].y][mPos[i].z].exists = false;
            cubemap[mPos[i].x][mPos[i].y][mPos[i].z + dir].texture = cubemap[mPos[i].x][mPos[i].y][mPos[i].z].texture;
            mPos[i].z += dir;
        }
    }
}

bool Model::falling(std::vector<cube> &mPos, cube (&cubemap)[9][12][9])
{
    bool doFall = true;
    for (int i = 0; i < mPos.size(); ++i)
    {
        if (cubemap[mPos[i].x][mPos[i].y - 1][mPos[i].z].exists)
        {
            doFall = false;
            break;
        }
    }
    if (doFall)
    {
        for (int i = 0; i < mPos.size(); ++i)
        {
            cubemap[mPos[i].x][mPos[i].y - 1][mPos[i].z].exists = true;
            cubemap[mPos[i].x][mPos[i].y][mPos[i].z].exists = false;
            cubemap[mPos[i].x][mPos[i].y - 1][mPos[i].z].texture = cubemap[mPos[i].x][mPos[i].y][mPos[i].z].texture;
            mPos[i].y += -1;
        }
        return true;
    }
    else
    {
        return false;
    }
}