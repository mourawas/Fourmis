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

	switch(etat)
	{
	case NBN:
		data >> total_food;
		count = 0;
		if(total_food == 0){
			etat = nbF;
		}
		else etat = Nourriture;
		break;
		
	case NOURRITURE:
		decodage_ligne_nourriture(line, vnourriture, grille)
		++count;
		if(count == total){
			etat = NBF;
		}
		break;
		
	case NBF:
		data >> totF;
		if(totF == 0){
			message::success();
			exit(EXIT_SUCCESS);
		}
		else if(totF > maxF){
			exit(EXIT_FAILURE);
		}
		else etat = FOURMILIERE;
		break;
		
	case FOURMILIERE:
		if(countF == totF){
			break;
		}
        
		// Mettre dans une classe
		// Une fois que countC = nbC, on passe a Def
		// Quand Pro est fini, si encore fourmiliere on revient ici
            
		//cout << "Fourmiliere " << countF << " : " << x << " " << y << " " << side << " " << x1 << " " << y1 << " " << total_food << " " << nbC << " " << nbD << " " << nbP << endl;
		
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
		//cout << "Defensor " << countD << " : " <<  x1 << " " << y1 << " " << age << endl;
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
		//cout << "Protector " << countP << " : " <<  x1 << " " << y1 << " " << age << endl;
		
		++countF;
		
		break;
	}
            
}