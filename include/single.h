#ifndef SINGLE_H
#define SINGLE_H
#include "modele.h"
#include "cube.h"
#include <vector>

class Single : public Model
{
public:
        Single();
        virtual void RotL(cube (&cubemap)[9][12][9]);
        virtual void RotR(cube (&cubemap)[9][12][9]);
};

#endif //SINGLE_H
