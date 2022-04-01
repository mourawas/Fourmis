#include "fourmiliere.h"


bool Fourmiliere::verification(vector<vector<bool> >& grille, Fourmiliere& f, vector<Fourmiliere>& vectF) {
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

vector< Carre > extraction_vector ( vector <Fourmiliere>& vectF)
{
    vector < Carre > vectC;
    for (size_t i(0); i < vectF.size(); ++i)
    {
        vectC.push_back(vectF[i].getcarref());
    }
    return vectC;
}

void decodage_ligne_fourmiliere(string line, vector<Fourmiliere>& vfourmiliere) {
    
    unsigned int x, y, side, x1, y1, total_food, nbC, nbD, nbP;

    isstringstream line(data);

    data >> x >> y >> side >> x1 >> y1 >> total_food >> nbC >> nbD >> nbP;

    Fourmiliere f(x, y, side, total_food, nbC, nbD, nbP);


}