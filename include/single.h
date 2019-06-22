#ifndef SINGLE_H
#define SINGLE_H
#include "modele.h"
#include "cube.h"
#include <vector>

class Single : public Model
{
public:
        Single();
        void RotL();
        void RotR();
};

#endif //SINGLE_H