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
    public :
}
vector < Fourmis > vectFourmis;
