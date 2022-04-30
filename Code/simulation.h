#ifndef HEADERS_H
#define HEADERS_H

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
	void lecture(char* nom_fichier);
	void decodage_ligne(string line);

	void tout_supprimer();
	
	enum Etat_lecture {NBN, NOURRITURE, NBF, FOURMIL};
	static int etat, count, total_food, totF;
};

#endif
