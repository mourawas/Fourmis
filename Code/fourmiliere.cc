//fourmiliere.cc
//Mouhamad: 50%
//Louis: 50%
#include "fourmiliere.h"	

void Fourmiliere::ajouterFourmis(Fourmis* nouveau) {
    if (nouveau != nullptr) {
        vfourmis.push_back(std::unique_ptr<Fourmis>(nouveau));
    }
}

bool Fourmiliere::testFourmis(unsigned int countF, unsigned int j) {
    if(vfourmis[j]->BigTest(countF, c)) return true;
    return false;
}

bool Fourmiliere::Foverlap(vector<Fourmiliere>& vfourmiliere, unsigned int countF){
	
	for(unsigned int i = 0; i < vfourmiliere.size(); ++i){
		
		if(supFourmiliere(c, vfourmiliere[i].c)){
			cout << message::homes_overlap(i, countF-1);
			return true;
		}
	}
	return false;
}

bool decodage_ligne_fourmiliere(string line, vector<Fourmiliere>& vfourmiliere,
                                unsigned int totF) {
	
	enum Etat_lecture2 { FOURMILIERE, COL, DEF, PRE };
	static unsigned int etat (FOURMILIERE);
    static unsigned int countF = 0, countC = 0, countD = 0, countP = 0, j = 0;
    unsigned int x, y, side, xg, yg, total_food;
    static unsigned int nbC, nbD, nbP;
    istringstream data(line);
    if (etat == FOURMILIERE) {
        data >> x >> y >> side >> xg >> yg >> total_food >> nbC >> nbD >> nbP;
        Carre c = { x, y, side };
        if(testCarre(c)) return true;
        Fourmiliere f(c, nbC, nbD, nbP);
		Carre cg = {xg, yg, sizeG};
        f.ajouterFourmis(new Generator(xg, yg, total_food, cg));
        if(testCarreCentre(cg)) return true;
        if(f.testFourmis(countF, j)) return true;
        ++j, ++countF;
		if(f.Foverlap(vfourmiliere, countF)) return true;
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
    }
    Collector Col(0, 0, 0, 0);
    Defensor Def(0, 0, 0);
    Predator Pre(0, 0, 0);

    switch (etat) {
    case COL:
        if(decodage_ligne_fourmis(line, etat, Col, Def, Pre)) return true;
        vfourmiliere[countF - 1].ajouterFourmis(new Collector(Col));
        if(vfourmiliere[countF - 1].testFourmis(countF - 1, j)) return true;
        ++j; ++countC;

        if (countC == nbC) {
            etat = DEF;
        }
        break;

    case DEF:
        if(decodage_ligne_fourmis(line, etat, Col, Def, Pre)) return true;
        vfourmiliere[countF - 1].ajouterFourmis(new Defensor(Def));
        if(vfourmiliere[countF - 1].testFourmis(countF - 1, j)) return true;
        ++j; ++countD;
        if (countD == nbD) {
            etat = PRE;
        }
        break;

    case PRE:
        if(decodage_ligne_fourmis(line, etat, Col, Def, Pre)) return true;
        vfourmiliere[countF - 1].ajouterFourmis(new Predator(Pre));
        if(vfourmiliere[countF - 1].testFourmis(countF - 1, j)) return true;
        ++j; ++countP;

        if (countP == nbP) {
            etat = FOURMILIERE;
            j = 0;
        }
        break;
    }
    return false;
}
