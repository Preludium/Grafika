#ifndef THREE_H
#define THREE_H

#include <modele.h>


class three : public Model
{
    public:
        three();
        int points;
        virtual int getPoints();
        virtual void RotL(cube (&cubemap)[9][12][9]);
        virtual void RotR(cube (&cubemap)[9][12][9]);
        virtual ~three();

    protected:

    private:
};

#endif // THREE_H
