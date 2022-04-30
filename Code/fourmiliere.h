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
#include "constantes.h"
using namespace std;

class Fourmiliere {
private:
    Carre c;
    unsigned int nbC, nbD, nbP;

    vector<unique_ptr<Fourmis> > vfourmis;
	
public:
    Fourmiliere (Carre c, unsigned int nbC, unsigned int nbD, unsigned int nbP)
    : c(c), nbC(nbC), nbD(nbD), nbP(nbP)
    {}  //^defining it anywhere but here DOESN'T WORK
    //pas de destructeur sinon erreur
    void ajouterFourmis(Fourmis* nouveau);
    bool testFourmis(unsigned int countF, unsigned int j);
    bool Foverlap(vector<Fourmiliere>& vfourmiliere, unsigned int countF);
    void d_Anthill(unsigned int i);
    void intern_ant_drawing(double r, double g, double b);
};

bool decodage_ligne_fourmiliere(string line,vector<Fourmiliere>& vfourmiliere,
                                unsigned int totF);

void re();
#endif
