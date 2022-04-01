#include <iostream>
#include "nourriture.h"

void Nourriture::launchNourriture(){
	
	Carre c = creeCarre(x, y, 1);

	vnourriture.push_back(c);
}
