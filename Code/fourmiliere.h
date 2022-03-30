using namespace std;
#include <vector>

//vector <Fourmiliere> vectF ;
vector< Carre > extraction_vector ( vector <Fourmiliere> vectF);

class Fourmiliere {
private:
    Carre f;
    Carre g;
    unsigned int nbC;
    unsigned int nbD;
    unsigned int nbP;
    unsigned int total_food;
public:
    Fourmiliere (Carre f, Carre g, unsigned int nbC, unsigned int nbD, unsigned int nbP, unsigned int total_food)
    : f(f), g(g), nbD(nbD),nbP(nbP), total_food (total_food),nbC (nbC)
    {}
    Carre getcarref () const
    {
        return f;
    }
    bool verification (vector<vector<bool> >& grille, Fourmiliere& f, vector < Fourmiliere >& vectF ){
        for (size_t i(0); i< vectF.size();++i)
        {
            if (superposition(grille,vectF[i].getcarref,f.getcarref)){
                return false
            }
        }else return true;
    }
};

//vector < Fourmiliaire > pushbackF (unsigned int& x, unsigned int& y, unsigned int& side , unsigned int& x1, unsigned int& y1, unsigned int& total_food, unsigned int& nbC, unsigned int& nbD, unsigned int& nbP);



