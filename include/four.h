#ifndef FOUR_H
#define FOUR_H

#include <modele.h>


class four : public Model
{
    public:
        four();
        int points;
        virtual int getPoints();
        virtual void RotL(cube (&cubemap)[9][15][9]);
        virtual void RotR(cube (&cubemap)[9][15][9]);
        virtual ~four();

    protected:

    private:
};

#endif // FOUR_H
