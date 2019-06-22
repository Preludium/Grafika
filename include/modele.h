#ifndef MODELE_H
#define MODELE_H

#include "cube.h"
#include <vector>
#include <stdexcept>
#include <iostream>

class Model
{
    public:
        Model();
        GLuint mytex;
        int base;
        std::vector<cube> parts;
        virtual void RotL()=0;
        virtual void RotR()=0;
        void MovLR(int, cube (&cubemap)[9][12][9]);
        void MovUD(int, cube (&cubemap)[9][12][9]);
        bool falling(cube (&cubemap)[9][12][9]);
};

#endif // MODELE_H
