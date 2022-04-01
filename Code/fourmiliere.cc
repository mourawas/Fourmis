#include "fourmiliere.h"

bool Fourmiliere::verification(grille& grille, Fourmiliere& f, vector<Fourmiliere>& vectF) {
    for (size_t i(0); i < vectF.size(); ++i)
    {
        if (superposition(grille, vectF[i].getcarref, f.getcarref)) {
            return false
        }
        else {
            return true;
        }
    }
}

vector<unique_ptr<Fourmis> > Fourmiliere::get_vfourmis() {
    return vfourmis;
}

void Fourmiliere::ajouter_foumis(Fourmis* nouveau) {
    if (nouveau != nullptr) {
        vfourmis.push_back(unique_ptr<Fourmis>(nouveau))
    }
}

void decodage_ligne_fourmiliere(string line, vector<Fourmiliere>& vfourmiliere, grille) {
    
    enum Etat = { FOURMILIERE, COL, DEF, PRO };
    static unsigned int etat = FOURMILIERE, countF = 0, countC = 0, countD = 0, countP = 0, j = 0;

    unsigned int x, y, side, xg, yg, total_food;
    static unsigned int nbC, nbD, nbP;

    isstringstream line(data);

    if (etat == FOURMILIERE) {
        data >> x >> y >> side >> xg >> yg >> total_food >> nbC >> nbD >> nbP;

        Fourmiliere f(x, y, side, nbC, nbD, nbP);

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
            etat = Pro;
        }
        else {
            ++countF;
            etat = Fourmiliere;
        }

    }
}