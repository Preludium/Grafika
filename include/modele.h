#ifndef MODELE_H
#define MODELE_H


class modele
{
    public:
        modele();
        virtual void RotL()=0;
        virtual void RotR()=0;
        virtual void MovLR(float kierunek)=0;
        virtual void MovUD(float kierunek)=0;
        virtual bool falling()=0;


    protected:

    private:
};

#endif // MODELE_H
