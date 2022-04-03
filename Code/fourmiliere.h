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
    void supFourmiliere(Fourmiliere& f2, unsigned int& countF, unsigned int& j);
};

void decodage_ligne_fourmiliere(string line,vector<Fourmiliere>& vfourmiliere,unsigned int totF);

#endif
