#include "constantes.h"
using namespace std;

vector<Carre> vnourriture;

class Nourriture{
	private:
	unsigned int x, y;
	
	public:
	Nourriture(unsigned int x_, unsigned int y_)
	: x(x_), y(y_) {}
	
	void launchNourriture();
};
