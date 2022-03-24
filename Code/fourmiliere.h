using namespace std;
#include <vector>

vector <Fourmiliere> vectF ;

class Fourmiliere {
private:
    Carre f;
    Carre g;
    unsigned nbC;
    unsigned nbD;
    unsigned nbP;
    unsigned total_food;
public:
    Fourmiliere (Carre f, Carre g, unsigned nbC, unsigned nbD, unsigned nbP,unsigned total_food)
    : f(f), g(g), nbD(nbD),nbP(nbP), total_food (total_food),nbC (nbC)
    {}
    Carre setcarref () const
    {
        return f;
    }
};

void pushbackF (unsigned x, unsigned y, unsigned side , unsigned x1, unsigned y1, unsigned total_food, unsigned nbC, unsigned nbD, unsigned nbP);

void multisuperposition ( vector <Fourmiliere> v);

