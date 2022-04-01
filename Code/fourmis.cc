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
void Generator::Generator_In_Homme(unsigned int countF, Carre& c,grille& grille){
    Carre cg = {{x1,y1},sideG}
    if (Carre_dans_Carre(c, cg, grille& grille, g_max) ==  0 )
    {
        cout <<message::generator_not_within_home(x1,y1,countF);
        exit (EXIT_FAILURE);
    }
}
void G_Overlap(carre& c, grille& grille){
    
    
    cout << message::generator_overlap(x1,y1,les deux indices de sup);
    exit(EXIT_FAILURE);
}
void Generator::Big_Test_G(grille& grille, Carre& c, unsigned int countF,g_max){
    Generator_In_Homme(countF, c, grille);
    G_Overlap(c, grille);
    initialise_Carre_Centre(cg, g_max);
}
