#ifndef FIVE_H
#define FIVE_H

#include <modele.h>


class five : public Model
{
    public:
        int points;
        five();
        virtual int getPoints();
        virtual void RotL(cube (&cubemap)[9][12][9]);
        virtual void RotR(cube (&cubemap)[9][12][9]);
        virtual ~five();

    protected:

    private:
};

#endif // FIVE_H
