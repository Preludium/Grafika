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
        void MovLR(int, std::vector<cube> &, cube (&cubemap)[9][12][9]);
        void MovUD(int, std::vector<cube> &, cube (&cubemap)[9][12][9]);
        bool falling();
};

#endif //SINGLE_H