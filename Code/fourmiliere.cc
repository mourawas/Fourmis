#include <iostream>
#include "squarecell.h"
#include "fourmis.h"
#include "nourriture.h"
#include "fourmiliere.h"
#include "message.h"

void pushbackF (unsigned int& x, unsigned int& y, unsigned int& side , unsigned int& x1, unsigned int& y1, unsigned int& total_food, unsigned int& nbC, unsigned int& nbD, unsigned int& nbP)
{
	
	unsigned int a = 3;
	Carre c;
	Carre g;
    c = creeCarre(x,y,side);
    g = creeCarre(x1,y1,a);
     
    Fourmiliere fourmiliere (c,g, nbC, nbD, nbP, total_food);
    
    vectF.push_back(fourmiliere);
 }
