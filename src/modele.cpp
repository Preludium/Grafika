#include "modele.h"

Model::Model()
{
    //ctor
}

void Model::MovLR(int dir, cube (&cubemap)[9][12][9])
{
    bool doMove = true;
    for (int i = 0; i < parts.size(); ++i)
    {
        try
        {
            if (cubemap[parts[i].x + dir][parts[i].y][parts[i].z].exists || parts[i].x + dir == 0 || parts[i].x + dir == 8)
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
        for (int i = 0; i < parts.size(); ++i)
        {
            cubemap[parts[i].x + dir][parts[i].y][parts[i].z].exists = true;
            cubemap[parts[i].x][parts[i].y][parts[i].z].exists = false;
            cubemap[parts[i].x + dir][parts[i].y][parts[i].z].texture = parts[i].texture;
            parts[i].x += dir;
        }
    }
}

void Model::MovUD(int dir, cube (&cubemap)[9][12][9])
{
    bool doMove = true;
    for (int i = 0; i < parts.size(); ++i)
    {
        try
        {
            if (cubemap[parts[i].x][parts[i].y][parts[i].z + dir].exists || parts[i].z + dir == 0 || parts[i].z + dir == 8)
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
        for (int i = 0; i < parts.size(); ++i)
        {
            cubemap[parts[i].x][parts[i].y][parts[i].z + dir].exists = true;
            cubemap[parts[i].x][parts[i].y][parts[i].z].exists = false;
            cubemap[parts[i].x][parts[i].y][parts[i].z + dir].texture = parts[i].texture;
            parts[i].z += dir;
        }
    }
}

bool Model::falling(cube (&cubemap)[9][12][9])
{
    bool doFall = true;
    for (int i = 0; i < parts.size(); ++i)
    {
        try
        {
            if (cubemap[parts[i].x][parts[i].y - 1][parts[i].z].exists)
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
        for (int i = 0; i < parts.size(); ++i)
        {
            cubemap[parts[i].x][parts[i].y - 1][parts[i].z].exists = true;
            cubemap[parts[i].x][parts[i].y][parts[i].z].exists = false;
            cubemap[parts[i].x][parts[i].y - 1][parts[i].z].texture = parts[i].texture;
            parts[i].y += -1;
        }
        return true;
    }
    else
    {
        return false;
    }
}
