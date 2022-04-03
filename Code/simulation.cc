//simulation.cc
//Mouhamad: 50%
//Louis: 50%
#include "simulation.h"
using namespace std;

void lecture(char * nom_fichier, vector<Fourmiliere>& vfourmiliere,
             vector<Nourriture>& vnourriture)
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
        cout << message::success();
	}
	else {
		exit(0);
	}	
}

void decodage_ligne(string line, vector<Fourmiliere>& vfourmiliere,
                    vector<Nourriture>& vnourriture){
	enum Etat_lecture {NBN, NOURRITURE, NBF, FOURMIL};
	istringstream data(line);
	static unsigned int etat(NBN);
	static unsigned int count(0), total_food(0), totF(0);
	switch (etat)
	{
	case NBN:
		data >> total_food;
		
		if (!total_food) {
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
		count = 0;
		//cout << "totF : " << totF << endl;
		if (!totF) {
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
	initialiseGrille();
	lecture(nom_fichier, vfourmiliere, vnourriture);
}
