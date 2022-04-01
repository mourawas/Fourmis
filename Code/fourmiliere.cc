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

vector< Carre > extraction_vector ( vector <Fourmiliere>& vectF)
{
    vector < Carre > vectC;
    for (size_t i(0); i < vectF.size(); ++i)
    {
        vectC.push_back(vectF[i].getcarref());
    }
    return vectC;
}

void decodage_ligne_fourmiliere(string line, vector<Fourmiliere>& vfourmiliere, grille) {
    
    enum Etat = {GEN, COL, DEF, }

    unsigned int x, y, side, xg, yg, total_food, nbC, nbD, nbP;

    isstringstream line(data);

    data >> x >> y >> side >> xg >> yg >> total_food >> nbC >> nbD >> nbP;

    Fourmiliere f(x, y, side, nbC, nbD, nbP, total_food);

    switch()

    decodage_ligne_fourmis(line, Fourmiliere::get_vfourmis());
}