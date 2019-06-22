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
        try
        {
            if (cubemap[mPos[i].x + dir][mPos[i].y][mPos[i].z].exists || mPos[i].x + dir == 0 || mPos[i].x + dir == 8)
            {
                doMove = false;
                break;
            }
        }
        catch (const std::out_of_range& oor)
        {
            std::cout << "no to poleciales gosciu\n";
        }
    }
    if (doMove)
    {
        for (int i = 0; i < mPos.size(); ++i)
        {
            cubemap[mPos[i].x + dir][mPos[i].y][mPos[i].z].exists = true;
            cubemap[mPos[i].x][mPos[i].y][mPos[i].z].exists = false;
            cubemap[mPos[i].x + dir][mPos[i].y][mPos[i].z].texture = mPos[i].texture;
            mPos[i].x += dir;
        }
    }
}

void Model::MovUD(int dir, std::vector<cube> &mPos, cube (&cubemap)[9][12][9])
{
    bool doMove = true;
    for (int i = 0; i < mPos.size(); ++i)
    { 
        try
        {
            if (cubemap[mPos[i].x][mPos[i].y][mPos[i].z + dir].exists || mPos[i].z + dir == 0 || mPos[i].z + dir == 8)
            {
                doMove = false;
                break;
            }
        }
        catch (const std::out_of_range& oor)
        {
            std::cout << "no to poleciales gosciu\n";
        }
    }
    if (doMove)
    {
        for (int i = 0; i < mPos.size(); ++i)
        {
            cubemap[mPos[i].x][mPos[i].y][mPos[i].z + dir].exists = true;
            cubemap[mPos[i].x][mPos[i].y][mPos[i].z].exists = false;
            cubemap[mPos[i].x][mPos[i].y][mPos[i].z + dir].texture = mPos[i].texture;
            mPos[i].z += dir;
        }
    }
}

bool Model::falling(std::vector<cube> &mPos, cube (&cubemap)[9][12][9])
{
    bool doFall = true;
    for (int i = 0; i < mPos.size(); ++i)
    {
        try
        {
            if (cubemap[mPos[i].x][mPos[i].y - 1][mPos[i].z].exists)
            {
                doFall = false;
                break;
            }
        }
        catch (const std::out_of_range& oor)
        {
            std::cout << "no to poleciales gosciu\n";
        }
    }
    if (doFall)
    {
        for (int i = 0; i < mPos.size(); ++i)
        {
            cubemap[mPos[i].x][mPos[i].y - 1][mPos[i].z].exists = true;
            cubemap[mPos[i].x][mPos[i].y][mPos[i].z].exists = false;
            cubemap[mPos[i].x][mPos[i].y - 1][mPos[i].z].texture = mPos[i].texture;
            mPos[i].y += -1;
        }
        return true;
    }
    else
    {
        return false;
    }
}