#include <vector>
#include <string>
#include "constantes.h"
#include "message.h"
#include "squarecell.h"
#include "constantes.h"
using namespace std;

class Nourriture{
	private:
	unsigned int x, y;

	public:
	Nourriture(unsigned int x_, unsigned int y_)
	: x(x_), y(y_) {}
	
};

void decodage_ligne_nourriture(string line, vector<Nourriture>& vnourriture); //peut etre lui donner la grille