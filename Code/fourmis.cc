//fourmis.cc
//Mouhamad: 50%
//Louis: 50%
#include "fourmis.h"
using namespace std;

void Collector::iniC(unsigned int& x2, unsigned int& y2, unsigned int& age2,
                     bool& food2) {
    x1 = x2;
    y1 = y2;
    age = age2;
    food = food2;
    setcc(x2, y2);
}

void Collector::setcc(unsigned int& x2, unsigned int& y2){
	cc = {x2, y2, sizeC};
}

void Collector::D_ant(double r, double g, double b){
    double s = sizeC;
    dessin_carre_croix(x1, y1, s, r, g, b);
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
void Defensor::D_ant(double r, double g, double b){
    double s = sizeD;
    dessin_carre_plus(x1, y1, s, r, g, b);
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

void Predator::D_ant(double r, double g, double b){
    double s = sizeP;
    dessin_carre_plein(x1, y1, s, r, g, b);
}

bool decodage_ligne_fourmis(string line, unsigned int etat, Collector& Col,
                            Defensor& Def, Predator& Pre)
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
        
        Carre c = { x, y, sizeC };
        if(testCarreCentre(c)) return true;
        Col.iniC(x, y, age, food);
        return false;
    }
    if (etat == 2) {
        data >> x >> y >> age;
        
        Carre c = { x, y, sizeD };
        if(testCarreCentre(c)) return true;
        Def.iniD(x, y, age);
        return false;
    }
    if (etat == 3) {
        data >> x >> y >> age;
        
        Carre c = { x, y, sizeP };
        if(testCarreCentre(c)) return true;
        Pre.iniP(x, y, age);
        return false;
    }
    return false;
}

bool Generator::GeneratorInHome(unsigned int countF, Carre& c){
    if (Carre_dans_Carre(c, cg)) {
        cout << message::generator_not_within_home(x1,y1,countF);
        return true;
    }
    return false;
}

bool Generator::G_Overlap(){
		unsigned int x, y;
		if(supCoord(cg, x, y)) {
			cout << message::generator_overlap(x1, y1, x, y);
			return true;
    }
    return false;
}

void Generator::D_ant(double r, double g, double b){
    double s = sizeG;
    dessin_carre_plein(x1, y1, s, r, g, b);
}

bool Generator::BigTest(unsigned int countF, Carre& c){
	if(testCarreCentre(cg)) return true;
    if(GeneratorInHome(countF, c)) return true;
    if(G_Overlap()) return true;
    initialise_Carre_Centre(cg);
    return false;
}

void Generator::ecrire_fourmis(ofstream& fichier){
    fichier << " " << to_string(cg.x) << " " << to_string(cg.y) << " "
            << to_string(total_food) << " ";
}

bool Collector::C_overlap(){
	unsigned int x, y;
	if(supCoord(cc, x, y)){
		cout << message::collector_overlap(x1, y1, x, y);
		return true;
	}
	return false;
}

bool Collector::BigTest(unsigned int countF, Carre& c){
	if(testCarreCentre(cc)) return true;
    if(C_overlap()) return true;
    initialise_Carre_Centre (cc);
    return false;
}

void Collector::ecrire_fourmis(ofstream& fichier){
    string a;
    if(food){
        a = "true";
    }else{
        a = "false";
    }
    fichier << "\t" << to_string(age) << " " << to_string(cc.x)
            << " " << to_string(cc.y) << " " << a << "\n";
}

bool Defensor::D_overlap(){
		unsigned int x, y;
		if(supCoord(cd, x, y)){
			cout << message::defensor_overlap(x1,y1,x,y);
			return true;
    }
    return false;
}

bool Defensor::DefensorInHome(unsigned int countF, Carre& c){
    if (Carre_dans_Carre(c,cd)){
        cout << message::defensor_not_within_home(x1,y1,countF);
        return true;
    }
    return false;
}

bool Defensor::BigTest(unsigned int countF, Carre& c){
	if(testCarreCentre(cd)) return true;
    if(DefensorInHome(countF, c)) return true;
    if(D_overlap()) return true;
    initialise_Carre_Centre(cd);
    return false;
}

void Defensor::ecrire_fourmis(ofstream& fichier){
    fichier << "\t" << to_string(age) << " " << to_string(cd.x)
            << " " << to_string(cd.y) << "\n";
}

bool Predator::P_overlap(){
	unsigned int x, y;
	if(supCoord(cp, x, y)){
		cout << message::predator_overlap(x1,y1);
		return true;
    }
    return false;
}

bool Predator::BigTest(unsigned int countF, Carre& c){
	if(testCarre(cp)) return true;
    if(P_overlap()) return true;
    initialise_Carre_Centre(cp);
    return false;
}

void Predator::ecrire_fourmis(ofstream& fichier){
    fichier << "\t" << to_string(age) << " " << to_string(cp.x)
            << " " << to_string(cp.y) << "\n";
}