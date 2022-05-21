//squarecell.cc
//Mouhamad: 50%
//Louis: 50%
#include "squarecell.h"
using namespace std;

static grille grid;

void initialise_grille() {
    for (size_t i = 0; i < g_max; ++i) {
        grid.push_back(vector<bool>());
        for (size_t j = 0; j < g_max; ++j) {
            grid[i].push_back(false);
        }
    }
}

void vide_grille(){
    grid.clear();
}

bool sup_carre(Carre& c1, Carre& c2){
	unsigned int coin1x = c1.x + c1.side; //en bas à droite
	unsigned int coin1y = c1.y + c1.side; //en haut a gauche
	
	unsigned int coin2x = c2.x + c2.side; //en bas à droite
	unsigned int coin2y = c2.y + c2.side; //en haut à gauche
	
	if((c1.x >= coin2x) or (c2.x >= coin1x)){
		return false;
	}
	if((c1.y >= coin2y) or (c2.y >= coin1y)){
		return false;
	}
	return true;
}

bool test_carre(Carre& c) {
	    
    if (c.x > (g_max)) {
        cout << error_squarecell::print_index(c.x, g_max-1);
        return true;
    }
    else if (c.y > (g_max)) {
        cout << error_squarecell::print_index(c.x, g_max-1);
        return true;
    }
    else if ((c.x + c.side) > (g_max)) {
        cout << error_squarecell::print_outside(c.x, c.side, g_max-1);
        return true;
    }
    else if ((c.y + c.side) > (g_max)) {
        cout << error_squarecell::print_outside(c.y, c.side, g_max-1);
        return true;
    }
    return false;
}

bool test_carre_centre(Carre& c){
		    
    if (c.x > (g_max)) {
        cout << error_squarecell::print_index(c.x, g_max-1);
        return true;
    }
    else if (c.y > (g_max)) {
        cout << error_squarecell::print_index(c.x, g_max-1);
        return true;
    }
    else if ((c.x + c.side/2) > (g_max)) {
        cout << error_squarecell::print_outside(c.x, c.side, g_max-1);
        return true;
    }
    else if ((c.y + c.side/2) > (g_max)) {
        cout << error_squarecell::print_outside(c.y, c.side, g_max-1);
        return true;
    }
    return false;
}

void initialise_carre(Carre& c) {
    for (size_t i = c.y; i < c.y + c.side; ++i) {
        for (size_t j = c.x; j < c.x + c.side; ++j) {
            grid[g_max-1-i][j] = true;
        }
    }
}

bool sup_coord(Carre c, unsigned int& x, unsigned int& y) {
    for (size_t i = c.y - c.side/2; i <= c.y + c.side/2; ++i) {
        for (size_t j = c.x - c.side/2; j <= c.x + c.side/2; ++j) {
            if (grid[g_max-i-1][j]) {
                x = j;
                y = i;
                return true;
            }
        }
    }
    return false;
}

bool sup(unsigned int& x, unsigned int& y){
    if(grid[g_max-y-1][x]){
        return true;
    }
    return false;
}

void supprimer_carre(Carre& c) {
    for (size_t i = c.y - c.side/2; i < c.y + c.side/2; ++i) {
        for (size_t j = c.x - c.side/2; j < c.x + c.side/2; ++j) {
            grid[g_max-1-i][j] = false;
        }
    }
}

bool carre_dans_carre(Carre& c1, Carre& c2) {
    if (c2.side > c1.side){
        return true;
    }else if(c2.x + c2.side/2 >= c1.x + c1.side-1){
		return true;
	}else if(c2.y + c2.side/2 >= c1.y + c1.side-1){
		return true;
	}else if(c2.x - c2.side/2 <= c1.x){
		return true;
	}else if(c2.y - c2.side/2 <= c1.y){
		return true;
	}
	
    return false;	//carre pas dans carre
}

void initialise_carre_centre(Carre& c)
{
    unsigned int t = (c.x - c.side/2);
    unsigned int k = (c.y - c.side/2);
    Carre nc = {t, k, c.side};
    initialise_carre (nc);
}

bool point_dans_carre(unsigned int& x, unsigned int& y, Carre& c){
    if(x < c.x){
        return false;
    }
    if(y < c.y){
        return false;
    }
    if(x > (c.x + c.side)){
        return false;
    }
    if(y > (c.y + c.side)){
        return false;
    }
    return true;
}

bool carre_libre_dans_carre(Carre& c){
    for (size_t i = c.y - c.side/2; i <= c.y + c.side/2; ++i) {
        for (size_t j = c.x - c.side/2; j <= c.x + c.side/2; ++j) {
            if (grid[g_max-i-1][j]) {
                return true;        //pas bien
            }
        }
    }
    return false;       //bien
}

void deplace_carre_digaonale(Carre& c, unsigned int dir){
    switch(dir){
        case 0: {        //en haut a droite
        Carre t = {c.x + 1, c.y + 1, 3};
        c = t;
        break; }
        case 1: {         //en bas a droite
        Carre t = {c.x + 1, c.y - 1, 3};
        c = t;
        break; }
        case 2: {        //en bas a gauche
        Carre t = {c.x - 1, c.y - 1, 3};
        c = t;
        break; }
        case 3: {        //en haut a gauche
        Carre t = {c.x - 1, c.y + 1, 3};
        c = t;
        break; }
    }
}

void dessin_carre_croix(unsigned int x, unsigned int y, double size, double r,
                        double g, double b)
{
    graphic_draw_carre_plein(x,y,size,r*0.6,g*0.6,b*0.6);
    graphic_draw_croix(x,y,r,g,b);
}

void dessin_carre_plus(unsigned int x, unsigned int y, double size, double r, double g,
                       double b)
{
    graphic_draw_carre_plein(x,y,size,r*0.6,g*0.6,b*0.6);
    graphic_draw_plus(x,y,size,r,g,b);
}

void dessin_carre_plein(unsigned int x, unsigned int y, double size, double r,
                        double g, double b)
{
    graphic_draw_carre_plein(x,y,size,r,g,b);
}
void dessin_losange(unsigned int x, unsigned int y, double r, double b, double g)
{
    graphic_draw_losange(x,y,r,g,b);
}

void dessin_carre_vide(unsigned int x, unsigned int y, double size, double r, double g,
                       double b)
{
    graphic_draw_carre_vide(x,y,size,r,g,b);
}
