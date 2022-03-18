#include <string>
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

int main()
{
    const unsigned int g_max = 100;
    vector<vector<bool> > grille;
    
    Point p1 = { 5, 5 };
    Point p2 = { 10, 10 };

    unsigned int dim1 = 6, dim2 = 5;

    initialiseGrille(grille, g_max);
    testCarre(grille, p1, dim1, g_max);
    testCarre(grille, p2, dim2, g_max);
    initialiseCarre(grille, p1, dim1);
    initialiseCarre(grille, p2, dim2);
    bool sup = superposition(grille, p1, p2, dim1, dim2, g_max);

    cout << sup << endl;

    if (sup) {
        supprimerCarre(grille, p2, dim2);
        initialiseCarre(grille, p1, dim1);
    }

    cout << grille[11][11] << endl;
    cout << grille[12][12] << endl;
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
    bool erreur = false;
    if (p.x > (g_max - 1)) {
        erreur = true;
    }
    else if (p.y > (g_max - 1)) {
        erreur = true;
    }
    else if ((p.x + dim) > (g_max - 1)) {
        erreur = true;
    }
    else if ((p.y + dim) > (g_max - 1)) {
        erreur = true;
    }
    if (erreur) {
        cout << "ERREUR" << endl;
        exit(0);
    }
}

void initialiseCarre(vector<vector<bool> > & grille, Point& p, unsigned int& dim) {
    for (size_t i = p.x; i <= p.x + dim; i++) {
        for (size_t j = p.y; j <= p.y + dim; j++) {
            grille[i][j] = true;
        }
    }
}

bool superposition(vector<vector<bool> > & grille, Point& p1, Point& p2, unsigned int& dim1, unsigned int& dim2, const unsigned int& g_max) {
    unsigned int compteur = 0;
    for (size_t i = 0; i < (g_max - 1); ++i) {
        for (size_t j = 0; j < (g_max - 1); ++j) {
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

void supprimerCarre(vector<vector<bool> > & grille, Point& p, unsigned int& dim) {
    for (size_t i = p.x; i <= p.x + dim; i++) {
        for (size_t j = p.y; j <= p.y + dim; j++) {
            grille[i][j] = false;
        }
    }
}
