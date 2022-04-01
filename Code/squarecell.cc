#include <vector>
#include <iostream>
#include "squarecell.h"
using namespace std;

static grille grid;

void initialiseGrille() {
    for (size_t i = 0; i < g_max; ++i) {
        grid.push_back(vector<bool>());
        for (size_t j = 0; j < g_max; ++j) {
            grid[i].push_back(false);
        }
    }
}

void testCarre(Carre& c) {
	    
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

void initialiseCarre(Carre& c) {
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

bool sup(Carre& c1, Carre& c2) {
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


void supprimerCarre(Carre& c) {
    for (size_t i = c.y; i < c.y + c.side; ++i) {
        for (size_t j = c.x; j < c.x + c.side; ++j) {
            grid[g_max-1-i][j] = false;
        }
    }
}

void afficheGrille(){
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

bool Carre_dans_Carre(Carre& c1, Carre& c2) {
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

void initialise_Carre_centre(Carre c)
{
    unsigned int t = (c.x - c.side%2);
    cout << t << endl;
    unsigned int k = (c.y - c.side%2);
    cout << k << endl;
    Carre nc = creeCarre (t, k, c.side);
    initialiseCarre (nc);
}
