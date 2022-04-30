//simulation.cc
//Mouhamad: 50%
//Louis: 50%
#include "simulation.h"
using namespace std;

int Simulation::etat = 0;
int Simulation::count = 0;
int Simulation::total_food = 0;
int Simulation::totF = 0;

void Simulation::lecture(char * nom_fichier)
{
    string line;
    ifstream fichier(nom_fichier); 
    if(!fichier.fail()) 
    {
        while(getline(fichier >> ws,line)) 
        {
			if(line[0]=='#')  continue;  
       
			decodage_ligne(line);
        }
        
        cout << message::success();
	}
	else {
		exit(0);
	}	
}

void Simulation::decodage_ligne(string line){
	enum Etat_lecture {NBN, NOURRITURE, NBF, FOURMIL};
	istringstream data(line);
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
		if(decodage_ligne_nourriture(line, vnourriture)){
			tout_supprimer();
		}
		++count;
		if (count == total_food) {
			etat = NBF;
		}
		break;

	case NBF:
		data >> totF;
		count = 0;
		etat = FOURMIL;
		break;

	case FOURMIL:
		if(decodage_ligne_fourmiliere(line, vfourmiliere, totF)){
			tout_supprimer();
		}
		break;
	}
}

void Simulation::lancement(char* nom_fichier){
	initialiseGrille();
	lecture(nom_fichier);
}

void Simulation::tout_supprimer(){
	vfourmiliere.clear(); //suppression des vfourmis automatique !!
	vnourriture.clear();  // ^ faute cheloue ici, p.52 mooc explication
	etat = NBN, count = 0, total_food = 0, totF = 0;
}
//dear assistant if you see this trust me we spent 2h with an assistant debugging
//this. it's automatically deleted no need to delete vfourmis of every
//fourmiliere because we're using unique_ptr !!