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
    Fourmiliere (unsigned int x, unsigned int y, unsigned int side, unsigned int nbC, unsigned int nbD, unsigned int nbP)
    : x(x), y(y), side(side), nbC(nbC), nbD(nbD), nbP(nbP)
    { }

    vector<unique_ptr<Fourmis> > get_vfourmis();
    void ajouter_foumis(Fourmis* nouveau);
};

void decodage_ligne_fourmiliere(string line, vector<Fourmiliere>& vfourmiliere, grille);