#include <iostream>
#include <vector>
#include "squarecell.h"
#include "fourmis.h"
#include "nourriture.h"
#include "fourmiliere.h"
#include "message.h"
using namespace std;

vector<Fourmiliere> fourmilieres;

class Fourmiliere {
private:
    unsigned int x, y, side, nbC, nbD, nbP, total_food;

    vector<unique_ptr<Fourmis> > fourmis;

public:
    Fourmiliere (Carre f, Carre g, unsigned int nbC, unsigned int nbD, unsigned int nbP, unsigned int total_food)
    : f(f), g(g), nbD(nbD),nbP(nbP), total_food (total_food), nbC (nbC)
    { }
};

void decodage_ligne_fourmiliere(string line, vector<Fourmiliere>& vfourmiliere, grille);