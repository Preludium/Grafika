#ifndef FOUR_H
#define FOUR_H

#include <modele.h>


class four : public Model
{
    public:
        four();
        virtual void RotL(cube (&cubemap)[9][12][9]);
        virtual void RotR(cube (&cubemap)[9][12][9]);
        virtual ~four();

    protected:

    private:
};

#endif // FOUR_H
