#include "simulation.h"
#include "squarecell.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	if(argc != 2){
		exit(0);
	}
	
	lecture(argv[1]);

    /*const unsigned int g_max = 10;
    vector<vector<bool> > grille;
    
    Point p1 = { 5, 5 };
    Point p2 = { 7, 7 };

    unsigned int dim1 = 2, dim2 = 5;

    initialiseGrille(grille, g_max);
    testCarre(grille, p1, dim1, g_max);
    testCarre(grille, p2, dim2, g_max);
    initialiseCarre(grille, p1, dim1, g_max);
    initialiseCarre(grille, p2, dim2, g_max);
    bool sup = superposition(grille, p1, p2, dim1, dim2, g_max);

    if (sup) {
        supprimerCarre(grille, p2, dim2, g_max);
        initialiseCarre(grille, p1, dim1, g_max);
    }

    afficheGrille(grille); */
}
