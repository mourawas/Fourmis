#include <vector>
#include <iostream>
using namespace std;

struct Point {
    unsigned int x;
    unsigned int y;
};

void initialiseGrille(vector<vector<bool> > & grille, const unsigned int& g_max);
 
void initialiseCarre(vector<vector<bool> > & grille, Point& p, unsigned int& dim);

void supprimerCarre(vector<vector<bool> > & grille, Point& p, unsigned int& dim);

bool superposition(vector<vector<bool> > & grille, Point& p1, Point& p2, unsigned int& dim1, unsigned int& dim2, const unsigned int& g_max);

void testCarre(vector<vector<bool> > & grille, Point& p, unsigned int& dim, const unsigned int& g_max);
