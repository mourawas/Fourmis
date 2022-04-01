using namespace std;
#include <iostream>
#include <vector>
#include "squarecell.h"
#include "message.h"
#include "fourmis.h"
#include "nourriture.h"

void pushbackfourmis ( Fourmis* fourmis, vector<unique_ptr<Fourmis> >& V);
void decodage_ligne_fourmis(string line, vector<unique_ptr<Fourmis> >& V);
class Fourmis {
protected :
    unsigned int x1;
    unsigned int y1;
    unsigned int age;
public:
    
    Fourmis (unsigned int x1, unsigned int y1, unsigned int age)
    : x1(x1),y1(y1),age(age)
    {}
    unsigned int getx1 (){
        return x1;
    }
    unsigned int gety1(){
        return y1;
    }
    unsigned int getage(){
        return age;
    }
};

class Generator : public Fourmis {
    private :
    unsigned int side = sizeG;
    Carre cg = {{x1,y1},sideG};
    public :
    Generator (unsigned int xg, unsigned int yg, unsigned int total_food)
    : xg(xg), yg(yg), total_food(total_food)
    {}
    void Big_Test_G(grille& grille, Carre& c, unsigned int countF,g_max);
    void
    void Generator_In_Homme(unsigned int count F, Carre& c);
    void G_Overlap(Carre& c,grille& grille);
};

class Collector : public Fourmis{
private:
    bool food;
    unsigned int side = sizeC
    Carre cc = {{x1,y1},side};
public:
    Collector ( unsigned int x1, unsigned y1, unsigned int age, bool food)
    : x1(x1),y1(y1),age(age),food(food)
    {}
};

class Defensor : public Fourmis {
private:
    unsigned int side = sizeD;
    Carre cd = {{x1,y1},side};
public:
    Defensor (unsigned int x1, unsigned int y1, unsigned age)
    :x1(x1),y1(y1),age(age)
    {}
};

class Predator : public Fourmis {
private:
    unsigned int side = sizeP;
    Carre cp = {{x1,y1},side}
public:
    Predator ( unsigned int x1,unsigned y1, unsigned age)
    :x1(x1),y1(y1),age(age)
    {}
};

vector < Fourmis > vectFourmis;
decodage_ligne_fourmis(string l,  );

