using namespace std;

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
        cout << "fin de la lecture" << endl;
	}
	else {
		exit(0);
	}	
}

void Simulation::decodage_ligne(string line){
	
	istringstream data(line);

	switch (etat)
	{
	case NBN:
		data >> total_food;
		count = 0;
		if (total_food == 0) {
			etat = nbF;
		}
		else etat = Nourriture;
		break;

	case NOURRITURE:
		decodage_ligne_nourriture(line, vnourriture, grille);
		++count;
		if (count == total) {
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
		else etat = FOURMILIERE;
		break;

	case FOURMILIERE:
		if (countF == totF) {
			break;
		}
		decodage_ligne_fourmiliere(line, vfourmiliere);

		break;
	}
}