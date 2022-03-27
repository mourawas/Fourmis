#include "constantes.h"
using namespace std;

vector<Carre> temp;				//en 1er vérification
vector<Carre> vnourriture;		//en 2e

class Nourriture{
	private:
	unsigned int x, y;
	
	public:
	Nourriture(unsigned int x_, unsigned int y_)
	: x(x_), y(y_) {}
	
	void launchNourriture();
};
