#include <vector>
#include "squarecell.h"
#include "error_squarecell.h"
using namespace std;

typedef vector<vector<bool> > grille;

const unsigned int g_max = 20;

struct Carre {
	unsigned int x;
	unsigned int y;
	unsigned int side;
};

void initialiseGrille(grille& grille, const unsigned int& g_max);
 
void initialiseCarre(grille& grille, Carre& c, const unsigned int& g_max);

void supprimerCarre(grille& grille, Carre& c, const unsigned int& g_max);

unsigned int nbTrue(grille& grille);

bool sup(grille& grille, Carre& c1, Carre& c2, const unsigned int& g_max);

bool supUnique(grille& grille, Carre& c, unsigned int& compteur);

unsigned int nbTrue();

void supCoord(Carre c, unsigned& x, unsigned& y);

void testCarre(grille& grille, Carre& c, const unsigned int& g_max);

void afficheGrille(grille& grille);

Carre creeCarre(unsigned int& x, unsigned int& y, unsigned int& dim);

void vectCarre(vector<Carre>& vcarre, Carre c);

bool multisup(vector<Carre>& v, grille& grille, const unsigned int& g_max);

void initialise_Carre_centre(grille& grille, Carre c, unsigned int g_max);

bool Carre_dans_Carre(Carre& c1, Carre& c2, grille& grille, unsigned int g_max);
