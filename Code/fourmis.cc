#include "fourmis.h"

vector<Fourmis> vectFourmis pushbackfourmis (unsigned int x1, unsigned int y1, unsigned int age)
{
    Fourmis fourmi (x1, x2, age);
    vectFourmis.push_back(fourmis);
    return vectFourmis;
}

void Collector::iniC(unsigned int& x2, unsigned int& y2, unsigned int& age2, bool& food2) {
    x1 = x2;
    y1 = y2;
    age = age2;
    food = food2;
}

void Defensor::iniD(unsigned int& x2, unsigned int& y2, unsigned int& age2)
{
    x1 = x2;
    y1 = y2;
    age = age2;
}

void Predator::iniP(unsigned int& x2, unsigned int& y2, unsigned int& age2)
{
    x1 = x2;
    y1 = y2;
    age = age2;
}

void decodage_ligne_fourmis(string line, unsigned int etat,
                            Collector& Col, Defensor& Def,
                            Predator& Pre)
{
    istringstream data(line);
    unsigned int x, y, age;
    string foods;
    bool food;

    if (etat == 1) {
        data >> x >> y >> age >> foods;
        if (foods == "true") {
            food = 1;
        }
        else food = 0;
        Carre c = { x, y, sizeC };
        //tester le carré
        Col.iniC(x, y, age, food);
        return;
    }
    if (etat == 2) {
        data >> x >> y >> age;
        Carre c = { x, y, sizeD };
        //tester le carré
        Def.iniD(x, y, age);
        return;
    }
    if (etat == 3) {
        data >> x >> y >> age;
        Carre c = { x, y, sizeP };
        //tester le carré
        Pre.iniP(x, y, age);
        return;
    }
}

void pushbackFourmis(Fourmis* fourmis, vector<unique_ptr<Fourmis> >& V)
{
    if (fourmis != nullptr){
        V.push_back(unique_ptr<Fourmis>(fourmis));
    }
}
void Generator::GeneratorInHome(unsigned int countF, Carre& c){
    if (CarreDansCarre(c, cg, g_max) ==  0 )
    {
        cout << message::generator_not_within_home(x1,y1,countF);
        exit (EXIT_FAILURE);
    }
}
void Generator::G_Overlap(){
    unsigned int compteur = nbTrue();
    if (supUnique(cg,compteur))
    {
        unsigned int a,b;
        supCoord (cg,a,b);
        cout << message::generator_overlap(x1,y1,a,b);
        exit(EXIT_FAILURE);
    }
}
void Generator::BigTest(unsigned int countF, Carre& c, const unsigned int& g_max){
    GeneratorInHome(countF, c);
    G_Overlap();
    initialise_Carre_Centre(cg, g_max);
}
void Collector::C_overlap(){
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
void Collector::BigTest(unsigned int countF, Carre& c, const unsigned int g_max){
    C_overlap(Carre& c);
    initialise_Carre_Centre (cc, g_max);
}
void Defensor::D_overlap(){
    unsigned int compteur = nbTrue();
    if (supUnique(cd,compteur))
    {
        unsigned int a,b;
        supCoord (cd,a,b);
        cout << message::generator_overlap(x1,y1,a,b);
        exit(EXIT_FAILURE);
    }
}
void Defensor::DefensorInHome(unsigned int countF, Carre& c,unsigned int g_max){
    if (Carre_dans_Carre(c,cd,g_max) == 0){
        cout << message::defensor_not_within_home(x1,y1,countF);
        exit(EXIT_FAILURE);
    }
}
void Defensor::BigTest(unsigned int countF, Carre& c,const unsigned int& g_max){
    DefensorInHome(countF,c,g_max);
    D_overlap();
    initialise_Carre_Centre(cd,g_max);
}
void Predator::P_overlap(){
    unsigned int compteur = nbTrue();
    if (supUnique(cp,compteur))
    {
        unsigned int a,b;
        supCoord (cp,a,b);
        cout << message::generator_overlap(x1,y1,a,b);
        exit(EXIT_FAILURE);
    }
}
void Predator::BigTest(unsigned int countF, Carre& c, const unsigned int& g_max){
    P_overlap();
    initialise_Carre_Centre(cp,g_max);
}
