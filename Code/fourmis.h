#ifndef FOURMIS_H
#define FOURMIS_H

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include "squarecell.h"
#include "message.h"
#include "fourmis.h"
#include "nourriture.h"

class Fourmis {
protected :
    unsigned int x1;
    unsigned int y1;
public:
    virtual void BigTest(unsigned int countF, Carre& c);
    Fourmis (unsigned int x1, unsigned int y1)
    : x1(x1),y1(y1)
    {}
    unsigned int getx1(){
        return x1;
    }
    unsigned int gety1(){
        return y1;
    }
};

void pushbackFourmis(Fourmis* fourmis, vector<unique_ptr<Fourmis> >& V);

class Generator : public Fourmis {
    private :
    unsigned int side = sizeG;
    unsigned int total_food;
    Carre cg = {x1, y1, side};
    public :
    Generator (unsigned int x1, unsigned int y1, unsigned int total_food)
    : x1(x1), y1(y1), total_food(total_food)
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
    Carre cc = {x1, y1, side};
public:
    Collector(unsigned int x1, unsigned y1, unsigned int age, bool food)
    : x1(x1), y1(y1), age(age), food(food)
    {}
    void C_overlap();
    void BigTest(unsigned int countF, Carre& c) override;
    void iniC(unsigned int& x2, unsigned int& y2, unsigned int& age2, bool& food2);
};

class Defensor : public Fourmis {
private:
    unsigned int age;
    unsigned int side = sizeD;
    Carre cd = {x1, y1, side};
public:
    void D_overlap();
    void DefensorInHome(unsigned int countF, Carre& c);
    void BigTest(unsigned int countF, Carre& c) override;
    Defensor(unsigned int x1, unsigned int y1, unsigned int age)
    :x1(x1), y1(y1), age(age)
    {}
    void iniD(unsigned int& x2, unsigned int& y2, unsigned int& age2);
};

class Predator : public Fourmis {
private:
    unsigned int age;
    unsigned int side = sizeP;
    Carre cp = {x1, y1, side}
public:
    void P_overlap();
    void BigTest(unsigned int countF, Carre& c) override;
    Predator(unsigned int x1, unsigned y1, unsigned age)
    :x1(x1),y1(y1),age(age)
    {}
    void iniP(unsigned int& x2, unsigned int& y2, unsigned int& age2);
};

vector < Fourmis > vectFourmis;
decodage_ligne_fourmis(string line, unsigned int etat,
                       Collector& Col, Defensor& Def,
                       Predator& Pre);

#endif