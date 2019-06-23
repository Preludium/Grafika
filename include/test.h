#ifndef TEST_H
#define TEST_H

#include <modele.h>

class test : public Model
{
    public:
        int points;
        test();
        virtual int getPoints();
        virtual void RotL(cube (&cubemap)[9][12][9]);
        virtual void RotR(cube (&cubemap)[9][12][9]);
        virtual ~test();

    protected:

    private:
};

#endif // TEST_H