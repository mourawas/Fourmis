#ifndef FOURMIS_H_INCLUDED
#define FOURMIS_H_INCLUDED

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
protected:
    unsigned int x1;
    unsigned int y1;

public:
    virtual bool big_test(unsigned int countF, Carre& c) = 0;
    Fourmis (unsigned int x1, unsigned int y1) : x1(x1),y1(y1) {}
    virtual void d_ant(double r, double g, double b) = 0;
    virtual ~Fourmis() = default;
    virtual void ecrire_fourmis(std::ofstream& fichier) = 0;
    virtual unsigned int get() = 0;
    virtual unsigned int get_type() = 0;
    unsigned int get_x();
    unsigned int get_y();
};

class Generator : public Fourmis {
private:
    unsigned int side = sizeG;
    unsigned int total_food;
    Carre cg;
public:
    ~Generator() = default;
    Generator(unsigned int x1, unsigned int y1,
              unsigned int total_food, Carre cg);
    bool big_test(unsigned int countF, Carre& c) override;
    bool generator_in_home(unsigned int countF, Carre& c);
    bool g_overlap();
    void d_ant(double r, double g, double b) override;
    void ecrire_fourmis(std::ofstream& fichier) override;
    unsigned int get() override;
    unsigned int get_type() override;
};

class Collector : public Fourmis{
private:
    unsigned int age;
    bool food;
    unsigned int side = sizeC;
    Carre cc;
    std::vector<Nourriture> n_atteignable;
public:
	~Collector() = default;
    Collector(unsigned int x1, unsigned y1, unsigned int age, bool food);
    void setcc(unsigned int& x2,unsigned int& y2);
    bool c_overlap();
    bool big_test(unsigned int countF, Carre& c) override;
    void ini_c(unsigned int& x2, unsigned int& y2, unsigned int& age2, bool& food2);
    void d_ant(double r, double g, double b) override;
    void ecrire_fourmis(std::ofstream& fichier) override;
    unsigned int get() override;
    unsigned int return_the_one(std::vector<Nourriture> n);
    unsigned int get_type() override;
    std::vector<Nourriture> get_n_atteignable();
};

class Defensor : public Fourmis {
private:
    unsigned int age;
    unsigned int side = sizeD;
    Carre cd;
public:
    Defensor(unsigned int x1, unsigned int y1, unsigned int age);
	~Defensor() = default;
    bool d_overlap();
    bool defensor_in_home(unsigned int countF, Carre& c);
    bool big_test(unsigned int countF, Carre& c) override;
    void setcd(unsigned int& x2,unsigned int& y2);
    void ini_d(unsigned int& x2, unsigned int& y2, unsigned int& age2);
    void d_ant(double r, double g, double b) override;
    void ecrire_fourmis(std::ofstream& fichier) override;
    unsigned int get() override;
    unsigned int get_type() override;
};

class Predator : public Fourmis {
private:
    unsigned int age;
    unsigned int side = sizeP;
    Carre cp;
public:
	Predator(unsigned int x1, unsigned y1, unsigned age);
	~Predator() = default;
    bool p_overlap();
    bool big_test(unsigned int countF, Carre& c) override;
    void setcp(unsigned int& x2,unsigned int& y2);
    void ini_p(unsigned int& x2, unsigned int& y2, unsigned int& age2);
    void d_ant(double r, double g, double b) override;
    void ecrire_fourmis(std::ofstream& fichier) override;
    unsigned int get() override;
    unsigned int get_type() override;
};

bool decodage_ligne_fourmis(std::string line, unsigned int etat, Collector& Col,
                            Defensor& Def, Predator& Pre);

#endif
