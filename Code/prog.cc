#include "simulation.h"
#include "squarecell.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	/*if(argc != 2){
		exit(0);
	}
	
	lecture(argv[1]);*/
	
	
	const unsigned int g_max = 10;
    vector<vector<bool> > grille;
    vector<Carre> E_c_f;
    vector<Carre> E_c_i;
    
    Carre c1 = {{ 5, 5 }, 2};
    Carre c2 = {{ 7, 7 }, 3};
    Carre c3 = {{4, 4}, 2};
    
    
    
    /*E_c_i.push_pack(c1);
    E_c_i.push_pack(c2);
    E_c_i.push_pack(c3);
    
    E_c.push_back(c1);*/

    initialiseGrille(grille, g_max);
    testCarre(grille, c1, g_max);
    testCarre(grille, c2, g_max);
    initialiseCarre(grille, c1, g_max);
    initialiseCarre(grille, c2, g_max);
    bool sup = superposition(grille, c1, c2, g_max);

    if (sup) {
        supprimerCarre(grille, c2, g_max);
        initialiseCarre(grille, c1, g_max);
    }

    afficheGrille(grille);
}
