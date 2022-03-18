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

void testCarre(vector<vector<bool> > & grille, Point& p, unsigned int& dim, const unsigned int& g_max) {
	    
    if (p.x > (g_max)) {
        cout << error_squarecell::print_index(p.x, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if (p.y > (g_max)) {
        cout << error_squarecell::print_index(p.x, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if ((p.x + dim) > (g_max)) {
        cout << error_squarecell::print_outside(p.x, dim, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if ((p.y + dim) > (g_max)) {
        cout << error_squarecell::print_outside(p.y, dim, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
}

void initialiseCarre(vector<vector<bool> > & grille, Point& p, unsigned int& dim, const unsigned int& g_max) {
    for (size_t i = p.y; i <p.y + dim; ++i) {
        for (size_t j = p.x; j < p.x + dim; ++j) {
            grille[g_max-1-i][j] = true;
        }
    }
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
