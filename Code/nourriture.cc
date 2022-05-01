//nourriture.cc
//Mouhamad: 50%
//Louis: 50%
#include "nourriture.h"
using namespace std;

bool decodage_ligne_nourriture(string line, vector<Nourriture>& vnourriture){
	unsigned int x, y;

	istringstream data(line);
	data >> x >> y;
	
	unsigned int sizeN = 1;
	Nourriture n(x, y);
	Carre c = {x, y, sizeN};
		
	if(testCarreCentre(c)) return true;
		
	unsigned int x1, y1;
	if(supCoord(c, x1, y1)){
		cout << message::food_overlap(x, y);
		return true;
	}
	initialiseCarre(c);
	vnourriture.push_back(n);
	return false;
}
void Nourriture::dessin_nourriture(){
    dessin_losange(x, y, 1., 1., 1.);
}

void Nourriture::ecrire_nourriture(ofstream& fichier){
	fichier << to_string(x) << " " << to_string(y) << "\n";
}