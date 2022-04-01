#include <iostream>
#include "nourriture.h"

void decodage_ligne_food(string line, vector<Nourriture>& vnourriture, grille& grille){
	
	unsigned int x, y;

	isstringstream line(data);
	data >> x >> y;

	Nourriture n(x, y);
	c = creeCarre(x, y, 1);

	testCarre(grille, c, g_max);
	unsigned int compteur = nbTrue(grille);
	intialiseCarre(grille, c, g_max);
	bool sup = sup_unique(grille, c, g_max, compteur);


	vnourriture.push_back(n);

}

