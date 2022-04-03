#include "fourmiliere.h"

void Fourmiliere::ajouterFourmis(Fourmis* nouveau) {
    if (nouveau != nullptr) {
        vfourmis.push_back(unique_ptr<Fourmis>(nouveau));
    }
}

void Fourmiliere::testFourmis(unsigned int countF, unsigned int j) {
    vfourmis[j]->BigTest(countF, c);
}
void Fourmiliere::Foverlap(vector<Fourmiliere>& vfourmiliere, unsigned int countF){
	
	for(unsigned int i = 0; i < vfourmiliere.size(); ++i){
		
		if(supFourmiliere(c, vfourmiliere[i].c)){
			cout << message::homes_overlap(i, countF-1);
			exit(EXIT_FAILURE);
		}
	}
}

void decodage_ligne_fourmiliere(string line, vector<Fourmiliere>& vfourmiliere,
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
        testCarre(c);
        Fourmiliere f(c, nbC, nbD, nbP);
		Carre cg = {xg, yg, sizeG};
        f.ajouterFourmis(new Generator(xg, yg, total_food, cg));
        testCarreCentre(cg);
        f.testFourmis(countF, j);
        ++j, ++countF;
		f.Foverlap(vfourmiliere, countF);
        vfourmiliere.push_back(std::move(f));
        countC = 0;
        countD = 0;
        countP = 0;

        if (nbC) {
            etat = COL;
            return;
        }
        else if (nbD) {
            etat = DEF;
            return;
        }
        else if (nbP) {
            etat = PRE;
            return;
        }
        else if (countF == totF) {
            return;
        }
    }
    Collector Col(0, 0, 0, 0);
    Defensor Def(0, 0, 0);
    Predator Pre(0, 0, 0);

    switch (etat) {
    case COL:
        decodage_ligne_fourmis(line, etat, Col, Def, Pre);
        vfourmiliere[countF - 1].ajouterFourmis(new Collector(Col));
        vfourmiliere[countF - 1].testFourmis(countF - 1, j);
        ++j; ++countC;

        if (countC == nbC) {
            etat = DEF;
        }
        break;

    case DEF:
        decodage_ligne_fourmis(line, etat, Col, Def, Pre);
        vfourmiliere[countF - 1].ajouterFourmis(new Defensor(Def));
        vfourmiliere[countF - 1].testFourmis(countF - 1, j);
        ++j; ++countD;
        if (countD == nbD) {
            etat = PRE;
        }
        break;

    case PRE:
        decodage_ligne_fourmis(line, etat, Col, Def, Pre);
        vfourmiliere[countF - 1].ajouterFourmis(new Predator(Pre));
        vfourmiliere[countF - 1].testFourmis(countF - 1, j);
        ++j; ++countP;

        if (countP == nbP) {
            etat = FOURMILIERE;
            j = 0;
        }
        break;
    }
}

