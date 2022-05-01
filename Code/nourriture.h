#ifndef NOURRITURE_H_INCLUDED
#define NOURRITURE_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <string> 
#include <fstream>
#include <sstream>
#include "constantes.h"
#include "message.h"
#include "squarecell.h"

class Nourriture{
	private:
	unsigned int x, y;

	public:
	Nourriture(unsigned int x_, unsigned int y_) : x(x_), y(y_) {}
	~Nourriture() {};
    void dessin_nourriture();
	void ecrire_nourriture(std::ofstream& fichier);
};

bool decodage_ligne_nourriture(std::string line, std::vector<Nourriture>& vnourriture);

#endif
