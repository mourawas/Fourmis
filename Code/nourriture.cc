//nourriture.cc
//Mouhamad: 50%
//Louis: 50%
#include "nourriture.h"

void decodage_ligne_nourriture(string line, vector<Nourriture>& vnourriture){
	unsigned int x, y;

	istringstream data(line);
	data >> x >> y;
	
	unsigned int sizeN = 1;
	Nourriture n(x, y);
	Carre c = {x, y, sizeN};
		
	testCarreCentre(c);
		
	unsigned int x1, y1;
	if(supCoord(c, x1, y1)){
		cout << message::food_overlap(x, y);
		exit(EXIT_FAILURE);
	}
	initialiseCarre(c);
	vnourriture.push_back(n);
}

