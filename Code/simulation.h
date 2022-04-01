#ifndef SIMULATION_H
#define SIMULATION_H

#include "simulation.h"
#include "squarecell.h"
#include "nourriture.h"
#include "fourmiliere.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Simulation {
	
	void lecture(char* nom_fichier);

	void decodage_ligne(std::string line);

	enum Etat_lecture {NBN, NOURRITURE, NBF, FOURMILIERE};

	static int etat = nbN;
	static int count = 0, countC = 0, countD = 0, countP = 0, total = 0, countF = 0;
	int x1, y1, age, x, y, side, total_food, nbC, nbD, nbP, totF;
	bool foodb;
	string foods;

	vector<Nourriture> vnourriture;
	vector<Fourmiliere> vfourmiliere;
};

#endif