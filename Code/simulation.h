#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include "squarecell.h"
#include "nourriture.h"
#include "fourmiliere.h"
#include "message.h"

class Simulation {
private:
	std::vector<Fourmiliere> vfourmiliere;
	std::vector<Nourriture> vnourriture;
public:
	void lancement(char* nom_fichier);
	bool lecture(char* nom_fichier);
	bool decodage_ligne(std::string line);
	void tout_supprimer();
	void sim_affiche();
	void ecrire_fichier(std::ofstream& fichier);
	int get_taillevf();
	unsigned int get_taillevn();
	unsigned int get_total_food(int& id);
	enum Etat_lecture {NBN, NOURRITURE, NBF, FOURMIL};
	static int etat, count, total_food, totF;
	unsigned int get_nbC(int& id);
	unsigned int get_nbD(int& id);
	unsigned int get_nbP(int& id);
	void creer_nourriture();
	bool test_point_fourmiliere(unsigned int& x, unsigned int& y);
    bool atteindre_test(Nourriture&, Fourmis&);
	void etape_simulation();
	void creer_coord(unsigned int& x, unsigned int& y);
    void detect_food();
};

#endif
