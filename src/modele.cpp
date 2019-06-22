#include "modele.h"

Model::Model()
{
    //ctor
}

void Model::MovLR(int dir, cube (&cubemap)[9][12][9])
{
        for (int i = 0; i < parts.size(); ++i)
    {
        try
        {
            if (cubemap[parts[i].x + dir][parts[i].y][parts[i].z].exists || parts[i].x + dir == 0 || parts[i].x + dir == 8)
            {
                return;
            }
        }
        catch (const std::out_of_range& oor)
        {
            std::cout << "no to poleciales gosciu\n";
        }
    }

    for (int i = 0; i < parts.size(); ++i)
    {
        parts[i].x += dir;
    }

}

void Model::MovUD(int dir, cube (&cubemap)[9][12][9])
{

    for (int i = 0; i < parts.size(); ++i)
    {
        try
        {
            if (cubemap[parts[i].x][parts[i].y][parts[i].z + dir].exists || parts[i].z + dir == 0 || parts[i].z + dir == 8)
            {
                return;
            }
        }
        catch (const std::out_of_range& oor)
        {
            std::cout << "no to poleciales gosciu\n";
        }
    }

    for (int i = 0; i < parts.size(); ++i)
    {
        parts[i].z += dir;
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
                return false;
            }
        }
        catch (const std::out_of_range& oor)
        {
            std::cout << "no to poleciales gosciu\n";
        }
    }

    for (int i = 0; i < parts.size(); ++i)
    {
        parts[i].y += -1;
    }
    return true;
}
