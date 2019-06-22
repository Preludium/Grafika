#ifndef MODELE_H
#define MODELE_H

#include "cube.h"
#include <vector>

class Model
{
    public:
        Model();
        virtual void RotL()=0;
        virtual void RotR()=0;
        void MovLR(int, std::vector<cube> &, cube (&cubemap)[9][12][9]);
        void MovUD(int, std::vector<cube> &, cube (&cubemap)[9][12][9]);
        bool falling(std::vector<cube> &, cube (&cubemap)[9][12][9]);
};

#endif // MODELE_H
