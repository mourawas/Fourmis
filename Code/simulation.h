#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

#include "squarecell.h"
#include "nourriture.h"
#include "fourmiliere.h"
#include "message.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
	enum Etat_lecture {NBN, NOURRITURE, NBF, FOURMIL};
	static int etat, count, total_food, totF;
};

#endif
