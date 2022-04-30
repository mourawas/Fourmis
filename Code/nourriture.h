#ifndef HEADERN_H
#define HEADERN_H
#include <iostream>
#include <vector>
#include <string>
#include "constantes.h"
#include "message.h"
#include "squarecell.h"
#include <cstdlib>
#include <string> 
#include <fstream>
#include <sstream>
using namespace std;

class Nourriture{
	private:
	unsigned int x, y;

	public:
	Nourriture(unsigned int x_, unsigned int y_)
	: x(x_), y(y_) {}
	~Nourriture() {};
	
};

bool decodage_ligne_nourriture(string line, vector<Nourriture>& vnourriture);

#endif
