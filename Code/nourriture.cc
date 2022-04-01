#include <iostream>
#include "nourriture.h"

void decodage_ligne_nourriture(string line, vector<Nourriture>& vnourriture){
	
	unsigned int x, y;

	isstringstream line(data);
	data >> x >> y;

	Nourriture n(x, y);
	c = creeCarre(x, y, 1);

	testCarre(c);
	unsigned int compteur = nbTrue();
	intialiseCarre(c);
	bool sup = supUnique(c, compteur);
	if (sup) {
		cout << message::food_overlap(x, y) << endl;
		exit(EXIT_FAILURE);
	}
	vnourriture.push_back(n);

}

