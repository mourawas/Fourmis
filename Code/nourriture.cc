#include "nourriture.h"

void decodage_ligne_nourriture(string line, vector<Nourriture>& vnourriture){
	
	unsigned int x, y;

	istringstream data(line);
	data >> x >> y;
	
	unsigned int sizeN = 1;
	Nourriture n(x, y);
	Carre c = creeCarre(x, y, sizeN);

	testCarre(c);
	unsigned int compteur = nbTrue();
	initialiseCarre(c);
	bool sup = supUnique(c, compteur);
	if (sup) {
		cout << message::food_overlap(x, y) << endl;
		exit(EXIT_FAILURE);
	}
	vnourriture.push_back(n);

}

