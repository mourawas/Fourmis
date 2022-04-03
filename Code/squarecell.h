#ifndef HEADERSQ_H
#define HEADERSQ_H
#include <iostream>
#include <vector>
#include <cmath>
#include "squarecell.h"
#include "error_squarecell.h"
using namespace std;

typedef vector<vector<bool> > grille;

constexpr short unsigned g_dim(7);
constexpr short unsigned g_max(pow(2,g_dim));

struct Carre {
	unsigned int x;
	unsigned int y;
	unsigned int side;
};

void initialiseGrille();
 
void initialiseCarre(Carre& c);

void supprimerCarre(Carre& c);

unsigned int nbTrue();

bool supFourmiliere(Carre& c1, Carre& c2);

bool sup(Carre& c1, Carre& c2);

bool supUnique(Carre& c, unsigned int& compteur);

unsigned int nbTrue();

bool supCoord(Carre c, unsigned& x, unsigned& y);

void testCarre(Carre& c);

void testCarreCentre(Carre& c);

void afficheGrille();

void initialise_Carre_Centre(Carre& c);

bool Carre_dans_Carre(Carre& c1, Carre& c2);

#endif
