#ifndef HEADERSQ_H
#define HEADERSQ_H
#include <iostream>
#include <vector>
#include "squarecell.h"
#include "error_squarecell.h"
using namespace std;

typedef vector<vector<bool> > grille;

const unsigned int g_max = 128;

struct Carre {
	unsigned int x;
	unsigned int y;
	unsigned int side;
};

void initialiseGrille();
 
void initialiseCarre(Carre& c);

void supprimerCarre(Carre& c);

unsigned int nbTrue();

bool sup(Carre& c1, Carre& c2);

bool supUnique(Carre& c, unsigned int& compteur);

unsigned int nbTrue();

void supCoord(Carre c, unsigned& x, unsigned& y);

void testCarre(Carre& c);

void afficheGrille();

Carre creeCarre(unsigned int& x, unsigned int& y, unsigned int& dim);

void initialise_Carre_Centre(Carre& c);

bool Carre_dans_Carre(Carre& c1, Carre& c2);

#endif
