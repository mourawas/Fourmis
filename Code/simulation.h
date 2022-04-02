#ifndef HEADERS_H
#define HEADERS_H

#include "squarecell.h"
#include "nourriture.h"
#include "fourmiliere.h"
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
	
};

void lecture(char* nom_fichier, vector<Fourmiliere>& vfourmiliere, vector<Nourriture>& vnourriture);
void decodage_ligne(string line, vector<Fourmiliere>& vfourmiliere, vector<Nourriture>& vnourriture);

enum Etat_lecture {NBN, NOURRITURE, NBF, FOURMIL};

static unsigned int etat(NBN);
static unsigned int count(0);

#endif
