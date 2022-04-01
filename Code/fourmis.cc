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
void Generator::Generator_In_Homme(unsigned int countF, Carre& c){
    if (Carre_dans_Carre(c, cg, g_max) ==  0 )
    {
        cout <<message::generator_not_within_home(x1,y1,countF);
        exit (EXIT_FAILURE);
    }
}
void Generator :: G_Overlap(){
    unsigned int compteur = nbTrue();
    if (supUnique(cg,compteur))
    {
        unsigned int a,b;
        supCoord (cg,a,b);
        cout << message::generator_overlap(x1,y1,a,b);
        exit(EXIT_FAILURE);
    }
}
void Generator::Big_Test_G(unsigned int countF, Carre& c, unsigned int g_max){
    Generator_In_Homme(countF, c);
    G_Overlap();
    initialise_Carre_Centre(cg, g_max);
}
void Collector :: C_overlap(){
    unsigned int compteur = nbTrue();
    if (supUnique(cc,compteur))
    {
        unsigned int a,b;
        supCoord (cc,a,b);
        cout << message::generator_overlap(x1,y1,a,b);
        exit(EXIT_FAILURE);
    }
}
}
void Collector :: Big_Test_C(Carre& c, unsigned int g_max){
    C_overlap(Carre& c);
    initialise_Carre_Centre (cc,g_max);
}
void Defensor :: D_overlap(){
    unsigned int compteur = nbTrue();
    if (supUnique(cd,compteur))
    {
        unsigned int a,b;
        supCoord (cd,a,b);
        cout << message::generator_overlap(x1,y1,a,b);
        exit(EXIT_FAILURE);
    }
}
void Defensor :: Defensor_In_Home(unsigned int countF, Carre& c,unsigned int g_max){
    if (Carre_dans_Carre(c,cd,g_max) == 0){
        cout << message::defensor_not_within_home(x1,y1,countF);
        exit(EXIT_FAILURE);
    }
}
void Defensor :: Big_Test_D(unsigned int countF,carre& c,unsigned int g_max){
    Defensor_In_Home(countF,c,g_max);
    D_overlap();
    initialise_Carre_Centre(cd,g_max);
}
void Predator ::  P_overlap(){
    unsigned int compteur = nbTrue();
    if (supUnique(cp,compteur))
    {
        unsigned int a,b;
        supCoord (cp,a,b);
        cout << message::generator_overlap(x1,y1,a,b);
        exit(EXIT_FAILURE);
    }
}
void Predator ::Big_Test_P(Carre& c,unsigned int g_max){
    P_overlap;
    initialise_Carre_Centre(cp,g_max);
}
