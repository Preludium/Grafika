#ifndef BIGCUBE_H
#define BIGCUBE_H

#include <modele.h>


class bigcube : public Model
{
    public:
        bigcube();
        void RotL();
        void RotR();
        virtual ~bigcube();

    protected:

    private:
};

#endif // BIGCUBE_H
