#include <vector>
#include <iostream>
#include "squarecell.h"
using namespace std;

static grille grid;

void initialiseGrille(const unsigned int& g_max) {
    for (size_t i = 0; i < g_max; ++i) {
        grid.push_back(vector<bool>());
        for (size_t j = 0; j < g_max; ++j) {
            grid[i].push_back(false);
        }
    }
}

void testCarre(Carre& c, const unsigned int& g_max) {
	    
    if (c.x > (g_max)) {
        cout << error_squarecell::print_index(c.x, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if (c.y > (g_max)) {
        cout << error_squarecell::print_index(c.x, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if ((c.x + c.side) > (g_max)) {
        cout << error_squarecell::print_outside(c.x, c.side, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
    else if ((c.y + c.side) > (g_max)) {
        cout << error_squarecell::print_outside(c.y, c.side, g_max-1) << endl;
        exit(EXIT_FAILURE);
    }
}

void initialiseCarre(Carre& c, const unsigned int& g_max) {
    for (size_t i = c.y; i < c.y + c.side; ++i) {
        for (size_t j = c.x; j < c.x + c.side; ++j) {
            grid[g_max-1-i][j] = true;
        }
    }
}

void supCoord(Carre c, unsigned& x, unsigned& y) {
    for (size_t i(g_max - 1 - (c.y-c.side/2); i > g_max - 1 - (c.y - c.side / 2)-c.side; --i) {
        for (size_t j(c.x-c.side/2); j <= c.x+c.side/2; ++j) {
            if (grid[i][j] == true) {
                x = j;
                y = i;
            }
        }
    }

}

Carre creeCarre(unsigned int& x,unsigned int& y, unsigned int& side)
{
	Carre c = {x, y, side};
    return c;
}

void vectCarre(vector<Carre>& vcarre, Carre c)
{	
	vcarre.push_back(c);
}

unsigned int nbTrue()
{
    unsigned int compteur = 0;
    for (size_t i = 0; i < g_max; ++i) {
        for (size_t j = 0; j < g_max; ++j) {
            if (grid[i][j]) {
                ++compteur;
            }
        }
    }
    return compteur;
}

bool sup(Carre& c1, Carre& c2, const unsigned int& g_max) {
    unsigned int compteur = nbTrue(grid);
    if (compteur != ((c1.side * c1.side) + (c2.side * c2.side))) {
        return true;
    }
    return false;
}

bool supUnique(Carre& c, unsigned int& compteur) {
    if (compteur == (compteur + c.side*c.side)) {
        return true;    //superposition
    }
    return false;       //pas sup
}


void supprimerCarre(Carre& c, const unsigned int& g_max) {
    for (size_t i = c.y; i < c.y + c.side; ++i) {
        for (size_t j = c.x; j < c.x + c.side; ++j) {
            grid[g_max-1-i][j] = false;
        }
    }
}

void afficheGrille(grille& grid){
	for(auto ligne : grid){
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

/*bool multisup(vector <Carre>& v, const unsigned int& g_max)
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

bool Carre_dans_Carre(Carre& c1, Carre& c2, const unsigned int& g_max) {
    bool t;
    if (c2.side > c1.side){
        t = false;
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
    if (compteur != (c1.side * c1.side)){
        t=false;
    }
    return true;
}*/

void initialise_Carre_centre (Carre c, unsigned int g_max)
{
    unsigned int t = (c.x - c.side%2);
    cout << t << endl;
    unsigned int k = (c.y - c.side%2);
    cout << k << endl;
    Carre nc = creeCarre (t, k, c.side);
    initialiseCarre (grille, nc, g_max);
}
