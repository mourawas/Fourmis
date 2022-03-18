#include "squarecell.h"
#include "error_squarecell.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    const unsigned int g_max = 10;
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

    afficheGrille(grille);
}

void initialiseGrille(vector<vector<bool> > & grille, const unsigned int& g_max) {
    for (size_t i = 0; i < g_max; ++i) {
        grille.push_back(vector<bool>());
        for (size_t j = 0; j < g_max; ++j) {
            grille[i].push_back(false);
        }
    }
}

void testCarre(vector<vector<bool> > & grille, Point& p, unsigned int& dim, const unsigned int& g_max) {
	    
    if (p.x > (g_max)) {
        cout << error_squarecell::print_index(p.x, g_max) << endl;
        exit(EXIT_FAILURE);
    }
    else if (p.y > (g_max)) {
        cout << error_squarecell::print_index(p.x, g_max) << endl;
        exit(EXIT_FAILURE);
    }
    else if ((p.x + dim) > (g_max)) {
        cout << error_squarecell::print_outside(p.x, dim, g_max) << endl;
        exit(EXIT_FAILURE);
    }
    else if ((p.y + dim) > (g_max)) {
        cout << error_squarecell::print_outside(p.y, dim, g_max) << endl;
        exit(EXIT_FAILURE);
    }
    cout << "OK" << endl;
}

void initialiseCarre(vector<vector<bool> > & grille, Point& p, unsigned int& dim, const unsigned int& g_max) {
    for (size_t i = p.y; i <p.y + dim; ++i) {
        for (size_t j = p.x; j < p.x + dim; ++j) {
            grille[g_max-1-i][j] = true;
        }
    }
    cout << "OK inic" << endl;
}

bool superposition(vector<vector<bool> > & grille, Point& p1, Point& p2, unsigned int& dim1, unsigned int& dim2, const unsigned int& g_max) {
    unsigned int compteur = 0;
    for (size_t i = 0; i < g_max; ++i) {
        for (size_t j = 0; j < g_max; ++j) {
            if(grille[i][j] == true){
                ++compteur;
            }
        }
    }
    cout << "OK sup" << endl;
    if (compteur != ((dim1 * dim1) + (dim2 * dim2))) {
        return true;
    }
    return false;
}

void supprimerCarre(vector<vector<bool> > & grille, Point& p, unsigned int& dim, const unsigned int& g_max) {
    for (size_t i = p.y; i <p.y + dim; ++i) {
        for (size_t j = p.x; j < p.x + dim; ++j) {
            grille[g_max-1-i][j] = false;
        }
    }
    cout << "OK supprimer" << endl;
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
