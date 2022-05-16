//fourmiliere.cc
//Mouhamad: 50%
//Louis: 50%
#include "fourmiliere.h"	
using namespace std;

static unsigned int etat = 0;
static unsigned int countF = 0, countC = 0, countD = 0, countP = 0, j = 0;

Fourmiliere::Fourmiliere(Carre c, unsigned int nbC, unsigned int nbD, 
                         unsigned int nbP)
    : c(c), nbC(nbC), nbD(nbD), nbP(nbP) {}

void Fourmiliere::ajouter_fourmis(Fourmis* nouveau) {
    if (nouveau != nullptr) {
        vfourmis.push_back(std::unique_ptr<Fourmis>(nouveau));
    }
}

bool Fourmiliere::test_fourmis(unsigned int countF, unsigned int j) {
    if(vfourmis[j]->big_test(countF, c)) return true;
    return false;
}

bool Fourmiliere::f_overlap(vector<Fourmiliere>& vfourmiliere, unsigned int countF){
	
	for(unsigned int i = 0; i < vfourmiliere.size(); ++i){
		
		if(sup_carre(c, vfourmiliere[i].c)){
			cout << message::homes_overlap(i, countF-1);
			return true;
		}
	}
	return false;
}

void Fourmiliere::d_anthill(unsigned int i){
    double r;
    double g;
    double b;
    if (i%6 == 0){       //rouge
    r=1;
    g=0;
    b=0;
    }
    else if (i%6 == 1){   //vert
    r=0;
    g=1;
    b=0;
    }
    else if (i%6 == 2){     //bleu
    r=0;
    g=0;
    b=1;
    }
    else if (i%6 == 3){      //jaune
    r=1;
    g=1;
    b=0;
    }
    else if (i%6 == 4){      //magenta
    r=1;
    g=0;
    b=1;
    }
    else if (i%6 == 5){      //cyan
    r=0;
    g=1;
    b=1;
    }
    double s = c.side;
    intern_ant_drawing(r, g, b);
    dessin_carre_vide(c.x, c.y, s, r, g, b);
}

void Fourmiliere::intern_ant_drawing(double r, double g, double b){
    for (size_t k = 0; k < vfourmis.size(); ++k){
        vfourmis[k]->d_ant(r, g, b);
    }
}

bool decodage_ligne_fourmiliere(string line, vector<Fourmiliere>& vfourmiliere,
                                unsigned int totF) {
	
	enum Etat_lecture2 { FOURMILIERE, COL, DEF, PRE };
    unsigned int x, y, side, xg, yg, total_food;
    static unsigned int nbC, nbD, nbP;
    istringstream data(line);
    if (etat == FOURMILIERE) {
        data >> x >> y >> side >> xg >> yg >> total_food >> nbC >> nbD >> nbP;
        Carre c = { x, y, side };
        if(test_carre(c)) return true;
        Fourmiliere f(c, nbC, nbD, nbP);
		Carre cg = {xg, yg, sizeG};
        f.ajouter_fourmis(new Generator(xg, yg, total_food, cg));
        if(test_carre_centre(cg)) return true;
        if(f.test_fourmis(countF, j)) return true;
        ++j, ++countF;
		if(f.f_overlap(vfourmiliere, countF)) return true;
        vfourmiliere.push_back(std::move(f));
        countC = 0, countD = 0, countP = 0;

        if (nbC) {
            etat = COL;
            return false;
        }
        else if (nbD) {
            etat = DEF;
            return false;
        }
        else if (nbP) {
            etat = PRE;
            return false;
        }
        else if (countF == totF) {
            return false;
        }
        if(j == (nbC + nbD + nbP + 1)){
            j = 0, countC = 0, countD = 0, countP = 0;
        }
    }

    Collector Col(0, 0, 0, 0);
    Defensor Def(0, 0, 0);
    Predator Pre(0, 0, 0);

    switch (etat) {
    case COL:
        if(decodage_ligne_fourmis(line, etat, Col, Def, Pre)) return true;
        vfourmiliere[countF - 1].ajouter_fourmis(new Collector(Col));
        if(vfourmiliere[countF - 1].test_fourmis(countF - 1, j)) return true;
        ++j; ++countC;

        if (countC == nbC) {
            etat = DEF;
        }
        break;
    case DEF:
        if(decodage_ligne_fourmis(line, etat, Col, Def, Pre)) return true;
        vfourmiliere[countF - 1].ajouter_fourmis(new Defensor(Def));
        if(vfourmiliere[countF - 1].test_fourmis(countF - 1, j)) return true;
        ++j; ++countD;
        if (countD == nbD) {
            etat = PRE;
        }
        break;
    case PRE:
        if(decodage_ligne_fourmis(line, etat, Col, Def, Pre)) return true;
        vfourmiliere[countF - 1].ajouter_fourmis(new Predator(Pre));
        if(vfourmiliere[countF - 1].test_fourmis(countF - 1, j)) return true;
        ++j; ++countP;

        if (countP == nbP) {
            etat = FOURMILIERE;
            j = 0;
        }
        break;
    }
    return false;
}

void re(){
    etat = 0, countF = 0, countC = 0, countD = 0, countP = 0;
    j = 0;
}

void Fourmiliere::ecrire_fourmiliere(ofstream& fichier){
    fichier << "\t" << to_string(c.x) << " " << to_string(c.y)
            << " " << to_string(c.side);
    vfourmis[0]->ecrire_fourmis(fichier);
    fichier << to_string(nbC) << " " << to_string(nbD)
            << " " << to_string(nbP) << "\n\n";
    for (size_t i = 1; i < vfourmis.size(); ++i)
    {
        vfourmis[i]->ecrire_fourmis(fichier);
    }
}

unsigned int Fourmiliere::get_nbC(){
    return nbC;
}

unsigned int Fourmiliere::get_nbD(){
    return nbD;
}

unsigned int Fourmiliere::get_nbP(){
    return nbP;
}

unsigned int Fourmiliere::get_total_food(){
    return vfourmis[0]->get();
}

Carre Fourmiliere::get_carre(){
    return c;
}