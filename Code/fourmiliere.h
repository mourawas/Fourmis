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
    Carre c;
    unsigned int nbC, nbD, nbP, total_food;

    vector<unique_ptr<Fourmis> > vfourmis;

public:
    Fourmiliere (Carre c, unsigned int nbC, unsigned int nbD, unsigned int nbP)
    : c(c), nbC(nbC), nbD(nbD), nbP(nbP)
    { }

    vector<unique_ptr<Fourmis> > get_vfourmis();
    void ajouterFoumis(Fourmis* nouveau);
    void testFourmis(grille& grille, unsigned int& countF, unsigned int& i);
};

void decodage_ligne_fourmiliere(string line, vector<Fourmiliere>& vfourmiliere, grille);