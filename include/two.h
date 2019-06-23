#ifndef TWO_H
#define TWO_H

#include <modele.h>


class two : public Model
{
    public:
        two();
        int points;
        virtual int getPoints();
        virtual void RotL(cube (&cubemap)[9][12][9]);
        virtual void RotR(cube (&cubemap)[9][12][9]);
        virtual ~two();

    protected:

    private:
};

#endif // TWO_H
