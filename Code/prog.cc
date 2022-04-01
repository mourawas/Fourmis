#include "simulation.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char * argv[])
{
	if(argc != 2){
		exit(0);
	}
	
	lecture(argv[1]);


    initialiseGrille();
    testCarre(c1);
    testCarre(c2);
    initialiseCarre(c1);
    initialiseCarre(c2);
    bool sup = sup(c1, c2);

    if (sup) {
        supprimerCarre(c2);
        initialiseCarre(c1);
    }

    afficheGrille();
}
