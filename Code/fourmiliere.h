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
    bool mode = 0;  //0 free, 1 constrained
    std::vector<std::unique_ptr<Fourmis>> vfourmis;
    unsigned int sizeF = (sqrt(4*((sizeG*sizeG)+(sizeC*sizeC)*nbC+(sizeD*sizeD)*nbD+(sizeP*sizeP)*nbP)));
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
    void taille_fourmiliere(std::vector<Fourmiliere>& vfourmiliere);
    void naissance_fourmis();
    void naissance_col();
    void naissance_def();
    void naissance_pre();
    void detecte_food(std::vector<Nourriture>& vnourriture);
    bool atteindre_test(Nourriture& n, unsigned int& i);
    bool fourmiliere_check();
    void attak_rival(unsigned int i, std::vector <Nourriture> vn, std::vector <Fourmiliere>& vfourmiliere);
    bool get_mode ();
    void defense();
    };

bool decodage_ligne_fourmiliere(std::string line,
                                std::vector<Fourmiliere>& vfourmiliere,
                                unsigned int totF);

void re();

#endif
