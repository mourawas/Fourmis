#include "squarecell.h"
#include "error_squarecell.h"
#include <vector>
#include <iostream>
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
	    
    if (c.p.x > (g_max)) {
        cout << error_squarecell::print_index(c.p.x, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if (c.p.y > (g_max)) {
        cout << error_squarecell::print_index(c.p.x, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if ((c.p.x + c.dim) > (g_max)) {
        cout << error_squarecell::print_outside(c.p.x, c.dim, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if ((c.p.y + c.dim) > (g_max)) {
        cout << error_squarecell::print_outside(c.p.y, c.dim, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
}

void initialiseCarre(vector<vector<bool> > & grille, Carre& c, const unsigned int& g_max) {
    for (size_t i = c.p.y; i <c.p.y + c.dim; ++i) {
        for (size_t j = c.p.x; j < c.p.x + c.dim; ++j) {
            grille[g_max-1-i][j] = true;
        }
    }
}

bool superposition(vector<vector<bool> > & grille, Carre& c1, Carre& c2, const unsigned int& g_max) {
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
    for (size_t i = c.p.y; i < c.p.y + c.dim; ++i) {
        for (size_t j = c.p.x; j < c.p.x + c.dim; ++j) {
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
