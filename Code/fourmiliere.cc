#include <iostream>
#include "squarecell.h"
#include "fourmis.h"
#include "nouriture.h"
#include "foumiliere.h"
 
vector <Fourmiliere> vectF ;
class Fourmiliere {
private:
    Carre f;
    Carre g;
    unsigned nbC;
    unsigned nbD;
    unsigned nbP;
    unsigned total_food;
public:
    Fourmiliere (Carre f, Carre g, unsigned nbC, unsigned nbD, unsigned nbP,unsigned total_food)
    : f(f), g(g), nbD(nbD),nbP(nbP), total_food (total_food),nbC (nbC)
    {}
};

void pushbackF (unsigned x, unsigned y, unsigned side , unsigned x1, unsigned y1, unsigned total_food, unsigned nbC, unsigned nbD, unsigned nbP)
{
     c=creeCarre (x,y,side);
     g=creeCarre (x1,y1,1);
     
     Fourmiliere (c,g);
     vectF.push_back(F);
 }
