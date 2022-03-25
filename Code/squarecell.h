#include <vector>
using namespace std;

struct Point {
    unsigned int x;
    unsigned int y;
};

struct Carre {
	Point p;
	unsigned int dim;
};

void initialiseGrille(vector<vector<bool> > & grille, const unsigned int& g_max);
 
void initialiseCarre(vector<vector<bool> > & grille, Carre& c, const unsigned int& g_max);

void supprimerCarre(vector<vector<bool> > & grille, Carre& c, const unsigned int& g_max);


bool superposition(vector<vector<bool> > & grille, Carre& c1, Carre& c2, const unsigned int& g_max);

void testCarre(vector<vector<bool> > & grille, Carre& c, const unsigned int& g_max);

void afficheGrille(vector<vector<bool> > & grille);

Carre creeCarre (unsigned int& x,unsigned int& y, unsigned& dim);

void multisuperposition ( vector <Carre> v);
