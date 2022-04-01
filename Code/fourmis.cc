#include <iostream>
#include <vector>
#include "squarecell.h"
#include "message.h"
#include "fourmis.h"
#include "nourriture.h"

vector< Fourmis > vectFourmis pushbackfourmis (unsigned int x1, unsigned int y1, unsigned int age)
{
    Fourmis fourmis (x1,x2,age);
    vectFourmis.push_back (fourmis);
    return vectFourmis;
}

void decodage_ligne_fourmis(string line, vector<unique_ptr<Fourmis> >& V )
{
    unsigned int x1,y1,age;
    isstringstream (data)
    data << x1, y1, age ;
    
}
void pushbackfourmis (Fourmis* fourmis, vector<unique_ptr<Fourmis> >& V)
{
    if ( fourmis != nullptr){
        V.push_back( unique_ptr<Fourmis>(fourmis));
    }
}
 
