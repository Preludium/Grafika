#ifndef ONE_H
#define ONE_H

#include <modele.h>


class one : public Model
{
    public:
        one();
        int points;
        virtual int getPoints();
        virtual void RotL(cube (&cubemap)[9][15][9]);
        virtual void RotR(cube (&cubemap)[9][15][9]);
        virtual ~one();

    protected:

    private:
};

#endif // ONE_H
