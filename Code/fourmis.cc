#include "fourmis.h"

void Collector::iniC(unsigned int& x2, unsigned int& y2, unsigned int& age2, bool& food2) {
    x1 = x2;
    y1 = y2;
    age = age2;
    food = food2;
    setcc(x2, y2);
}

void Collector::setcc(unsigned int& x2, unsigned int& y2){
	cc = {x2, y2, sizeC};
}

void Defensor::iniD(unsigned int& x2, unsigned int& y2, unsigned int& age2)
{
    x1 = x2;
    y1 = y2;
    age = age2;
    setcd(x2, y2);
}

void Defensor::setcd(unsigned int& x2, unsigned int& y2){
	cd = {x2, y2, sizeD};
}

void Predator::iniP(unsigned int& x2, unsigned int& y2, unsigned int& age2)
{
    x1 = x2;
    y1 = y2;
    age = age2;
    setcp(x2, y2);
}

void Predator::setcp(unsigned int& x2, unsigned int& y2){
	cp = {x2, y2, sizeP};
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
        //cout << "Col : " << x << " " << y << " " << age << " " << food << endl;
        Carre c = { x, y, sizeC };
        testCarreCentre(c);
        Col.iniC(x, y, age, food);
        return;
    }
    if (etat == 2) {
        data >> x >> y >> age;
        //cout << "Def : " << x << " " << y << " " << age << endl;
        Carre c = { x, y, sizeD };
        testCarreCentre(c);
        Def.iniD(x, y, age);
        return;
    }
    if (etat == 3) {
        data >> x >> y >> age;
        //cout << "Pre : " << x << " " << y << " " << age << endl;
        Carre c = { x, y, sizeP };
        testCarreCentre(c);
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
		unsigned int x, y;
		if(supCoord(cg, x, y)){
        cout << message::generator_overlap(x1, y1, x, y);
        exit(EXIT_FAILURE);
    }
}

void Generator::BigTest(unsigned int countF, Carre& c){
    GeneratorInHome(countF, c);
    G_Overlap();
    initialise_Carre_Centre(cg);
}

void Collector::C_overlap(){
	unsigned int x, y;
	if(supCoord(cc, x, y)){
		cout << message::collector_overlap(x1, y1, x, y);
		exit(EXIT_FAILURE);
	}
}

void Collector::BigTest(unsigned int countF, Carre& c){
    C_overlap();
    initialise_Carre_Centre (cc);
}

void Defensor::D_overlap(){
		unsigned int x, y;
		if(supCoord(cd, x, y)){
			cout << message::defensor_overlap(x1,y1,x,y);
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
    DefensorInHome(countF, c);
    D_overlap();
    initialise_Carre_Centre(cd);
}

void Predator::P_overlap(){
		unsigned int x, y;
		if(supCoord(cp, x, y)){
			cout << message::predator_overlap(x1,y1);
			exit(EXIT_FAILURE);
    }
}

void Predator::BigTest(unsigned int countF, Carre& c){
    P_overlap();
    initialise_Carre_Centre(cp);
}
