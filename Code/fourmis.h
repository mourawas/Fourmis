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
#include <cmath>
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
    unsigned int return_the_one(std::vector<Nourriture>& n);
    virtual void set(int setter) = 0;
    virtual int move(Nourriture& n, unsigned int t1, unsigned int t2) = 0;
    static int compteur1, compteur2, obs1, obs2;
    static bool obstacle, mur1, mur2;
    virtual void detection_f_rival(unsigned int& A, unsigned int& B, unsigned int rog_one,unsigned int rog_two, unsigned int& GROGU, unsigned int h, unsigned int k) = 0;
    virtual int fight(double xb, double yb,double xa, double ya) = 0;
    virtual void operation_milenium(Carre cf) = 0;
    virtual void generator_eat(size_t nbT) = 0 ;
    virtual int contrained_attack(unsigned int t1,unsigned int t2, Carre cf) = 0;
    virtual double get_total_food() =0 ;

};

class Generator : public Fourmis {
private:
    unsigned int side = sizeG;
    double total_food;
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
    int move(Nourriture& n, unsigned int t1, unsigned int t2) override;
    void set(int setter) override;
    void detection_f_rival(unsigned int& A, unsigned int& B, unsigned int rog_one,unsigned int rog_two, unsigned int& GROGU, unsigned int h, unsigned int k) override;
    int fight(double xb, double yb,double xa, double ya) override;
    void operation_milenium(Carre cf)override;
    double get_total_food() override ;
    int contrained_attack(unsigned int t1,unsigned int t2, Carre cf) override;
    void generator_eat(size_t nbT) override;
};

class Collector : public Fourmis{
private:
    unsigned int age;
    bool food, hebs;
    unsigned int side = sizeC;
    Carre cc;
    int xf, yf, cas, longueur1, longueur2, cas_pos;
public:
	~Collector() = default;
    Collector(unsigned int x1, unsigned y1, unsigned int age, bool food);
    void setcc(unsigned int x2, unsigned int y2);
    bool c_overlap();
    bool big_test(unsigned int countF, Carre& c) override;
    void ini_c(unsigned int& x2, unsigned int& y2, unsigned int& age2, bool& food2);
    void d_ant(double r, double g, double b) override;
    void ecrire_fourmis(std::ofstream& fichier) override;
    unsigned int get() override;
    unsigned int get_type() override;
    int move(Nourriture& n, unsigned int t1, unsigned int t2) override;
    void choix_chemin1(Nourriture& n, Carre& bebou);
    void choix_chemin2(Nourriture& n, Carre& bebou);
    void move1(Nourriture& n);
    void move2(Nourriture& n);
    void move_direct(Nourriture& n);
    void move_miroir(Carre& bebou, unsigned int miroir, int& a, bool chemin, Nourriture& n);
    void deplace_miroir(int cas, Nourriture& n);
    int trouver_cas(Nourriture& n);
    void set(int setter) override;
    void generator_eat(size_t nbT) override;
    void detection_f_rival(unsigned int& A, unsigned int& B, unsigned int rog_one,unsigned int rog_two, unsigned int& GROGU, unsigned int h, unsigned int k) override;
    int fight(double xb, double yb,double xa, double ya) override;
    void operation_milenium(Carre cf)override;
    int contrained_attack(unsigned int t1,unsigned int t2, Carre cf) override;
    double get_total_food() override ;
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
    void setcd(unsigned int x2,unsigned int y2);
    void ini_d(unsigned int& x2, unsigned int& y2, unsigned int& age2);
    void d_ant(double r, double g, double b) override;
    void ecrire_fourmis(std::ofstream& fichier) override;
    unsigned int get() override;
    unsigned int get_type() override;
    int move(Nourriture& n, unsigned int t1, unsigned int t2) override;
    void set(int setter) override;
    void detection_f_rival(unsigned int& A, unsigned int& B, unsigned int rog_one,unsigned int rog_two, unsigned int& GROGU, unsigned int h, unsigned int k) override;
    int fight(double xb, double yb,double xa, double ya) override;
    void operation_milenium(Carre cf)override;
    void generator_eat(size_t nbT) override;
    int contrained_attack(unsigned int t1,unsigned int t2, Carre cf) override;
    double get_total_food() override ;
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
    void setcp(unsigned int x2,unsigned int y2);
    void ini_p(unsigned int& x2, unsigned int& y2, unsigned int& age2);
    void d_ant(double r, double g, double b) override;
    void ecrire_fourmis(std::ofstream& fichier) override;
    unsigned int get() override;
    unsigned int get_type() override;
    int move(Nourriture& n, unsigned int t1, unsigned int t2) override;
    void set(int setter) override;
    void detection_f_rival(unsigned int& A, unsigned int& B, unsigned int rog_one,unsigned int rog_two, unsigned int& GROGU, unsigned int h, unsigned int k) override;
    int fight(double xb, double yb,double xa, double ya) override;
    void operation_milenium(Carre cf)override;
    void generator_eat(size_t nbT) override;
    int contrained_attack(unsigned int t1,unsigned int t2,Carre cf) override;
    double get_total_food() override ;
};

bool decodage_ligne_fourmis(std::string line, unsigned int etat, Collector& Col,
                            Defensor& Def, Predator& Pre);

#endif
