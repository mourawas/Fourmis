using namespace std;

class Fourmis {
private :
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
    public :
    Generator (unsigned int x1, unsigned int y1, unsigned int age,)
    : x1(x1),y1(y1),age(age)
    {}
};

class Collector : public Fourmis{
private:
    bool food;
public:
    Collector ( unsigned int x1, unsigned y1, unsigned int age ,bool food)
    : x1(x1),y1(y1),age(age),food(food)
    {}
};

class Defensor : public Fourmis {
private:
public:
    Defensor (unsigned int x1, unsigned int y1, unsigned age)
    :x1(x1),y1(y1),age(age)
    {}
};

class Predator : public Fourmis {
private:
public:
    Predator ( unsigned int x1,unsigned y1, unsigned age)
    :x1(x1),y1(y1),age(age)
    {}
};

vector < Fourmis > vectFourmis;
