#include "fourmis.h"

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

void decodage_ligne_fourmis(string line, unsigned int etat, Collector& Col, Defensor& Def, Predator& Pre)
{
    istringstream data(line);
    unsigned int x, y, age;
    string foods;
    bool food;

    if (etat == 1) {
        data >> x >> y >> age >> foods;
        if (foods == "true") {
            food = 1;
        }else food = 0;
        cout << "Col : " << x << " " << y << " " << age << " " << food << endl;
        Carre c = { x, y, sizeC };
        //tester le carré
        Col.iniC(x, y, age, food);
        return;
    }
    if (etat == 2) {
        data >> x >> y >> age;
        cout << "Def : " << x << " " << y << " " << age << endl;
        Carre c = { x, y, sizeD };
        //tester le carré
        Def.iniD(x, y, age);
        return;
    }
    if (etat == 3) {
        data >> x >> y >> age;
        cout << "Pre : " << x << " " << y << " " << age << endl;
        Carre c = { x, y, sizeP };
        //tester le carré
        Pre.iniP(x, y, age);
        return;
    }
}

void Generator::GeneratorInHome(unsigned int countF, Carre& c){
    if (Carre_dans_Carre(c, cg))
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
void Generator::BigTest(unsigned int countF, Carre& c){
    GeneratorInHome(countF, c);
    G_Overlap();
    initialise_Carre_Centre(cg);
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

void Collector::BigTest(unsigned int countF, Carre& c){
    C_overlap();
    initialise_Carre_Centre (cc);
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
void Defensor::DefensorInHome(unsigned int countF, Carre& c){
    if (Carre_dans_Carre(c,cd)){
        cout << message::defensor_not_within_home(x1,y1,countF);
        exit(EXIT_FAILURE);
    }
}
void Defensor::BigTest(unsigned int countF, Carre& c){
    DefensorInHome(countF,c);
    D_overlap();
    initialise_Carre_Centre(cd);
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
void Predator::BigTest(unsigned int countF, Carre& c){
    P_overlap();
    initialise_Carre_Centre(cp);
}
