#include <vector>
#include "fourmis.h"
using namespace std;

vector<Fourmiliere> fourmilieres;

class Fourmiliere {
private:
    Carre f;
    Carre g;
    unsigned int nbC;
    unsigned int nbD;
    unsigned int nbP;
    unsigned int total_food;

    vector<Fourmis> Col;
    vector<Fourmis> Def;
    vector<Fourmis> Pro;

public:
    Fourmiliere (Carre f, Carre g, unsigned int nbC, unsigned int nbD, unsigned int nbP, unsigned int total_food)
    : f(f), g(g), nbD(nbD),nbP(nbP), total_food (total_food),nbC (nbC)
    { }
    Carre getcarref () const
    {
        return f;
    }
    bool verification(vector<vector<bool> >& grille, Fourmiliere& f, vector<Fourmiliere>& vectF);

};