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
using namespace std;

class Simulation {
private:
	vector<Fourmiliere> vfourmiliere;
	vector<Nourriture> vnourriture;
	public:
	void lancement(char* nom_fichier);
	bool lecture(char* nom_fichier);
	bool decodage_ligne(string line);
	void tout_supprimer();
	void sim_affiche();
	
	enum Etat_lecture {NBN, NOURRITURE, NBF, FOURMIL};
	static int etat, count, total_food, totF;
};

#endif
