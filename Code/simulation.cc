//simulation.cc
//Mouhamad: 50%
//Louis: 50%
#include "simulation.h"
using namespace std;

default_random_engine e;

int Simulation::etat = 0;
int Simulation::count = 0;
int Simulation::total_food = 0;
int Simulation::totF = 0;

bool Simulation::lecture(char * nom_fichier)
{
    string line;
    ifstream fichier(nom_fichier); 
    if(!fichier.fail()) 
    {
        while(getline(fichier >> ws,line)) 
        {
			if(line[0]=='#')  continue;  
       
			if(decodage_ligne(line)){
				return true;
			}
        }
        cout << message::success();
		return false;
	}
	else{
		exit(0);
	}
	return false;
}

bool Simulation::decodage_ligne(string line){
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
		return false;
	case NOURRITURE:
		if(decodage_ligne_nourriture(line, vnourriture)){
			return true;
		}
		++count;
		if (count == total_food) {
			etat = NBF;
		}
		return false;
	case NBF:
		data >> totF;
		count = 0;
		etat = FOURMIL;
		return false;
	case FOURMIL:
		if(decodage_ligne_fourmiliere(line, vfourmiliere, totF)){
			return true;
		}
		return false;
	}
	return false;
}

void Simulation::lancement(char* nom_fichier){
	initialise_grille();
	if(lecture(nom_fichier)){		//erreur
		tout_supprimer();
	}else{							//good
		
	}
}

void Simulation::sim_affiche(){
	for (size_t i = 0; i < vfourmiliere.size(); ++i)
		{
			vfourmiliere[i].d_anthill(i);
		}
		for (size_t i = 0; i < vnourriture.size(); ++i)
		{
			vnourriture[i].dessin_nourriture();
		}	
}

void Simulation::tout_supprimer(){
	vfourmiliere.clear(); //suppression des vfourmis automatique !
	vnourriture.clear();
	re();
	vide_grille();
	etat = NBN, count = 0, total_food = 0, totF = 0;
}

void Simulation::ecrire_fichier(ofstream& fichier){
	fichier << to_string(vnourriture.size()) << "\n\n";
	for (size_t i = 0; i < vnourriture.size(); ++i) {
		vnourriture[i].ecrire_nourriture(fichier);
	}
	fichier << "\n" << to_string(vfourmiliere.size()) << "\n";
	for (size_t i = 0; i < vfourmiliere.size(); ++i){
		vfourmiliere[i].ecrire_fourmiliere(fichier);
	}
}

int Simulation::get_taillevf(){
	return vfourmiliere.size();
}

unsigned int Simulation::get_taillevn(){
	return vnourriture.size();
}

unsigned int Simulation::get_total_food(int& id){
	return vfourmiliere[id].get_total_food();
}

unsigned int Simulation::get_nbC(int& id){
	return vfourmiliere[id].get_nbC();
}

unsigned int Simulation::get_nbD(int& id){
	return vfourmiliere[id].get_nbD();
}

unsigned int Simulation::get_nbP(int& id){
	return vfourmiliere[id].get_nbP();
}

void Simulation::creer_nourriture(){
	
	uniform_int_distribution<unsigned> u(1, g_max-2);
	unsigned int x = u(e), y = u(e);
	Nourriture n(x, y);
	vnourriture.push_back(n);
}