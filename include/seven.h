#ifndef SEVEN_H
#define SEVEN_H

#include <modele.h>


class seven : public Model
{
    public:
        seven();
        int points;
        virtual int getPoints();
        virtual void RotL(cube (&cubemap)[9][12][9]);
        virtual void RotR(cube (&cubemap)[9][12][9]);
        virtual ~seven();

    protected:

    private:
};

#endif // SEVEN_H
