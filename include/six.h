#ifndef SIX_H
#define SIX_H

#include <modele.h>


class six : public Model
{
    public:
        six();
        virtual void RotL(cube (&cubemap)[9][12][9]);
        virtual void RotR(cube (&cubemap)[9][12][9]);
        virtual ~six();

    protected:

    private:
};

#endif // SIX_H
