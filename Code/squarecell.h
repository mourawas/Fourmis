#ifndef HEADERSQ_H
#define HEADERSQ_H
#include <iostream>
#include <vector>
#include <cmath>
#include "error_squarecell.h"
#include "graphic.h"
using namespace std;

typedef vector<vector<bool> > grille;

constexpr short unsigned g_dim(7);
//constexpr short unsigned g_max(pow(2,g_dim));
constexpr short unsigned g_max(128);

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

bool testCarre(Carre& c);

bool testCarreCentre(Carre& c);

void afficheGrille();

void initialise_Carre_Centre(Carre& c);

bool Carre_dans_Carre(Carre& c1, Carre& c2);

void dessin_carre_croix(unsigned int x,unsigned int y, double size, double r, double g, double b);

void dessin_carre_plus(unsigned int x, unsigned int y, double size, double r, double g, double b);

void dessin_carre_plein(unsigned int x, unsigned int y, double size, double r, double g, double b);

void dessin_losange(unsigned int x, unsigned int y, double r, double b, double g);

void dessin_carre_vide(unsigned int x, unsigned int y, double size, double r, double g, double b);

#endif
