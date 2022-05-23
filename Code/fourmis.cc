//fourmis.cc
//Mouhamad: 50%
//Louis: 50%
#include "fourmis.h"
using namespace std;

int Fourmis::compteur1 = 0;
int Fourmis::compteur2 = 0;
int Fourmis::obs1 = 0;
int Fourmis::obs2 = 0;
bool Fourmis::obstacle = 0;
bool Fourmis::mur1 = 0;
bool Fourmis::mur2 = 0;

Generator::Generator(unsigned int x1, unsigned int y1,
                     unsigned int total_food, Carre cg)
    : Fourmis(x1, y1), total_food(total_food), cg(cg) {}

Collector::Collector(unsigned int x1, unsigned y1, unsigned int age, bool food)
: Fourmis(x1, y1), age(age), food(food) {cc.x = x1; cc.y = y1; cc.side = sizeC;}

Defensor::Defensor(unsigned int x1, unsigned int y1, unsigned int age)
    : Fourmis(x1, y1), age(age) {}

Predator::Predator(unsigned int x1, unsigned y1, unsigned age)
    : Fourmis(x1, y1), age(age) {}

void Collector::ini_c(unsigned int& x2, unsigned int& y2, unsigned int& age2,
                     bool& food2) {
    x1 = x2;
    y1 = y2;
    age = age2;
    food = food2;
    setcc(x2, y2);
}

void Collector::setcc(unsigned int x2, unsigned int y2){
	cc = {x2, y2, sizeC};
}

void Collector::d_ant(double r, double g, double b){
    double s = sizeC;
    if(!food){
        dessin_carre_croix(x1, y1, s, r, g, b);
    }else{
        dessin_losange_carre_croix(x1, y1, s, r, g, b);
    }
}

void Generator::set(int setter){
    cout << "oups";
}

void Collector::set(int setter){
    food = setter;

}

void Defensor::set(int setter){
    cout << "oups";
}

void Predator::set(int setter){
    cout << "oups";
}

void Defensor::ini_d(unsigned int& x2, unsigned int& y2, unsigned int& age2)
{
    x1 = x2;
    y1 = y2;
    age = age2;
    setcd(x2, y2);
}

void Defensor::setcd(unsigned int x2, unsigned int y2){
	cd = {x2, y2, sizeD};
}
void Defensor::d_ant(double r, double g, double b){
    double s = sizeD;
    dessin_carre_plus(x1, y1, s, r, g, b);
}

void Predator::ini_p(unsigned int& x2, unsigned int& y2, unsigned int& age2)
{
    x1 = x2;
    y1 = y2;
    age = age2;
    setcp(x2, y2);
}

void Predator::setcp(unsigned int x2, unsigned int y2){
	cp = {x2, y2, sizeP};
}

void Predator::d_ant(double r, double g, double b){
    double s = sizeP;
    dessin_carre_plein(x1, y1, s, r, g, b);
}

bool decodage_ligne_fourmis(string line, unsigned int etat, Collector& Col,
                            Defensor& Def, Predator& Pre)
{
    istringstream data(line);
    unsigned int x, y, age;
    string foods;
    bool food;

    if (etat == 1) {
        data >> x >> y >> age >> foods;
        if (foods == "true") {
            food = 1;
        }else food = 0;
        
        Carre c = { x, y, sizeC };
        if(test_carre_centre(c)) return true;
        Col.ini_c(x, y, age, food);
        return false;
    }
    if (etat == 2) {
        data >> x >> y >> age;
        
        Carre c = { x, y, sizeD };
        if(test_carre_centre(c)) return true;
        Def.ini_d(x, y, age);
        return false;
    }
    if (etat == 3) {
        data >> x >> y >> age;
        
        Carre c = { x, y, sizeP };
        if(test_carre_centre(c)) return true;
        Pre.ini_p(x, y, age);
        return false;
    }
    return false;
}

bool Generator::generator_in_home(unsigned int countF, Carre& c){
    if (carre_dans_carre(c, cg)) {
        cout << message::generator_not_within_home(x1,y1,countF);
        return true;
    }
    return false;
}

bool Generator::g_overlap(){
		unsigned int x, y;
		if(sup_coord(cg, x, y)) {
			cout << message::generator_overlap(x1, y1, x, y);
			return true;
    }
    return false;
}

void Generator::d_ant(double r, double g, double b){
    double s = sizeG;
    dessin_carre_plein(x1, y1, s, r, g, b);
}

bool Generator::big_test(unsigned int countF, Carre& c){
	if(test_carre_centre(cg)) return true;
    if(generator_in_home(countF, c)) return true;
    if(g_overlap()) return true;
    initialise_carre_centre(cg);
    return false;
}

void Generator::ecrire_fourmis(ofstream& fichier){
    fichier << " " << to_string(cg.x) << " " << to_string(cg.y) << " "
            << to_string(total_food) << " ";
}

unsigned int Generator::get(){
    return total_food;
}

unsigned int Generator::get_type(){
    return 0;
}

bool Collector::c_overlap(){
	unsigned int x, y;
	if(sup_coord(cc, x, y)){
		cout << message::collector_overlap(x1, y1, x, y);
		return true;
	}
	return false;
}

bool Collector::big_test(unsigned int countF, Carre& c){
	if(test_carre_centre(cc)) return true;
    if(c_overlap()) return true;
    initialise_carre_centre (cc);
    return false;
}

void Collector::ecrire_fourmis(ofstream& fichier){
    string a;
    if(food){
        a = "true";
    }else{
        a = "false";
    }
    fichier << "\t" << to_string(cc.x) << " " << to_string(cc.y)
            << " " << to_string(age) << " " << a << "\n";
}

unsigned int Collector::get(){
    return food;
}

unsigned int Collector::get_type(){
    return 1;
}

bool Defensor::d_overlap(){
		unsigned int x, y;
		if(sup_coord(cd, x, y)){
			cout << message::defensor_overlap(x1,y1,x,y);
			return true;
    }
    return false;
}

bool Defensor::defensor_in_home(unsigned int countF, Carre& c){
    if (carre_dans_carre(c,cd)){
        cout << message::defensor_not_within_home(x1,y1,countF);
        return true;
    }
    return false;
}

bool Defensor::big_test(unsigned int countF, Carre& c){
	if(test_carre_centre(cd)) return true;
    if(defensor_in_home(countF, c)) return true;
    if(d_overlap()) return true;
    initialise_carre_centre(cd);
    return false;
}

void Defensor::ecrire_fourmis(ofstream& fichier){
    fichier << "\t" << to_string(cd.x) << " " << to_string(cd.y)
            << " " << to_string(age) << "\n";
}

unsigned int Defensor::get(){
    return age;
}

unsigned int Defensor::get_type(){
    return 2;
}

bool Predator::p_overlap(){
	unsigned int x, y;
	if(sup_coord(cp, x, y)){
		cout << message::predator_overlap(x1,y1);
		return true;
    }
    return false;
}

bool Predator::big_test(unsigned int countF, Carre& c){
	if(test_carre(cp)) return true;
    if(p_overlap()) return true;
    initialise_carre_centre(cp);
    return false;
}

void Predator::ecrire_fourmis(ofstream& fichier){
    fichier << "\t" << to_string(cp.x) << " " << to_string(cp.y)
            << " " << to_string(age) << "\n";
}

unsigned int Predator::get(){
    return age;
}

unsigned int Predator::get_type(){
    return 3;
}

unsigned int Fourmis::get_x(){
    return x1;
}

unsigned int Fourmis::get_y(){
    return y1;
}

unsigned int Fourmis::return_the_one(vector<Nourriture>& n){
    int T = 0;
    int K = 127;
    unsigned int A = 0;
    for(size_t i = 0; i < n.size(); ++i){
        if (abso(n[i].get_x()-x1) >= abso(n[i].get_y()-y1)){
            T = abso(n[i].get_x()-x1);
            if (T < K){
                K=T;
                A=i;
                //cout << " K = "<< K << endl;
            }
        }else{
            T = abso(n[i].get_y()-y1);
            if (T < K){
                K=T;
                A=i;
                //cout << " K = "<< K << endl;
            }
        }
    }
    return A;
}

int Collector::move(Nourriture& n, unsigned int t1, unsigned int t2){
    //cout << "HEBS : " << hebs << "  CAS : " << cas << endl;
    int nx = n.get_x(), ny = n.get_y();
    if(hebs){
        cout << "dans if hebs "<<endl;
        if((x1 == 1) or (x1 == g_max-2) or (y1 == 1) or (y1 == g_max-2)
            or (xf != nx) or (yf != ny)){
            hebs = 0;
        }else{
            deplace_miroir(cas, n);
            return 0;
        }
    }
    supprimer_carre(cc);
    Carre bebou = cc;
    double xn = n.get_x(), yn = n.get_y();
    double xc = bebou.x, yc = bebou.y;
    double k;
    if(xn == xc){
        k = 200;
        cout << "dans l 333"<< endl;
    }else{
    k = (yn - yc)/(xn - xc);
    cout << "dans l 337"<< endl;
    }
    cout << k << endl;
    cout << "avant chemin 1" << endl;
    choix_chemin1(n, bebou);
    cout << "chemin 1 ok" << endl;
    obstacle = 0;
    bebou = cc;
    choix_chemin2(n, bebou);
    cout << "chemin 2 ok" << endl;
    //initialise_carre_centre(cc);
    cout << "compteur1 : " << compteur1 << " compteur2 : " << compteur2 << endl;
    //cout << "obs1 : " << obs1 << " obs2 : " << obs2 << endl;
    if(compteur1 > compteur2){
        cout << " entrez dans l 351"<<endl;
        cout << "mur2: "<<mur2<<" cas_pos: "<< cas_pos<<" y1: "<<y1<<endl;
        if(mur2 and (((cas_pos == 0) and (x1 == 1)) or ((cas_pos == 1) and (y1 == 1)) or
           ((cas_pos == 2) and (x1 == g_max-2)) or ((cas_pos == 3) and (y1 == g_max-2)))){
            hebs = 1;
            cout <<"hebs"<<endl;
            xf = xn, yf = yn;
            longueur1 = ((xf -x1)+(yf-y1))/2;
            longueur2 = ((xf -x1)-(yf-y1))/2;
            cas = trouver_cas(n);
            cout << "avant deplace miroir"<< endl;
            deplace_miroir(cas, n);
            return 0;
        }
        cout << "A prend chemin 2" << endl;
        move2(n);
        cout << "A a pris chemin 2" << endl;
    }
    if(compteur1 < compteur2){
        cout << "mur2: "<<mur2<<" cas_pos: "<< cas_pos<<" y1: "<<y1<<endl;
        if(mur1 and (((cas_pos == 0) and (x1 == 1)) or ((cas_pos == 1) and (y1 == 1)) or
           ((cas_pos == 2) and (x1 == g_max-2)) or ((cas_pos == 3) and (y1 == g_max-2)))){
            hebs = 1;
            cout <<"hebs"<<endl;
            xf = xn, yf = yn;
            longueur1 = ((xf -x1)+(yf-y1))/2;
            longueur2 = ((xf -x1)-(yf-y1))/2;
            cas = trouver_cas(n);
            cout << "avant deplace miroir"<< endl;
            deplace_miroir(cas, n);
            return 0;
        }
        cout << "B prend chemin 1" << endl;
        move1(n);
        cout << "B a pris chemin 1" << endl;
    }
    if((k==1) or (k== -1)){
        cout << "chemin diagonal" << endl;
        move_direct(n);
        cout << "a pris chemin diagonal" << endl;
    }
    if((compteur1 == compteur2) and (k !=1) and (k!=-1)){
        if(obs1 > obs2){
            cout<<"hebs l 393"<<endl;
            if(mur1 and (((cas_pos == 0) and (x1 == 1)) or ((cas_pos == 1) and (y1 == 1)) or
               ((cas_pos == 2) and (x1 == g_max-2)) or ((cas_pos == 3) and (y1 == g_max-2)))){
                hebs = 1;
                xf = xn, yf = yn;
                longueur1 = ((xf -x1)+(yf-y1))/2;
                longueur2 = ((xf -x1)-(yf-y1))/2;
                cas = trouver_cas(n);
                deplace_miroir(cas, n);
                return 0;
            }
            cout << "C prend chemin 1" << endl;
            move1(n);
            cout << "C a pris chemin 1" << endl;
        }else if(obs1 < obs2){

            if(mur2 and (((cas_pos == 0) and (x1 == 1)) or ((cas_pos == 1) and (y1 == 1)) or
               ((cas_pos == 2) and (x1 == g_max-2)) or ((cas_pos == 3) and (y1 == g_max-2)))){
                hebs = 1;
                cout<<"hebs l 393"<<endl;
                xf = xn, yf = yn;
                longueur1 = ((xf -x1)+(yf-y1))/2;
                longueur2 = ((xf -x1)-(yf-y1))/2;
                cas = trouver_cas(n);
                deplace_miroir(cas, n);
                return 0;
            }
            cout << "D prends chemin 2" << endl;
            move2(n);
            cout << "D a pris chemin 2" << endl;
        }
        else{
            cout << "mur2: "<<mur2<<" cas_pos: "<< cas_pos<<" y1: "<<y1<<endl;
            if(mur2 and (((cas_pos == 0) and (x1 == 1)) or ((cas_pos == 1) and (y1 == 1)) or
               ((cas_pos == 2) and (x1 == g_max-2)) or ((cas_pos == 3) and (y1 == g_max-2)))){
                hebs = 1;
                cout<<"hebs l 393"<<endl;
                xf = xn, yf = yn;
                longueur1 = ((xf -x1)+(yf-y1))/2;
                longueur2 = ((xf -x1)-(yf-y1))/2;
                cas = trouver_cas(n);
                deplace_miroir(cas, n);
                return 0;
            }
            else {
                cout << "E prends chemin 2" << endl;
                move1(n);
                cout << "E a pris chemin 2" << endl;
            }
        }
    }
    compteur1 = 0, compteur2 = 0, obs1 = 0, obs2 = 0, obstacle = 0;
    return 0;
}

int Collector::trouver_cas(Nourriture& n){
    int xn = n.get_x();
    int yn = n.get_y();
    int x2 = x1;
    int y2 = y1;

    if((x2 == g_max-2) and (yn > y2)){
        return 0;
    }else if((x2 == g_max-2) and (yn < y2)){
        return 4;
    }else if((y2 == g_max-2) and (xn > x2)){
        return 5;
    }else if((y2 == g_max-2) and (xn < x2)){
        return 3;
    }else if((x2 == 1) and (xn > x2)){
        return 1;
    }else if((x2 == 1) and (xn < x2)){
        return 7;
    }else if((y2 == 1) and (yn > y2)){
        return 2;
    }else if((y2 == 1) and (yn < y2)){
        return 6;
    }
    return 10;
}

void Collector::choix_chemin1(Nourriture& n, Carre& bebou){
    if((bebou.x == n.get_x()) and (bebou.y == n.get_y())){
        return;
    }
    double k;
    //cout << "OBSTACLE 1 : " << acle << endl;
    if(!obstacle) ++obs1;
    double xn = n.get_x(), yn = n.get_y();
    double xc = bebou.x, yc = bebou.y;
    if(xn == xc){
        k = 200;
    }else{
    k = (yn - yc)/(xn - xc);
    }
    cout << "k : " << k << endl;
    if((xn - xc) != 0){
        cout<<" xn-xc != 0"<< endl;
        if((xn > xc) and (k > -1) and (k < 1)){
            cout << " entre dans xn > xc , k>-1,k<1"<< endl;
            if((k != 1) and (k != -1) and (xc = 1)){
                cout << " faut pas rentrez la "<<endl;
                if(xc == g_max-2){
                    int a = 0;
                    if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
                    move_miroir(bebou, 0, a, 0, n);
                    mur1 = true;
                    compteur1 += a;
                    cas_pos = 2;
                    return choix_chemin1(n, bebou);
                }else if(yc == 1){//yc == 2
                    cout << " faut rentrez la "<<endl;
                    int a = 0;
                    if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
                    cout <<"entre dans moove miroir"<< endl;
                    move_miroir(bebou, 1, a, 0, n);
                    cout << "chemin1: "<<bebou.x<<" "<<bebou.y<<endl;
                    cout<<"sors de moove miroir"<<endl;
                    mur1 = true;
                    compteur1 += a;
                    cas_pos = 1;
                    return choix_chemin1(n, bebou);
                }
            }
            //cout << "k1"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            //cout << "k2"<< endl;
            deplace_carre_digaonale(bebou, 1);
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            return choix_chemin1(n, bebou);
        }
        if((xn < xc) and (k > -1) and (k < 1)){
            if(xc == 1){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
                move_miroir(bebou, 2, a, 0, n);
                mur1 = true;
                compteur1 += a;
                cas_pos = 0;
                return choix_chemin1(n, bebou);
            }else if(yc == g_max - 2){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
                move_miroir(bebou, 3, a, 0, n);
                mur1 = true;
                compteur1 += a;
                cas_pos = 3;
                return choix_chemin1(n, bebou);
            }
            //cout << "k3"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            //cout << "k4"<< endl;
            deplace_carre_digaonale(bebou, 3);
            return choix_chemin1(n, bebou);
        }
    }
    if((yn - y1) != 0){
        if((yn > yc) and ((k > 1) or (k < -1))){
            if(x1 == g_max-2){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
                move_miroir(bebou, 4, a, 0, n);
                mur1 = true;
                compteur1 += a;
                cas_pos = 2;
                return choix_chemin1(n, bebou);
            }else if(y1 == g_max-2){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
                move_miroir(bebou, 5, a, 0, n);
                mur1 = true;
                compteur1 += a;
                cas_pos = 3;
                return choix_chemin1(n, bebou);
            }
            //cout << "k5"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            //cout << "k6"<< endl;
            deplace_carre_digaonale(bebou, 0);
            return choix_chemin1(n, bebou);
        }
        if((yn < yc) and ((k > 1) or (k < -1))){
            if(xc == 1){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
                move_miroir(bebou, 6, a, 0, n);
                mur1 = true;
                compteur1 += a;
                cas_pos = 0;
                return choix_chemin1(n, bebou);
            }else if(yc == 1){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
                move_miroir(bebou, 7, a, 0, n);
                mur1 = true;
                compteur1 += a;
                cas_pos = 1;
                return choix_chemin1(n, bebou);
            }
            //cout << "k7"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            //cout << "k8"<< endl;
            deplace_carre_digaonale(bebou, 2);
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            return choix_chemin1(n, bebou);
        }
    }
    if((xn == xc) and (yn > yc)){
        if(xc == g_max-2){
            int a = 0;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            move_miroir(bebou, 4, a, 0, n);
            mur1 = true;
            compteur1 += a;
            cas_pos = 2;
            return choix_chemin1(n, bebou);
        }else if(yc == g_max-2){
            int a = 0;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            move_miroir(bebou, 5, a, 0, n);
            mur1 = true;
            compteur1 += a;
            cas_pos = 3;
            return choix_chemin1(n, bebou);
        }
        //cout << "k9"<< endl;
        //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
        if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
        //cout << "k10"<< endl;
        //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
        deplace_carre_digaonale(bebou, 0);
        return choix_chemin1(n, bebou);
    }
    if((xn == xc) and (yn < yc)){
        if(xc == 1){
            int a = 0;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            move_miroir(bebou, 6, a, 0, n);
            mur1 = true;
            compteur1 += a;
            cas_pos = 0;
            return choix_chemin1(n, bebou);
        }else if(yc == 1){
            int a = 0;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            move_miroir(bebou, 7, a, 0, n);
            mur1 = true;
            compteur1 += a;
            cas_pos = 1;
            return choix_chemin1(n, bebou);
        }
        //cout << "k11"<< endl;
        //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
        if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
        //cout << "k12"<< endl;
        //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
        deplace_carre_digaonale(bebou, 2);
        return choix_chemin1(n, bebou);
    }
    if((k == 1) or (k == -1)){
        cout<<"calcul le bon"<<endl;
        if((xn < xc) and (yn > yc)){
            //cout << "k13"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            //cout << "k14"<< endl;
            deplace_carre_digaonale(bebou, 3);
            return choix_chemin1(n, bebou);
        }
        if((xn > xc) and (yn > yc)){
            //cout << "k15"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            //cout << "k16"<< endl;
            deplace_carre_digaonale(bebou, 0);
            return choix_chemin1(n, bebou);
        }
        if((xn < xc) and (yn < yc)){
            //cout << "k17"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            //cout << "k18"<< endl;
            deplace_carre_digaonale(bebou, 2);
            return choix_chemin1(n, bebou);
        }
        if((xn > xc) and (yn < yc)){
            //cout << "k19"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur1; obstacle = 1; }
            //cout << "k20"<< endl;
            deplace_carre_digaonale(bebou, 1);
            return choix_chemin1(n, bebou);
        }
    }
}

void Collector::choix_chemin2(Nourriture& n, Carre& bebou){
    if((bebou.x == n.get_x()) and (bebou.y == n.get_y())){
        return;
    }
    //cout << "OBSTACLE 2 : " << obstacle << endl;
    if(!obstacle) ++obs2;
    double k;
    double xn = n.get_x(), yn = n.get_y();
    double xc = bebou.x, yc = bebou.y;
    if(xn == xc){
        k = 200;
    }else{
        k = (yn - yc)/(xn - xc);
    }
    if((xn - x1) != 0){
        if((xn > xc) and (k > -1) and (k < 1)){
            if(xc == g_max-2){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
                move_miroir(bebou, 4, a, 1, n);
                mur2 = true;
                compteur2 += a;
                cas_pos = 2;
                return choix_chemin2(n, bebou);
            }else if(yc == g_max-2){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
                move_miroir(bebou, 5, a, 1, n);
                mur2 = true;
                compteur2 += a;
                cas_pos = 3;
                return choix_chemin2(n, bebou);
            }
            //cout << "c1"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            //cout<<"c2"<< endl;
            deplace_carre_digaonale(bebou, 0);
            return choix_chemin2(n, bebou);
        }
        if((xn < xc) and (k > -1) and (k < 1)){
            if(xc == 1){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
                move_miroir(bebou, 6, a, 1, n);
                mur2 = true;
                compteur2 += a;
                cas_pos = 0;
                return choix_chemin2(n, bebou);
            }else if(yc == 1){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
                move_miroir(bebou, 7, a, 1, n);
                mur2 = true;
                compteur2 += a;
                cas_pos = 1;
                return choix_chemin2(n, bebou);
            }
            //cout << "c3"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            //cout << "c4"<< endl;
            deplace_carre_digaonale(bebou, 2);
            return choix_chemin2(n, bebou);
        }
    }
    if(yn != yc){
        if((yn > yc) and ((k > 1) or (k < -1))){
            if(xc == 1){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
                move_miroir(bebou, 2, a, 1, n);
                mur2 = true;
                compteur2 += a;
                cas_pos = 0;
                return choix_chemin2(n, bebou);
            }else if(yc == g_max - 2){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
                move_miroir(bebou, 3, a, 1, n);
                mur2 = true;
                compteur2 += a;
                cas_pos = 3;
                return choix_chemin2(n, bebou);
            }
            //cout << "c5"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            //cout << "c6"<< endl;
            deplace_carre_digaonale(bebou, 3);
            return choix_chemin2(n, bebou);
        }
        if((yn < yc) and ((k > 1) or (k < -1))){
            if(xc == g_max-2){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
                move_miroir(bebou, 0, a, 1, n);
                mur2 = true;
                compteur2 += a;
                cas_pos = 2;
                return choix_chemin2(n, bebou);
            }else if(yc == 1){
                int a = 0;
                if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
                move_miroir(bebou, 1, a, 1, n);
                mur2 = true;
                compteur2 += a;
                cas_pos = 1;
                return choix_chemin2(n, bebou);
            }
            //cout << "c7"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            //cout << "c8"<< endl;
            deplace_carre_digaonale(bebou, 1);
            return choix_chemin2(n, bebou);
        }
    }
    if((xn == xc) and (yn > yc)){
        if(xc == 1){
            int a = 0;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            move_miroir(bebou, 2, a, 1, n);
            mur2 = true;
            compteur2 += a;
            cas_pos = 0;
            return choix_chemin2(n, bebou);
        }else if(yc == g_max - 2){
            int a = 0;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            move_miroir(bebou, 3, a, 1, n);
            mur2 = true;
            compteur2 += a;
            cas_pos = 3;
            return choix_chemin2(n, bebou);
        }
        //cout << "c9"<< endl;
        //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
        if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
        //cout << "c10"<< endl;
        //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
        deplace_carre_digaonale(bebou, 3);
        return choix_chemin2(n, bebou);
    }
    if((xn == xc) and (yn < yc)){
        if(xc == g_max-2){
            int a = 0;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            move_miroir(bebou, 0, a, 1, n);
            mur2 = true;
            compteur2 += a;
            cas_pos = 2;
            return choix_chemin2(n, bebou);
        }else if(yc == 1){
            int a = 0;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            move_miroir(bebou, 1, a, 1, n);
            mur2 = true;
            compteur2 += a;
            cas_pos = 1;
            return choix_chemin2(n, bebou);
        }
        //cout << "c11"<< endl;
        //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
        if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
        //cout << "c12"<< endl;
        //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
        deplace_carre_digaonale(bebou, 1);
        return choix_chemin2(n, bebou);
    }
    if((k == 1) or (k == -1)){
        if((xn < xc) and (yn > yc)){
            //cout << "c13"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            //cout << "c14"<< endl;
            deplace_carre_digaonale(bebou, 3);
            return choix_chemin2(n, bebou);
        }
        if((xn > xc) and (yn > yc)){
            //cout << "c15"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            //cout << "c16"<< endl;
            deplace_carre_digaonale(bebou, 0);
            return choix_chemin2(n, bebou);
        }
        if((xn < xc) and (yn < yc)){
            //cout << "c17"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            //cout << "c18"<< endl;
            deplace_carre_digaonale(bebou, 2);
            return choix_chemin2(n, bebou);
        }
        if((xn > xc) and (yn < yc)){
            //cout << "c19"<< endl;
            //cout << "BEBOU X : " << bebou.x << "  Y : " << bebou.y << endl;
            if(carre_libre_dans_carre(bebou)){ ++compteur2; obstacle = 1; }
            //cout << "c20"<< endl;
            deplace_carre_digaonale(bebou, 1);
            return choix_chemin2(n, bebou);
        }
    }
}

void Collector::move1(Nourriture& n){
    cout << "move1"<<endl;
    double xn = n.get_x(), yn = n.get_y();
    double xc = x1, yc = y1;
    double k;
    cout << "xn: "<<xn<<" yn: "<<yn<<" xc: "<<xc<<" yc: "<< yc<<endl;
    unsigned int a, b;
    if(xn == xc){
        k = 200;
    }else{
        k = (yn - yc)/(xn - xc);
    }
    cout<<" k: "<<k<<endl;
    if((xn - x1) != 0){
        if((xn > x1) and (k > -1) and (k < 1)){
            cout << "rentre la"<< endl;
            Carre test = {x1+1, y1-1, 3};
            //cout << "TEST: x: " << test.x << " y: " << test.y << endl;
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                //cout << "A ca bouge pas" << endl;
                return;
            }
            //cout << "ca bouge" << endl;
            ++x1; --y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }   
        if((xn < x1) and (k > -1) and (k < 1)){
            Carre test = {x1-1, y1+1, 3};
            //cout << "TEST: x: " << test.x << " y: " << test.y << endl;
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                //cout << "B ca bouge pas" << endl;
                return;
            }
           //cout << "ca bouge" << endl;
            --x1; ++y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
    if((yn - y1) != 0){
        if((yn > y1) and ((k > 1) or (k < -1))){
            Carre test = {x1+1, y1+1, 3};
            //cout << "TEST: x: " << test.x << " y: " << test.y << endl;
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                //cout << "C ca bouge pas" << endl;
                return;
            }
            //cout << "ca bouge" << endl;
            ++x1; ++y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
        if((yn < y1) and ((k > 1) or (k < -1))){
            Carre test = {x1-1, y1-1, 3};
            //cout << "TEST: x: " << test.x << " y: " << test.y << endl;
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                //cout << "D ca bouge pas" << endl;
                return;
            }
            //cout << "ca bouge" << endl;
            --x1; --y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
}

void Collector::move2(Nourriture& n){
    double xn = n.get_x(), yn = n.get_y();
    double xc = x1, yc = y1;
    double k;
    unsigned int a, b;
    if(xn == xc){
        k = 200;
    }else{
        k = (yn - yc)/(xn - xc);
    }
    if((xn - x1) != 0){
        if((xn > x1) and (k > -1) and (k < 1)){
            Carre test = {x1+1, y1+1, 3};
            //cout << "TEST: x: " << test.x << " y: " << test.y << endl;
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                //cout << "E ca bouge pas" << endl;
                return;
            }
            //cout << "ca bouge" << endl;
            ++x1; ++y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }   
        if((xn < x1) and (k > -1) and (k < 1)){
            Carre test = {x1-1, y1+1, 3};
            //cout << "TEST: x: " << test.x << " y: " << test.y << endl;
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                //cout << "F ca bouge pas" << endl;
                return;
            }
            //cout << "ca bouge" << endl;
            --x1; ++y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
    if((yn - y1) != 0){
        if((yn > y1) and ((k > 1) or (k < -1))){
            Carre test = {x1-1, y1+1, 3};
            //cout << "TEST: x: " << test.x << " y: " << test.y << endl;
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                //cout << "G ca bouge pas" << endl;
                return;
            }
            //cout << "ca bouge" << endl;
            --x1; ++y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
        if((yn < y1) and ((k > 1) or (k < -1))){
            Carre test = {x1+1, y1-1, 3};
            //cout << "TEST: x: " << test.x << " y: " << test.y << endl;
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                //cout << "H ca bouge pas" << endl;
                return;
            }
            //cout << "ca bouge" << endl;
            ++x1; --y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
}

void Collector::move_direct(Nourriture& n){
    double xn = n.get_x(), yn = n.get_y();
    double xc = x1, yc = y1;
    double k = (yn - yc)/(xn - xc);
    unsigned int a, b;
    if(k == 1){
        if(xn > x1){
            Carre test = {x1+1, y1+1, 3};
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                cout << "I ca bouge pas" << endl;
                return;
            }
            cout << "ca bouge" << endl;
            ++x1; ++y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
        if(xn < x1){
            Carre test = {x1-1, y1-1, 3};
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                cout << "J ca bouge pas" << endl;
                return;
            }
            cout << "ca bouge" << endl;
            --x1; --y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
    if(k == -1){
        if(xn > x1){
            Carre test = {x1+1, y1-1, 3};
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                cout << "K ca bouge pas" << endl;
                return;
            }
            cout << "ca bouge" << endl;
            ++x1; --y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
        if(xn < x1){
            Carre test = {x1-1, y1+1, 3};
            supprimer_carre(cc);
            if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                ++age;
                initialise_carre_centre(cc);
                cout << "L ca bouge pas" << endl;
                return;
            }
            cout << "ca bouge" << endl;
            --x1; ++y1; ++age;
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
}

void Collector::move_miroir(Carre& bebou, unsigned int miroir, int& a, bool chemin, Nourriture& n){
    int vx = n.get_x() - bebou.x;
    int vy = n.get_y() - bebou.y;

    int l1 = abso(vx - vy);
    int l2 = abso(vx + vy);
    //cout << "vx: "<<vx<<" vy :"<<" l1: "<< l1 <<" l2: "<<l2<< endl;
    switch(miroir){
        case 0: {
            for (int i = 0; i <= l1; ++i)
            {
                if(!obstacle){
                    //cout << "entree pas d'obstacle, CHEMIN : " << chemin << endl;;
                    if(!chemin) ++obs1; //chemin1
                    if(chemin) ++obs2;  //chemin2
                }
                if(i < l1/2){
                    deplace_carre_digaonale(bebou, 2);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }else{
                    deplace_carre_digaonale(bebou, 1);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }
            }
            break;
        }
        case 1: {
            //cout << "entre dans le bon case"<< endl;
            for (int i = 0; i < l1; ++i)
            {
                if(!obstacle){
                    //cout<<" entre l1127"<<endl;
                    if(!chemin) ++obs1; //chemin1
                    if(chemin) ++obs2;  //chemin2
                }
                if(i < l1/2){
                    //cout << " entre la"<<endl;
                    deplace_carre_digaonale(bebou, 0);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }else{
                    //cout << " entre la 2"<<endl;
                    deplace_carre_digaonale(bebou, 1);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }
            }
            cout << " tout c'est bien passé ?: bebou.x: "<< bebou.x<<" bebou.y: "<< bebou.y<<endl;
            break;
        }
        case 2: {
            for (int i = 0; i < l1; ++i)
            {
                if(!obstacle){
                    if(!chemin) ++obs1; //chemin1
                    if(chemin) ++obs2;  //chemin2
                }
                if(i < l1/2){
                    deplace_carre_digaonale(bebou, 0);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }else{
                    deplace_carre_digaonale(bebou, 3);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }
            }
            break;
        }
        case 3: {
            for (int i = 0; i < l1; ++i)
            {
                if(!obstacle){
                    if(!chemin) ++obs1; //chemin1
                    if(chemin) ++obs2;  //chemin2
                }
                if(i < l1/2){
                    deplace_carre_digaonale(bebou, 2);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }else{
                    deplace_carre_digaonale(bebou, 3);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }
            }
            break;
        }
        case 4: {
            for (int i = 0; i < l2; ++i)
            {
                if(!obstacle){
                    if(!chemin) ++obs1; //chemin1
                    if(chemin) ++obs2;  //chemin2
                }
                if(i < l2/2){
                    deplace_carre_digaonale(bebou, 3);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }else{
                    deplace_carre_digaonale(bebou, 0);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }
            }
            break;
        }
        case 5: {
            for (int i = 0; i < l2; ++i)
            {
                if(!obstacle){
                    if(!chemin) ++obs1; //chemin1
                    if(chemin) ++obs2;  //chemin2
                }
                if(i < l2/2){
                    deplace_carre_digaonale(bebou, 1);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }else{
                    deplace_carre_digaonale(bebou, 0);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }
            }
            break;
        }
        case 6: {
            for (int i = 0; i < l2; ++i)
            {
                if(!obstacle){
                    if(!chemin) ++obs1; //chemin1
                    if(chemin) ++obs2;  //chemin2
                }
                if(i < l2/2){
                    deplace_carre_digaonale(bebou, 2);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }else{
                    deplace_carre_digaonale(bebou, 2);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }
            }
            break;
        }
        case 7: {
            for (int i = 0; i < l2; ++i)
            {
                if(!obstacle){
                    if(!chemin) ++obs1; //chemin1
                    if(chemin) ++obs2;  //chemin2
                }
                if(i < l2/2){
                    deplace_carre_digaonale(bebou, 3);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }else{
                    deplace_carre_digaonale(bebou, 2);
                    if(carre_libre_dans_carre(bebou)) {++a; obstacle = 1;}
                }
            }
        }
        default:
        break;
    }
}

void Collector::deplace_miroir(int cas, Nourriture& n){
    cout<<"deplace miroir"<< endl;
    int xn = n.get_x();
    int yn = n.get_y();
    int x2 = x1, y2 = y1;
    unsigned int a, b;

    switch(cas){
        case 0: {
            cout<< "cas 0, "<< endl;
            unsigned int dis = (y2 - (yn+g_max-1-xn)/2);
            cout<< "dis :  "<< dis << endl;
            if(g_max-1-x1 < dis){
                Carre test = {x1 -1, y1 - 1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "M ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge en bas a gauche" << endl;
                --x1; --y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
            }else{
                Carre test = {x1 + 1, y1 - 1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "N ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge en bas a droite" << endl;
                ++x1; --y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
                if(x1 == g_max-2){
                    hebs = 0;
                }
            }
            break;
        }
        case 1: {
            cout<< "cas 1, "<< endl;
            unsigned int dis = (((xn-yn) -x2)/2);
            cout<< "dis : "<< dis << endl;
            if(y1 < dis){
                Carre test = {x1+1, y1+1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "O ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge en haut a droite" << endl;
                ++x1; ++y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
            }else{
                Carre test = {x1+1, y1-1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "P ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge en bas a droite" << endl;
                ++x1; --y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
                if(y1 == 1){
                    hebs = 0;
                }
            }
            break;
        }
        case 2: {
            cout<< "cas 2 "<< endl;
            unsigned int dis = ((yn-xn-y2)/2);
            cout<< "dis:  "<< dis << endl;
            if(x1 < dis){
                Carre test = {x1+1, y1+1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "Q ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge en haut a droite" << endl;
                ++x1; ++y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
            }else{
                Carre test = {x1-1, y1+1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "R ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge" << endl;
                --x1; ++y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
                if(x1 == 1){
                    hebs = 0;
                }
            }
            break;
        }
        case 3: {
            cout<< "cas 3 "<< endl;
            unsigned int dis = ((xn+(g_max-1-yn)-x2)/2);
            cout<< "dis: "<<dis<< endl;
            if(g_max-1-y1 < dis){
                Carre test = {x1-1, y1-1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "S ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge" << endl;
                --x1; --y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
            }else{
                Carre test = {x1-1, y1+1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "T ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge" << endl;
                --x1; ++y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
                if(y1 == g_max-2){
                    hebs = 0;
                }
            }
            break;
        }
        case 4: {
            cout<< "cas 4 "<< endl;
            unsigned int dis = (((yn+g_max-1-xn)-y2)/2);
            cout<< "dis: "<< dis << endl;
            for (size_t i = 0; i < dis; i++)
            if(g_max-1-x1 < dis){
                Carre test = {x1-1, y1+1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "U ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge" << endl;
                --x1; ++y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
            }else{
                Carre test = {x1+1, y1+1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "V ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge" << endl;
                ++x1; ++y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
                if(x1 == g_max - 2){
                    hebs = 0;
                }
            }
            break;
        }
        case 5: {

            unsigned int dis = (((xn-g_max-1+yn)-x2)/2);
            cout << "cas 5, dis: " << dis << endl;
            if(g_max-1-y1 <= dis){
                Carre test = {x1+1, y1-1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "W ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge" << endl;
                ++x1; --y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
            }else{
                Carre test = {x1+1, y1+1, 3};
                supprimer_carre(cc);
                cout << cc.x << " " << cc.y << endl;
                cout << test.x << " " << test.y << " " << test.side << endl;
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    cout << "a " << a << " b " << b << endl;
                    initialise_carre_centre(cc);
                    cout << "X ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge" << endl;
                ++x1; ++y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
                if(y1 == g_max - 2){
                    hebs = 0;
                }
            }
            break;
        }
        case 6: {
            unsigned int dis = ((y2-yn+xn)/2);
            cout << "cas 6, dis: " << dis << endl;
            if(x1 < dis){
                Carre test = {x1+1, y1-1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "Y ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge" << endl;
                ++x1; --y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
            }else{
                Carre test = {x1-1, y1-1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "Z ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge" << endl;
                --x1; --y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
                if(x1 == 1){
                    hebs = 0;
                }
            }
            
        }
        case 7: {
            unsigned int dis = ((x2-xn+yn)/2);
            cout << "cas 7, dis: " << dis << endl;
            if(y1 < dis){
                Carre test = {x1-1, y1+1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "ZA ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge" << endl;
                --x1; ++y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
            }else{
                Carre test = {x1-1, y1-1, 3};
                supprimer_carre(cc);
                if(sup_coord(test, a, b) and ((a != n.get_x()) and (b != n.get_y()))){
                    ++age;
                    initialise_carre_centre(cc);
                    cout << "ZB ca bouge pas" << endl;
                    return;
                }
                cout << "ca bouge" << endl;
                --x1; --y1; ++age;
                cc = {x1, y1, 3};
                initialise_carre_centre(cc);
                if(x1 == 1){
                    hebs = 0;
                }
            }
        }
    }
}
void Collector::detection_f_rival(unsigned int& A, unsigned int& B, unsigned int rog_one,unsigned int rog_two, unsigned int& GROGU, unsigned int h, unsigned int k){
    cout<< "fault"<< endl;
}
void Defensor::detection_f_rival(unsigned int& A, unsigned int& B, unsigned int rog_one,unsigned int rog_two, unsigned int& GROGU, unsigned int h, unsigned int k){
    cout<< "fault"<< endl;
}
void Generator::detection_f_rival(unsigned int& A, unsigned int& B, unsigned int rog_one,unsigned int rog_two, unsigned int& GROGU, unsigned int h, unsigned int k){
    cout<< "fault"<< endl;
}
void Predator::detection_f_rival(unsigned int& A, unsigned int& B, unsigned int rog_one,unsigned int rog_two, unsigned int& GROGU, unsigned int h, unsigned int k){
    double r;
    double r1= rog_one;
    double r2= rog_two;
    double X1=x1;
    double Y1=y1;
    r = abso(sqrt(pow(r1-X1,2)+pow(r2-Y1,2)));
    //cout << "r: " << r << "grogu"<< GROGU << endl;
    if ( r < GROGU){
        GROGU = r;
        A=h;
        B=k;
        //cout << "GROGU: "<< GROGU << endl;
        //cout << "A: " << A << "B: "<< B << "R: " << r << endl;
        //cout << rog_one << " " << rog_two << endl;
    }
    //cout << " good"<< endl;
    return;
}
int Predator::fight(double xb, double yb,double xa, double ya){
    double r = abso(sqrt(pow(xa-xb,2)+pow(ya-yb,2)));
    double z =r;
    //cout << "Z: "<< z << endl;
    //cout << "fight"<< endl;
    double SD = sqrt(2);
    double SC = sqrt(5);
    double SH = sqrt(8);
    if (z){
        if ((z == 1) or (z ==SD)){
            return 1;
        }
        if (( z== 2) or (z == SC) or (z == SH)){
            return 2;
        }
    }
    return 3;
}
int Collector::fight(double xb, double yb,double xa, double ya){
    cout<<"fight c"<< endl;
    return 1;
}
int Defensor::fight(double xb, double yb,double xa, double ya){
    cout <<" fight d"<< endl;
    return 1;
}
int Generator::fight(double xb, double yb,double xa, double ya){
    cout <<"fight g"<< endl;
    return 1;
}

void Predator::operation_milenium(Carre cf){
    double xa = cf.x;
    double ya = cf.y;
    double xb =x1;
    double yb = y1;
    double coef = ((ya-yb)/(xa-xb));
    int k;
    if ((xa-xb)){
        if ((xb>xa)and(yb>=ya)){
            if (coef > 1){
                //cout << "N1"<< endl;
                if (sup_sans_deformation(--x1,y1-2)){return;}
                --x1;
                y1=y1-2;
                --xb;
                yb=yb-2;
            }
            if(coef<=1){
                //cout<< "N2"<< endl;
                if (sup_sans_deformation(x1-2,--y1)){return;}
                --y1;
                x1=x1-2;
                --yb;
                 xb=xb-2;
            }
            if ((xb>xa)and (yb<ya)){
                //cout<< "N3"<< endl;
                if (coef<-1){
                    if (sup_sans_deformation(--x1,y1+2)){return;}
                    --x1;
                    y1=y1+2;
                    yb=yb+2;
                    --xb;
                    }
                    if(coef>-1){
                        //cout<< "N4"<< endl;
                        if (sup_sans_deformation(x1-2,++y1)){return;}
                        ++y1;
                        x1=x1-2;
                        ++yb;
                        xb=xb-2;
                    }

                }
            }
            if ((xb<xa)and(yb<=ya)){
                if (coef>=1){
                    //cout<< "N5"<< endl;
                    if(sup_sans_deformation(++x1,y1+2)){return;}
                    ++x1;
                    y1=y1+2;
                    ++xb;
                    yb=yb+2;
                }
                if (coef < 1){
                    //cout<< "N6"<< endl;
                    if(sup_sans_deformation(x1+2,++y1)){return;}
                    ++y1;
                    x1=x1+2;
                    ++yb;
                    xb=xb+2;
                }
            }
            if ((xb<xa) and (yb>ya)){
                if(coef >=-1 ){
                    //cout<< "N7"<< endl;
                    if(sup_sans_deformation(x1+2,--y1)){return;}
                    x1= x1 +2;
                    --y1;
                    --yb;
                    xb=xb+2;
                }
                if (coef<-1){
                    //cout<< "N8"<< endl;
                    if(sup_sans_deformation(++x1,y1-2)){return;}
                    y1=y1-2;
                    ++x1;
                    yb=yb-2;
                    ++xb;
                }
            }
    }
    cout << "Rentre chez toi" << endl;
}
void Collector::operation_milenium(Carre cf){
    //moove();
    cout << "Collector retour a la casa "<< endl;
}
void Defensor::operation_milenium(Carre cf){
cout << "Defensor retour a la casa "<< endl;
}
void Generator::operation_milenium(Carre cf){
cout << "Generator retour a la casa "<< endl;
}
int Generator::move(Nourriture& n, unsigned int t1, unsigned int t2){
    cout << "move G" << endl;
}

int Defensor(Nourriture& n, unsigned int t1, unsigned int t2){
    cout << "move D" << endl;
}

int Predator::move(Nourriture& n, unsigned int t1, unsigned int t2){
    double xa = t1;
    double ya = t2;
    double xb =x1;
    double yb = y1;
    double coef = ((ya-yb)/(xa-xb));
    int k;
    if ((xa-xb)){
            if ((xb>xa)and(yb>=ya)){

                if (coef > 1){
                    if (sup_sans_deformation(--x1,y1-2)){return 0;}
                    --x1;
                    y1=y1-2;
                    --xb;
                    yb=yb-2;
                    k=fight(xb,yb,xa,ya);
                }
                if(coef<=1){
                if (sup_sans_deformation(x1-2,--y1)){return 0;}
                --y1;
                x1=x1-2;
                --yb;
                xb=xb-2;
                k=fight(xb,yb,xa,ya);
            }
            if ((xb>xa)and (yb<ya)){
                if (coef<-1){
                    if (sup_sans_deformation(--x1,y1+2)){return 0;}
                    --x1;
                    y1=y1+2;
                    yb=yb+2;
                    --xb;
                    k=fight(xb,yb,xa,ya);
                    }
                    if(coef>-1){
                        if (sup_sans_deformation(x1-2,++y1)){return 0;}
                        ++y1;
                        x1=x1-2;
                        ++yb;
                        xb=xb-2;
                        k=fight(xb,yb,xa,ya);
                    }

                }
            }
            if ((xb<xa)and(yb<=ya)){
                if (coef>=1){
                    if(sup_sans_deformation(++x1,y1+2)){return 0;}
                    ++x1;
                    y1=y1+2;
                    ++xb;
                    yb=yb+2;
                    k=fight(xb,yb,xa,ya);
                }
                if (coef < 1){
                    if(sup_sans_deformation(x1+2,++y1)){return 0;}
                    ++y1;
                    x1=x1+2;
                    ++yb;
                    xb=xb+2;
                    k=fight(xb,yb,xa,ya);
                }
            }
            if ((xb<xa) and (yb>ya)){
                if(coef >=-1 ){
                    if(sup_sans_deformation(x1+2,--y1)){return 0;}
                    --y1;
                    x1= x1 +2;
                    --yb;
                    xb=xb+2;
                    k=fight(xb,yb,xa,ya);
                }
                if (coef<-1){
                    if(sup_sans_deformation(++x1,y1-2)){return 0;}
                    y1=y1-2;
                    ++x1;
                    yb=yb-2;
                    ++xb;
                    k=fight(xb,yb,xa,ya);
                }
            }
    }
    cout << "move P" << endl;
    return k;
}
int Collector::contrained_attack(unsigned int t1,unsigned int t2,Carre cf){
    cout << "rien"<<endl;
    return 0;
}
int Defensor::contrained_attack(unsigned int t1,unsigned int t2,Carre cf){
    cout << "rien"<<endl;
    return 0;
}
int Generator::contrained_attack(unsigned int t1,unsigned int t2,Carre cf){
    cout << "rien"<<endl;
    return 0;
}
int Predator::contrained_attack(unsigned int t1,unsigned int t2, Carre cf){
    double xa = t1;
    double ya = t2;
    double xb =x1;
    double yb = y1;
    Carre cn = {x1,y1,1};
    double coef = ((ya-yb)/(xa-xb));
    int k;
    if ((xa-xb)){
        if ((xb>xa)and(yb>=ya)){
            if (coef > 1){
                cn.x= --x1;
                cn.y= y1-2;
                if (sup_sans_deformation(--x1,y1-2)){return 0;}
                if (carre_dans_carre(cf,cn)){return 0;}
                cp.x= --x1;
                cp.y= y1-2;
                --x1;
                y1=y1-2;
                --xb;
                yb=yb-2;
                k=fight(xb,yb,xa,ya);
                }
                if(coef<=1){
                    cn.x=x1-2;
                    cn.y=--y1;
                    if (carre_dans_carre(cf,cn)){return 0;}
                    if (sup_sans_deformation(x1-2,--y1)){return 0;}
                    cp.x=x1-2;
                    cp.y=--y1;
                    --y1;
                    x1=x1-2;
                    --yb;
                    xb=xb-2;
                    k=fight(xb,yb,xa,ya);
                }
            }
        if ((xb>xa)and (yb<ya)){
            if (coef<-1){
                cn.x=--x1;
                cn.y=y1+2;
                if (carre_dans_carre(cf,cn)){return 0;}
                if (sup_sans_deformation(--x1,y1+2)){return 0;}
                cp.x=--x1;
                cp.y=y1+2;
                --x1;
                y1=y1+2;
                yb=yb+2;
                --xb;
                k=fight(xb,yb,xa,ya);
            }
            if(coef>-1){
                cn.x=x1-2;
                cn.y=++y1;
                if (carre_dans_carre(cf,cn)){return 0;}
                if (sup_sans_deformation(x1-2,++y1)){return 0;}
                cp.x=x1-2;
                cp.y=++y1;
                ++y1;
                x1=x1-2;
                ++yb;
                xb=xb-2;
                k=fight(xb,yb,xa,ya);
            }
        }
        
        if ((xb<xa)and(yb<=ya)){
            if (coef>=1){
                cn.x=++x1;
                cn.y=y1+2;
                if (carre_dans_carre(cf,cn)){return 0;}
                if(sup_sans_deformation(++x1,y1+2)){return 0;}
                cp.x=++x1;
                cp.y=y1+2;
                ++x1;
                y1=y1+2;
                ++xb;
                yb=yb+2;
                k=fight(xb,yb,xa,ya);
            }
            if (coef < 1){
                cn.x=x1+2;
                cn.y=++y1;
                if (carre_dans_carre(cf,cn)){return 0;}
                if(sup_sans_deformation(x1+2,++y1)){return 0;}
                cp.x=x1+2;
                cp.y=++y1;
                ++y1;
                x1=x1+2;
                ++yb;
                xb=xb+2;
                k=fight(xb,yb,xa,ya);
            }
        }
        if ((xb<xa) and (yb>ya)){
            if(coef >=-1 ){
                cn.x=x1+2;
                cn.y=--y1;
                if (carre_dans_carre(cf,cn)){return 0;}
                if(sup_sans_deformation(x1+2,--y1)){return 0;}
                cp.x=x1+2;
                cp.y=--y1;
                --y1;
                x1= x1 +2;
                --yb;
                xb=xb+2;
                k=fight(xb,yb,xa,ya);
            }
            if (coef<-1){
                cn.x=++x1;
                cn.y=y1-2;
                if (carre_dans_carre(cf,cn)){return 0;}
                if(sup_sans_deformation(++x1,y1-2)){return 0;}
                cp.x=++x1;
                cp.y=y1-2;
                y1=y1-2;
                ++x1;
                yb=yb-2;
                ++xb;
                k=fight(xb,yb,xa,ya);
            }
        }
    }
    return k;
}