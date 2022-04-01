#include "fourmiliere.h"

vector<unique_ptr<Fourmis> > Fourmiliere::get_vfourmis() {
    return vfourmis;
}

void Fourmiliere::ajouterFoumis(Fourmis* nouveau) {
    if (nouveau != nullptr) {
        vfourmis.push_back(unique_ptr<Fourmis>(nouveau))
    }
}

void Fourmiliere::testFourmis(unsigned int& countF, unsigned int& i) {
    vfourmis[i]->BigTest(countF, c)
}

void decodage_ligne_fourmiliere(string line, vector<Fourmiliere>& vfourmiliere) {

    enum Etat = { FOURMILIERE, COL, DEF, PRO };
    static unsigned int etat = FOURMILIERE, countF = 0, countC = 0, countD = 0, countP = 0, j = 0;

    unsigned int x, y, side, xg, yg, total_food;
    static unsigned int nbC, nbD, nbP;

    isstringstream line(data);

    if (etat == FOURMILIERE) {
        data >> x >> y >> side >> xg >> yg >> total_food >> nbC >> nbD >> nbP;
        Carre c = { x, y, side };
        Fourmiliere f(c, nbC, nbD, nbP);

        f.ajouter_fourmis(new Generator(xg, yg, total_food));
        //tester generator
        decodage_ligne_fourmis(line, Fourmiliere::get_vfourmis());
        ++j, ++countF;

        vfourmiliere.push_back(move(f));
        countC = 0;
        countD = 0;
        countP = 0;

        if (nbC) {
            etat = Col;
        }
        else if (nbD) {
            etat = Def;
        }
        else if (nbP) {
            etat = Pre;
        }
        else if (countF == totF) {
            return;
        }
    }
    Collector Col(0, 0, 0);
    Defensor Def(0, 0);
    Protector Pro(0, 0);

    switch (etat) {
    case COL:
        decodage_ligne_fourmis(line, grille, etat, Col, Def, Pre);
        vfourmiliere[countF - 1].ajouterFourmis(new Collector(Col));
        vfourmiliere[countF - 1].testFourmis(grille, countF - 1, j);
        ++j; ++countC;

        if (countC == nbC) {
            etat = DEF;
        }
        break;

    case DEF:
        decodage_ligne_fourmis(line, grille, etat, Col, Def, Pre);
        vfourmiliere[countF - 1].ajouterFourmis(new Defensor(Def));
        vfourmiliere[countF - 1].testFourmis(grid, countF - 1, j);
        ++j; ++countD;
        if (countD == nbD) {
            etat = PRE;
        }
        break;

    case PRE:
        decodage_ligne_fourmis(line, grid, etat, Col, Def, Pre);
        vfourmiliere[countF - 1].ajouterFourmis(new Predator(Pre));
        vfourmiliere[countF - 1].testFourmis(grille, countF - 1, j);
        ++j; ++countP;

        if (countP == nbP) {
            etat = FOURMILIERE;
            i = 0;
        }
        break;
    }
}

