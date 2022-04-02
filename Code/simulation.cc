#include "simulation.h"
using namespace std;

void lecture(char * nom_fichier, vector<Fourmiliere>& vfourmiliere, vector<Nourriture>& vnourriture)
{
    string line;
    ifstream fichier(nom_fichier); 
    if(!fichier.fail()) 
    {
        while(getline(fichier >> ws,line)) 
        {
			if(line[0]=='#')  continue;  
       
			decodage_ligne(line, vfourmiliere, vnourriture);
        }
        cout << "SUCCES" << endl;
	}
	else {
		exit(0);
	}	
}

void decodage_ligne(string line, vector<Fourmiliere>& vfourmiliere, vector<Nourriture>& vnourriture){
	
	unsigned int totF, total_food;
	istringstream data(line);

	switch (etat)
	{
	case NBN:
		data >> total_food;
		count = 0;
		if (total_food == 0) {
			etat = NBF;
		}
		else etat = NOURRITURE;
		break;

	case NOURRITURE:
		decodage_ligne_nourriture(line, vnourriture);
		++count;
		if (count == total_food) {
			etat = NBF;
		}
		break;

	case NBF:
		data >> totF;
		if (totF == 0) {
			message::success();
			exit(EXIT_SUCCESS);
		}
		else if (totF > maxF) {
			exit(EXIT_FAILURE);
		}
		else etat = FOURMIL;
		break;

	case FOURMIL:
		decodage_ligne_fourmiliere(line, vfourmiliere, totF);

		break;
	}
}

void Simulation::lancement(char* nom_fichier){
	lecture(nom_fichier, vfourmiliere, vnourriture);
}
