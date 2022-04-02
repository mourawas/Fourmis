
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

void supCoord(Carre c, unsigned int& x, unsigned int& y) {
    for (size_t i = (g_max - 1 - (c.y-c.side/2)); i > (g_max - 1 - (c.y - c.side / 2)-c.side); --i) {
        for (size_t j(c.x-c.side/2); j <= c.x+c.side/2; ++j) {
            if (grid[i][j] == true) {
                x = j;
                y = i;	//on veut les coordonnées ou les index ??
            }			//si coord alors y = g_max-i
        }
    }
}

Carre creeCarre(unsigned int& x,unsigned int& y, unsigned int& side)
{
	Carre c = {x, y, side};
    return c;
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
    unsigned int compteur = nbTrue();
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
    if (c2.side > c1.side){
        return true;
    }
    if((c2.x > c1.x + c1.side) or (c2.y > c1.y + c1.side)){
		return true;
	}
	if((c2.x + side/2 > c1.x + side) or (c2.y + side/2 > c1.y + side) ){
		return true;
	}
	
    return false;	//carre pas dans carre
}

void initialise_Carre_Centre(Carre& c)
{
    unsigned int t = (c.x - c.side/2);
    cout << t << endl;
    unsigned int k = (c.y - c.side/2);
    cout << k << endl;
    Carre nc = creeCarre (t, k, c.side);
    initialiseCarre (nc);
}
