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
        virtual void MovLR(int, std::vector<cube> &, cube (&cubemap)[9][12][9]) = 0;
        virtual void MovUD(int, std::vector<cube> &, cube (&cubemap)[9][12][9]) = 0;
        virtual bool falling()=0;


    protected:

    private:
};

#endif // MODELE_H
