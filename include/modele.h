#ifndef MODELE_H
#define MODELE_H

#include "cube.h"
#include <vector>
#include <stdexcept>
#include <iostream>

class Model
{
    public:
        int mytex;
        // int points;
        int state;
        std::vector<cube> parts;
        
        Model();
        virtual ~Model();
        virtual int getPoints()=0;
        virtual void RotL(cube (&cubemap)[9][12][9])=0;
        virtual void RotR(cube (&cubemap)[9][12][9])=0;
        void MovLR(int, cube (&cubemap)[9][12][9]);
        void MovUD(int, cube (&cubemap)[9][12][9]);
        bool falling(cube (&cubemap)[9][12][9]);
        void toBottom(cube (&cubemap)[9][12][9]);
};

#endif // MODELE_H
