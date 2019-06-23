#ifndef BIGCUBE_H
#define BIGCUBE_H

#include <modele.h>


class bigcube : public Model
{
    public:
        bigcube();
        int points;
        virtual int getPoints();
        virtual void RotL(cube (&cubemap)[9][12][9]);
        virtual void RotR(cube (&cubemap)[9][12][9]);
        virtual ~bigcube();

    protected:

    private:
};

#endif // BIGCUBE_H
