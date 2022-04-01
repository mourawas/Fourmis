#include <vector>
#include <iostream>
#include "squarecell.h"
using namespace std;

void initialiseGrille(vector<vector<bool> > & grille, const unsigned int& g_max) {
    for (size_t i = 0; i < g_max; ++i) {
        grille.push_back(vector<bool>());
        for (size_t j = 0; j < g_max; ++j) {
            grille[i].push_back(false);
        }
    }
}

void testCarre(vector<vector<bool> > & grille, Carre& c, const unsigned int& g_max) {
	    
    if (c.x > (g_max)) {
        cout << error_squarecell::print_index(c.x, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if (c.y > (g_max)) {
        cout << error_squarecell::print_index(c.x, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if ((c.x + c.dim) > (g_max)) {
        cout << error_squarecell::print_outside(c.x, c.dim, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if ((c.y + c.dim) > (g_max)) {
        cout << error_squarecell::print_outside(c.y, c.dim, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
}

void initialiseCarre(vector<vector<bool> >& grille, Carre& c, const unsigned int& g_max) {
    for (size_t i = c.y; i < c.y + c.dim; ++i) {
        for (size_t j = c.x; j < c.x + c.dim; ++j) {
            grille[g_max-1-i][j] = true;
        }
    }
}

Carre creeCarre(unsigned int& x,unsigned int& y, unsigned int& dim)
{
	Carre c = {x, y, dim};
    return c;
}

void vectCarre(vector<Carre>& vcarre, Carre c)
{	
	vcarre.push_back(c);
}

bool superposition(vector<vector<bool> >& grille, Carre& c1, Carre& c2, const unsigned int& g_max) {
    unsigned int compteur = 0;
    for (size_t i = 0; i < g_max; ++i) {
        for (size_t j = 0; j < g_max; ++j) {
            if(grille[i][j] == true){
                ++compteur;
            }
        }
    }
    if (compteur != ((c1.dim * c1.dim) + (c2.dim * c2.dim))) {
        return true;
    }
    return false;
}

void supprimerCarre(vector<vector<bool> > & grille, Carre& c, const unsigned int& g_max) {
    for (size_t i = c.y; i < c.y + c.dim; ++i) {
        for (size_t j = c.x; j < c.x + c.dim; ++j) {
            grille[g_max-1-i][j] = false;
        }
    }
}

void afficheGrille(vector<vector<bool> > & grille){
	for(auto ligne : grille){
		for(auto kase : ligne){
			if(!kase){
				cout << "|___";
				
			}else{
				cout << "|_X_";
			}
		}
		cout << endl;
	}
}

/*bool multisuperposition ( vector <Carre>& v,vector < vector<bool> >& grille, const unsigned int& g_max)
{
    for (size_t i(0); i < v.size(); ++i){
        for (size_t j(i+1);j < v.size(); ++j){
            if(superposition(grid, v[i], v[j], g_max) == 0){
                cout << "passage"<< endl;
                return true;
            }
        }
    }
    return false;
}*/

//Tester les éléments dans l'ordre qu'ils sont lus (pas à faire ici)
//Si deux elements se superposent, pas grave pour rendu 1

bool multisuperposition(vector<Carre>& v, vector<vector<bool> > grille, const unsigned int& g_max)
{
	
	
	
}

/*bool Carre_dans_Carre(Carre& c1, Carre& c2, vector< vector< bool> >& grille, const unsigned int& g_max) {
    bool t;
    if (c2.dim > c1.dim){
        t = true;
        return t;
    }
    unsigned int compteur = 0;
    for (size_t i = 0; i < g_max; ++i) {
        for (size_t j = 0; j < g_max; ++j) {
            if(grille[i][j] == true){
                ++compteur;
            }
        }
    }
    if (compteur != (c1.dim * c1.dim)){
        t=true;
    }
    return false;
}*/

void initialise_Carre_centre ( vector<vector<bool> >& grille, Carre c, unsigned int g_max)
{
    unsigned int t = (c.x - c.dim%2);
    cout << t << endl;
    unsigned int k = (c.y - c.dim%2);
    cout << k << endl;
    Carre nc = creeCarre ( t,k,c.dim);
    initialiseCarre ( grille,nc, g_max);
}
