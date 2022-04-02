#ifndef FHEADER_H
#define FHEADER_H
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "squarecell.h"
#include "fourmis.h"
#include "nourriture.h"
#include "message.h"
using namespace std;

class Fourmiliere {
private:
    Carre c;
    unsigned int nbC, nbD, nbP;

    vector<unique_ptr<Fourmis> > vfourmis;

public:
    Fourmiliere (Carre c, unsigned int nbC, unsigned int nbD, unsigned int nbP)
    : c(c), nbC(nbC), nbD(nbD), nbP(nbP)
    { }

    void ajouterFourmis(Fourmis* nouveau);
    void testFourmis(unsigned int countF, unsigned int j);
};

enum Etat_lecture2 { FOURMILIERE, COL, DEF, PRE };

void decodage_ligne_fourmiliere(string line,vector<Fourmiliere>& vfourmiliere,unsigned int totF);

#endif
