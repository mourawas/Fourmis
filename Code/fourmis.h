#ifndef HEADERF_H
#define HEADERF_H

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include "squarecell.h"
#include "message.h"
#include "nourriture.h"
#include "constantes.h"

class Fourmis {
protected :
    unsigned int x1;
    unsigned int y1;
public:
    virtual void BigTest(unsigned int countF, Carre& c) = 0;
    Fourmis (unsigned int x1, unsigned int y1)
    : x1(x1),y1(y1)
    {}
    virtual ~Fourmis() {};
    unsigned int getx1(){
        return x1;
    }
    unsigned int gety1(){
        return y1;
    }
};

class Generator : public Fourmis {
    private :
    unsigned int side = sizeG;
    unsigned int total_food;
    Carre cg;
    public :
    ~Generator() {};
    Generator (unsigned int x1, unsigned int y1, unsigned int total_food, Carre cg)
    : Fourmis(x1, y1), total_food(total_food), cg(cg)
    {}
    void BigTest(unsigned int countF, Carre& c) override;
    void GeneratorInHome(unsigned int countF, Carre& c);
    void G_Overlap();
};

class Collector : public Fourmis{
private:
    unsigned int age;
    bool food;
    unsigned int side = sizeC;
    Carre cc;
public:
	~Collector() {};
    Collector(unsigned int x1, unsigned y1, unsigned int age, bool food)
    : Fourmis(x1, y1), age(age), food(food)
    {}
    void setcc(unsigned int& x2,unsigned int& y2);
    void C_overlap();
    void BigTest(unsigned int countF, Carre& c) override;
    void iniC(unsigned int& x2, unsigned int& y2, unsigned int& age2, bool& food2);
};

class Defensor : public Fourmis {
private:
    unsigned int age;
    unsigned int side = sizeD;
    Carre cd;
public:
    Defensor(unsigned int x1, unsigned int y1, unsigned int age)
    :Fourmis(x1, y1), age(age)
    {}
	~Defensor() {};
    void D_overlap();
    void DefensorInHome(unsigned int countF, Carre& c);
    void BigTest(unsigned int countF, Carre& c) override;
    void setcd(unsigned int& x2,unsigned int& y2);
    void iniD(unsigned int& x2, unsigned int& y2, unsigned int& age2);
};

class Predator : public Fourmis {
private:
    unsigned int age;
    unsigned int side = sizeP;
    Carre cp;
public:
	Predator(unsigned int x1, unsigned y1, unsigned age)
    : Fourmis(x1, y1), age(age)
    {}
	~Predator() {};
    void P_overlap();
    void BigTest(unsigned int countF, Carre& c) override;
    void setcp(unsigned int& x2,unsigned int& y2);
    void iniP(unsigned int& x2, unsigned int& y2, unsigned int& age2);
};

void decodage_ligne_fourmis(string line, unsigned int etat, Collector& Col,
                            Defensor& Def, Predator& Pre);

#endif
