#include <iostream>
#include "message.h"
#include "squarecell.h"
#include "nourriture.h"
#include "constantes.h"

//Lancer 1 fois pour verification, 1 fois définitivement
//après vérification

Nourriture::launchNourriture(){
	
	Carre c = creeCarre(x, y, 1);
	vectCarre(temp, c);
}
