#include <string>
#include "nourriture.h"
#include "fourmiliere.h"

void lecture(char* nom_fichier);

void decodage_ligne(std::string line);

vector <Fourmiliere> pushbackF (unsigned int& x, unsigned int& y, unsigned int& side , unsigned int& x1, unsigned int& y1, unsigned int& total_food, unsigned int& nbC, unsigned int& nbD, unsigned int& nbP);

vector <Fourmiliere> vectF ;
vector <Carre> vectC;