#include <iostream>
#include "squarecell.h"
#include "fourmis.h"
#include "nouriture.h"
#include "foumiliere.h"
 

void pushbackF (unsigned x, unsigned y, unsigned side , unsigned x1, unsigned y1, unsigned total_food, unsigned nbC, unsigned nbD, unsigned nbP)
{
     c=creeCarre (x,y,side);
     g=creeCarre (x1,y1,1);
     
     Fourmiliere (c,g);
     vectF.push_back(F);
 }
bool multisuperposition ( vector <Fourmiliere> v)
{
    bool t=0;
    for (size_t i(0), i<v.size();++i){
        for (size_t j(i+1),j< v.size();++j){
            if ( superposition(grille,tab[i].getcarre(),tab[j].getcarre())){
                cout << i<<"eme carré se superpose avec le "<< j<< "eme carré"<< endl;
            }
            else
            {
                cout << "pas de superposition"<< endl;
                t=1
            }
        }
    }
    return t;
}
