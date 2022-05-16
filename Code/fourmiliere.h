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

    std::vector<std::unique_ptr<Fourmis>> vfourmis;
public:
    Fourmiliere (Carre c, unsigned int nbC, unsigned int nbD, unsigned int nbP);
    void ajouter_fourmis(Fourmis* nouveau);
    bool test_fourmis(unsigned int countF, unsigned int j);
    bool f_overlap(std::vector<Fourmiliere>& vfourmiliere, unsigned int countF);
    void d_anthill(unsigned int i);
    void intern_ant_drawing(double r, double g, double b);
    void ecrire_fourmiliere(std::ofstream& fichier);
    unsigned int get_nbC();
    unsigned int get_nbD();
    unsigned int get_nbP();
    unsigned int get_total_food();
    Carre get_carre();
};

bool decodage_ligne_fourmiliere(std::string line,
                                std::vector<Fourmiliere>& vfourmiliere,
                                unsigned int totF);

void re();

#endif
