#include <vector>
#include "squarecell.h"
#include "error_squarecell.h"
using namespace std;

struct Carre {
	unsigned int x;
	unsigned int y;
	unsigned int dim;
};

void initialiseGrille(vector<vector<bool> > & grille, const unsigned int& g_max);
 
void initialiseCarre(vector<vector<bool> > & grille, Carre& c, const unsigned int& g_max);

void supprimerCarre(vector<vector<bool> > & grille, Carre& c, const unsigned int& g_max);

bool superposition(vector<vector<bool> > & grille, Carre& c1, Carre& c2, const unsigned int& g_max);

void testCarre(vector<vector<bool> > & grille, Carre& c, const unsigned int& g_max);

void afficheGrille(vector<vector<bool> > & grille);

Carre creeCarre(unsigned int& x, unsigned int& y, unsigned int& dim);

void vectCarre(vector<Carre>& vcarre, Carre c);

bool multisuperposition (vector <Carre>& v, vector<vector<bool> >& grille, const unsigned int& g_max);

void initialise_Carre_centre ( vector<vector<bool> >& grille, Carre c, unsigned int g_max);

bool Carre_dans_Carre (Carre& c1, Carre& c2, vector< vector< bool> >& grid,unsigned int g_max);
