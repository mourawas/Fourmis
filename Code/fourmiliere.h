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

    vector<unique_ptr<Fourmis> > vfourmis;

public:
    Fourmiliere (unsigned int x, unsigned int y, unsigned int side, unsigned int nbC, unsigned int nbD, unsigned int nbP, unsigned int total_food)
    : x(x), y(y), side(side), nbC(nbC), nbD(nbD), nbP(nbP), total_food (total_food)
    { }

    vector<unique_ptr<Fourmis> > get_vfourmis();
};

void decodage_ligne_fourmiliere(string line, vector<Fourmiliere>& vfourmiliere, grille);