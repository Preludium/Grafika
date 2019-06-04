#ifndef SINGLE_H
#define SINGLE_H
#include "modele.h"

class single : public modele
{
public:
        single();
        void RotL();
        void RotR();
        void MovLR(float kierunek);
        void MovUD(float kierunek);
        bool falling();
};

#endif //SINGLE_H