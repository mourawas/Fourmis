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
    void Big_Test_G( unsigned int countF, Carre& c, unsigned int g_max);
    void Generator_In_Home(unsigned int countF, Carre& c);
    void G_Overlap(Carre& c);
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
    void C_overlap(Carre& c);
    void Big_Test_C(Carre& c, unsigned int g_max)
};

class Defensor : public Fourmis {
private:
    unsigned int side = sizeD;
    Carre cd = {{x1,y1},side};
public:
    void D_overlap(carre& c);
    void Defensor_In_Home(unsigned int countF,Carre& c,unsigned int g_max);
    void Big_Test_D(unsigned int countF,carre& c,unsigned int g_max);
    Defensor (unsigned int x1, unsigned int y1, unsigned age)
    :x1(x1),y1(y1),age(age)
    {}
};

class Predator : public Fourmis {
private:
    unsigned int side = sizeP;
    Carre cp = {{x1,y1},side}
public:
    void P_overlap();
    void Big_Test_P(Carre& c,unsigned int g_max);
    Predator ( unsigned int x1,unsigned y1, unsigned age)
    :x1(x1),y1(y1),age(age)
    {}
};

vector < Fourmis > vectFourmis;
decodage_ligne_fourmis(string l,  );

