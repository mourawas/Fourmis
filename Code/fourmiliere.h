#ifndef FOURMILIERE_H_INCLUDED
#define FOURMILIERE_H_INCLUDED
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

class Fourmiliere {
private:
    Carre c;
    unsigned int nbC, nbD, nbP;

    std::vector<unique_ptr<Fourmis> > vfourmis;
	
public:
    Fourmiliere (Carre c, unsigned int nbC, unsigned int nbD, unsigned int nbP)
    : c(c), nbC(nbC), nbD(nbD), nbP(nbP)
    {}  //^defining it anywhere but here DOESN'T WORK
    //pas de destructeur sinon erreur
    void ajouterFourmis(Fourmis* nouveau);
    bool testFourmis(unsigned int countF, unsigned int j);
    bool Foverlap(std::vector<Fourmiliere>& vfourmiliere, unsigned int countF);
    void d_Anthill(unsigned int i);
    void intern_ant_drawing(double r, double g, double b);
    void ecrire_fourmiliere(std::ofstream& fichier);
};

bool decodage_ligne_fourmiliere(std::string line, std::vector<Fourmiliere>& vfourmiliere,
                                unsigned int totF);

void re();
#endif
