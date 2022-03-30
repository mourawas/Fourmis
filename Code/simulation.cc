#include "simulation.h"
#include "squarecell.h"
#include "nourriture.h"
#include "fourmiliere.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void lecture(char * nom_fichier)
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
        cout << "fin de la lecture" << endl;
	}
	else {
		exit(0);
	}	
}

void decodage_ligne(string line){
	
	enum Etat_lecture {nbN, Nourriture, nbF, Fourmiliere, Col, Def, Pro, Fini};
	
	istringstream data(line);
	
	static int etat = nbN;
	static int count = 0, countC = 0, countD = 0, countP = 0, total = 0, countF = 0;
	int x1, y1, age, x, y, side, total_food, nbC, nbD, nbP, totF;
	bool foodb;
	string foods;
	
	switch(etat)
	{
            
	case nbN:
		data >> total;
		count = 0;
		if(total == 0){
			etat = nbF;
		}else {
			etat = Nourriture;
		}
		//Mettre dans une classe
		cout << "Nombre nourriture : " << total << endl;
		break;
		
	case Nourriture:
		data >> x1 >> y1;
		++count;
		if(count == total){
			etat = nbF;
		}
		//Mettre dans une classe
		cout << "Nourriture " << count << " : " << x1 << " " << y1 << endl;
		break;
		
	case nbF:
		data >> totF;
		if(totF == 0){
			etat = Fini;
		}else{
			etat = Fourmiliere;
		}
		//Mettre dans une classe
		break;
		
	case Fourmiliere:
		if(countF == totF){
			etat = Fini;
			break;
		}
		data >> x >> y >> side >> x1 >> y1 >> total_food >> nbC >> nbD >> nbP;
        creeCarre cF (x,y,side);
        creeCarre cf (x,y,size_G);
        Fourmiliere fourmiliere (cF,cf,total_food,nbC,nbD,nbP);
        if (Fourmiliere.verification(grille,fourmiliere,vectF){
            vectF.pushback(fourmiliere);
        };
		// Mettre dans une classe
		// Une fois que countC = nbC, on passe a Def
		// Quand Pro est fini, si encore fourmiliere on revient ici
        //pushbckackF(x,y,side,x1,y1,total_food,nbC,nbD,nbP);
        
         
            
		cout << "Fourmiliere " << countF << " : " << x << " " << y << " " << side << " " << x1 << " " << y1 << " " << total_food << " " << nbC << " " << nbD << " " << nbP << endl;
		
		if(nbC) {
			etat = Col;
		}else if(nbD) {
			etat = Def;
		}else if(nbP) {
			etat = Pro;
		}else {
			++countF;
			etat = Fourmiliere;
		}
			
		countC = 0, countD = 0, countP = 0;
		//cout << nbP << endl;
		break;
		
	case Col:
		if(nbC == 0){
			etat = Def;
			break;
		}
		//on arrive pas ici 2e fourmil
		++countC;
		data >> x1 >> y1 >> age >> foods;
		if(countC == nbC){
			etat = Def;
		}
		if(foods == "true"){
			foodb = 1;
		}else{
			foodb = 0;
		}
		
		//Mettre dans une classe
		cout << "Collector " << countC << " : " <<  x1 << " " << y1 << " " << age << " " << foodb << endl;
		break;
		
	case Def:
		if(nbD == 0){
			etat = Pro;
			break;
		}
		++countD;
		data >> x1 >> y1 >> age;
		if(countD == nbD){
			etat = Pro;
		}
		//Mettre dans une classe
		cout << "Defensor " << countD << " : " <<  x1 << " " << y1 << " " << age << endl;
		break;

	case Pro:
		if(nbP == 0){
			etat = Fourmiliere;
			++countF;
			break;
		}
		++countP;
		data >> x1 >> y1 >> age;
		
		if(countP == nbP){
			etat = Fourmiliere;
		}
		//Mettre dans une classe
		cout << "Protector " << countP << " : " <<  x1 << " " << y1 << " " << age << endl;
		
		++countF;
		
		break;
	
	case Fini:
		cout << "Fini" << endl;
		break;
	}
}
/*vector < Fourmiliere > pushbackF (unsigned int& x, unsigned int& y, unsigned int& side , unsigned int& x1, unsigned int& y1, unsigned int& total_food, unsigned int& nbC, unsigned int& nbD, unsigned int& nbP)
{
    
    unsigned int a = 3;
    Carre c;
    Carre g;
    c = creeCarre(x,y,side);
    g = creeCarre(x1,y1,a);
     
    Fourmiliere fourmiliere (c,g, nbC, nbD, nbP, total_food);
    
    vectF.push_back(fourmiliere);
    return vectF;
 }
vector< Carre > extraction_vector ( vector <Fourmiliere>& vectF)
{
    vector < Carre > vectC;
    for (size_t i(0); i < vectF.size(); ++i)
    {
        vectC.push_back(vectF[i].getcarref());
    }
    return vectC;
}*/
