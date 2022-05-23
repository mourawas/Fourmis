#ifndef SQUARECELL_H_INCLUDED
#define SQUARECELL_H_INCLUDED
#include <iostream>
#include <vector>
#include <cmath>
#include "error_squarecell.h"
#include "graphic.h"

typedef std::vector<std::vector<bool> > grille;

constexpr short unsigned g_dim(7);
//constexpr short unsigned g_max(pow(2,g_dim));
constexpr short unsigned g_max(128);

struct Carre {
	unsigned int x;
	unsigned int y;
	unsigned int side;
};

void initialise_grille();
 
void initialise_carre(Carre& c);

void supprimer_carre(Carre& c);

bool sup_carre(Carre& c1, Carre& c2);

bool sup(unsigned int& x, unsigned int& y);

bool sup_coord(Carre c, unsigned& x, unsigned& y);

bool test_carre(Carre& c);

bool test_carre_centre(Carre& c);

void initialise_carre_centre(Carre& c);

bool carre_dans_carre(Carre& c1, Carre& c2);

bool point_dans_carre(unsigned int& x, unsigned int& y, Carre& c);

void dessin_carre_croix(unsigned int x,unsigned int y, double size, double r, double g, double b);

void dessin_carre_plus(unsigned int x, unsigned int y, double size, double r, double g, double b);

void dessin_carre_plein(unsigned int x, unsigned int y, double size, double r, double g, double b);

void dessin_losange(unsigned int x, unsigned int y, double r, double b, double g);

void dessin_carre_vide(unsigned int x, unsigned int y, double size, double r, double g, double b);

void vide_grille();

bool carre_libre_dans_carre(Carre& c);

void deplace_carre_digaonale(Carre& c, unsigned int dir);

int abso(int a);

bool point_dans_carre_centre(unsigned int& x, unsigned int& y, Carre& c);

void dessin_losange_carre_croix(unsigned int x, unsigned int y, double size, double r,
                        double g, double b);

#endif
