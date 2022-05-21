//fourmis.cc
//Mouhamad: 50%
//Louis: 50%
#include "fourmis.h"
using namespace std;

int Fourmis::compteur1 = 0;
int Fourmis::compteur2 = 0;
int Fourmis::compteur3 = 0;

Generator::Generator(unsigned int x1, unsigned int y1,
                     unsigned int total_food, Carre cg)
    : Fourmis(x1, y1), total_food(total_food), cg(cg) {}

Collector::Collector(unsigned int x1, unsigned y1, unsigned int age, bool food)
: Fourmis(x1, y1), age(age), food(food) {}

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

void Collector::setcc(unsigned int& x2, unsigned int& y2){
	cc = {x2, y2, sizeC};
}

void Collector::d_ant(double r, double g, double b){
    double s = sizeC;
    dessin_carre_croix(x1, y1, s, r, g, b);
}
 

void Defensor::ini_d(unsigned int& x2, unsigned int& y2, unsigned int& age2)
{
    x1 = x2;
    y1 = y2;
    age = age2;
    setcd(x2, y2);
}

void Defensor::setcd(unsigned int& x2, unsigned int& y2){
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

void Predator::setcp(unsigned int& x2, unsigned int& y2){
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
    return age;
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
    int K = 0;
    unsigned int A = 0;
    for(size_t i = 0; i < n.size(); ++i){
        if (fabs(n[i].get_x()-x1) >= fabs(n[i].get_y()-y1)){
            T = fabs(n[i].get_x()-x1);
            if (T < K){
                K=T;
                A=i;
            }
        }else{
            T = fabs(n[i].get_y()-y1);
            if (T < K){
                K=T;
                A=i;
            }
        }
    }
    return A;
}

void Collector::move(Nourriture& n){
    unsigned int miroir = 20;
    Carre bebou = cc;
    cout << "chemin 1"<< endl;
    choix_chemin1(n, bebou, miroir);
    bebou = cc;
    cout << "chemin2"<< endl;
    choix_chemin2(n, bebou, miroir);

    if(compteur1 > compteur2){
        move2(n);
    }
    if(compteur1 < compteur2){
        move1(n);
    }
    if(compteur1 == compteur2){
        move_direct(n);
    }
    compteur1 = 0, compteur2 = 0;
}

void Collector::choix_chemin1(Nourriture& n, Carre& bebou, unsigned int& miroir){
    if((bebou.x == n.get_x()) and (bebou.y == n.get_y())){
        return;
    }
    double xn = n.get_x(), yn = n.get_y();
    double xc = bebou.x, yc = bebou.y;
    double k = (yn - yc)/(xn - xc);
    if((xn - xc) != 0){
        if((xn > xc) and (k > -1) and (k < 1)){
            if((k != 1) and (k != -1) and (x1 = 0)){
                if(xc == g_max-2){
                    miroir = 0;
                    move_miroir(bebou, miroir);
                }else if(yc == 1){
                    miroir = 1;
                    move_miroir(bebou, miroir);
                }
            }
            cout << "k1"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur1;
            cout << "k2"<< endl;
            deplace_carre_digaonale(bebou, 1);
            return choix_chemin1(n, bebou, miroir);
        }
        if((xn < xc) and (k > -1) and (k < 1)){
            if(xc == 1){
                miroir = 2;
                move_miroir(bebou, miroir);
            }else if(yc == g_max - 2){
                miroir = 3;
                move_miroir(bebou, miroir);
            }
            cout << "k3"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur1;
            cout << "k4"<< endl;
            deplace_carre_digaonale(bebou, 3);
            return choix_chemin1(n, bebou, miroir);
        }
    }
    if((yn - y1) != 0){
        if((yn > yc) and ((k > 1) or (k < -1))){
            if(x1 == g_max-2){
                miroir = 4;
                move_miroir(bebou, miroir);
            }else if(y1 == g_max-2){
                miroir = 5;
                move_miroir(bebou, miroir);
            }
            cout << "k5"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur1;
            cout << "k6"<< endl;
            deplace_carre_digaonale(bebou, 0);
            return choix_chemin1(n, bebou, miroir);
        }
        if((yn < yc) and ((k > 1) or (k < -1))){
            if(xc == 1){
                miroir = 9;
                move_miroir(bebou, miroir);
            }else if(yc == 1){
                miroir = 10;
                move_miroir(bebou, miroir);
            }
            cout << "k7"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur1;
            cout << "k8"<< endl;
            deplace_carre_digaonale(bebou, 2);
            return choix_chemin1(n, bebou, miroir);
        }
    }
    if((xn == xc) and (yn > yc)){
        if(xc == g_max-2){
            miroir = 4;
            move_miroir(bebou, miroir);
        }else if(yc == g_max-2){
            miroir = 5;
            move_miroir(bebou, miroir);
        }
        cout << "k9"<< endl;
        if(carre_libre_dans_carre(bebou)) ++compteur1;
        cout << "k10"<< endl;
        deplace_carre_digaonale(bebou, 0);
        return choix_chemin1(n, bebou, miroir);
    }
    if((xn == xc) and (yn < yc)){
        if(xc == 1){
            miroir = 6;
            move_miroir(bebou, miroir);
        }else if(yc == 1){
            miroir = 8;
            move_miroir(bebou, miroir);
        }
        cout << "k11"<< endl;
        if(carre_libre_dans_carre(bebou)) ++compteur1;
        cout << "k12"<< endl;
        deplace_carre_digaonale(bebou, 2);
        return choix_chemin1(n, bebou, miroir);
    }
    if((k == 1) or (k == -1)){
        if((xn < xc) and (yn > yc)){
            cout << "k13"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur1;
            cout << "k14"<< endl;
            deplace_carre_digaonale(bebou, 3);
            return choix_chemin1(n, bebou, miroir);
        }
        if((xn > xc) and (yn > yc)){
            cout << "k15"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur1;
            cout << "k16"<< endl;
            deplace_carre_digaonale(bebou, 0);
            return choix_chemin1(n, bebou, miroir);
        }
        if((xn < xc) and (yn < yc)){
            cout << "k17"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur1;
            cout << "k18"<< endl;
            deplace_carre_digaonale(bebou, 2);
            return choix_chemin1(n, bebou, miroir);
        }
        if((xn > xc) and (yn < yc)){
            cout << "k19"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur1;
            cout << "k20"<< endl;
            deplace_carre_digaonale(bebou, 1);
            return choix_chemin1(n, bebou, miroir);
        }
    }
}

void Collector::choix_chemin2(Nourriture& n, Carre& bebou, unsigned int& miroir){
    if((bebou.x == n.get_x()) and (bebou.y == n.get_y())){
        return;
    }
    double xn = n.get_x(), yn = n.get_y();
    double xc = bebou.x, yc = bebou.y;
    double k = (yn - yc)/(xn - xc);
    if((xn - x1) != 0){
        if(x1 == g_max-2){
            miroir = 4;
            move_miroir(bebou, miroir);
        }else if(y1 == g_max-2){
            miroir = 5;
            move_miroir(bebou, miroir);
        }
            cout << "c1"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur2;
            cout<<"c2"<< endl;
            deplace_carre_digaonale(bebou, 0);
            return choix_chemin2(n, bebou, miroir);
        }
        if((xn < xc) and (k > -1) and (k < 1)){
            if(xc == 1){
            miroir = 9;
            move_miroir(bebou, miroir);
        }else if(yc == 1){
            miroir = 10;
            move_miroir(bebou, miroir);
        }
            cout << "c3"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur2;
            cout << "c4"<< endl;
            deplace_carre_digaonale(bebou, 2);
            return choix_chemin2(n, bebou, miroir);
        }
    }
    if((yn - yc) != 0){
        if((yn > yc) and ((k > 1) or (k < -1))){
            if(xc == 1){
                miroir = 2;
                move_miroir(bebou, miroir);
            }else if(yc == g_max - 2){
                miroir = 3;
                move_miroir(bebou, miroir);
            }
            cout << "c5"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur2;
            cout << "c6"<< endl;
            deplace_carre_digaonale(bebou, 3);
            return choix_chemin2(n, bebou, miroir);
        }
        if((yn < yc) and ((k > 1) or (k < -1))){
            if(xc == g_max-2){
                miroir = 0;
                move_miroir(bebou, miroir);
            }else if(yc == 1){
                miroir = 1;
                move_miroir(bebou, miroir);
            }
            cout << "c7"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur2;
            cout << "c8"<< endl;
            deplace_carre_digaonale(bebou, 1);
            return choix_chemin2(n, bebou, miroir);
        }
    }
    if((xn == xc) and (yn > yc)){
        if(xc == 1){
            miroir = 2;
            move_miroir(bebou, miroir);
        }else if(yc == g_max - 2){
            miroir = 3;
            move_miroir(bebou, miroir);
        }
        cout << "c9"<< endl;
        if(carre_libre_dans_carre(bebou)) ++compteur2;
        cout << "c10"<< endl;
        deplace_carre_digaonale(bebou, 3);
        return choix_chemin2(n, bebou, miroir);
    }
    if((xn == xc) and (yn < yc)){
        if(xc == g_max-2){
            miroir = 0;
            move_miroir(bebou, miroir);
        }else if(yc == 1){
            miroir = 1;
            move_miroir(bebou, miroir);
        }
        cout << "c11"<< endl;
        if(carre_libre_dans_carre(bebou)) ++compteur2;
        cout << "c12"<< endl;
        deplace_carre_digaonale(bebou, 1);
        return choix_chemin2(n, bebou, miroir);
    }
    if((k == 1) or (k == -1)){
        if((xn < xc) and (yn > yc)){
            cout << "c13"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur2;
            cout << "c14"<< endl;
            deplace_carre_digaonale(bebou, 3);
            return choix_chemin2(n, bebou, miroir);
        }
        if((xn > xc) and (yn > yc)){
            cout << "c15"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur2;
            cout << "c16"<< endl;
            deplace_carre_digaonale(bebou, 0);
            return choix_chemin2(n, bebou, miroir);
        }
        if((xn < xc) and (yn < yc)){
            cout << "c17"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur2;
            cout << "c18"<< endl;
            deplace_carre_digaonale(bebou, 2);
            return choix_chemin2(n, bebou, miroir);
        }
        if((xn > xc) and (yn < yc)){
            cout << "c19"<< endl;
            if(carre_libre_dans_carre(bebou)) ++compteur2;
            cout << "c20"<< endl;
            deplace_carre_digaonale(bebou, 1);
            return choix_chemin2(n, bebou, miroir);
        }
    }
}

void Collector::move1(Nourriture& n){
    double xn = n.get_x(), yn = n.get_y();
    double xc = x1, yc = y1;
    double k = (yn - yc)/(xn - xc);
    if((xn - x1) != 0){
        if((xn > x1) and (k > -1) and (k < 1)){
            ++x1, --y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }   
        if((xn < x1) and (k > -1) and (k < 1)){
            --x1, ++y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
    if((yn - y1) != 0){
        if((yn > y1) and ((k > 1) or (k < -1))){
            ++x1, ++y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
        if((yn < y1) and ((k > 1) or (k < -1))){
            --x1, --y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
}

void Collector::move2(Nourriture& n){
    double xn = n.get_x(), yn = n.get_y();
    double xc = x1, yc = y1;
    double k = (yn - yc)/(xn - xc);
    if((xn - x1) != 0){
        if((xn > x1) and (k > -1) and (k < 1)){
            ++x1, ++y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }   
        if((xn < x1) and (k > -1) and (k < 1)){
            --x1, ++y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
    if((yn - y1) != 0){
        if((yn > y1) and ((k > 1) or (k < -1))){
            --x1, ++y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
        if((yn < y1) and ((k > 1) or (k < -1))){
            ++x1, --y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
}

void Collector::move_direct(Nourriture& n){
    double xn = n.get_x(), yn = n.get_y();
    double xc = x1, yc = y1;
    double k = (yn - yc)/(xn - xc);
    if(k == 1){
        if(xn > x1){
            ++x1, ++y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
        if(xn < x1){
            --x1, --y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
    if(k == -1){
        if(xn > x1){
            ++x1, --y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
        if(xn < x1){
            --x1, ++y1, ++age;
            supprimer_carre(cc);
            cc = {x1, y1, 3};
            initialise_carre_centre(cc);
        }
    }
}

void Collector::move_miroir(Carre& bebou, unsigned int& miroir){
    switch(miroir){
        case 0: {
            if(compteur3 < 4){
                deplace_carre_digaonale(bebou, 2);
            }else{
                deplace_carre_digaonale(bebou, 1);
            }
        }
        case 1: {
            if(compteur3 < 4){
                deplace_carre_digaonale(bebou, 0);
            }else{
                deplace_carre_digaonale(bebou, 1);
            }
        }
        case 2: {
            if(compteur3 < 4){
                deplace_carre_digaonale(bebou, 0);
            }else{
                deplace_carre_digaonale(bebou, 3);
            }
        }
        case 3: {
            if(compteur3 < 4){
                deplace_carre_digaonale(bebou, 2);
            }else{
                deplace_carre_digaonale(bebou, 3);
            }
        }
        case 4: {
            if(compteur3 < 4){
                deplace_carre_digaonale(bebou, 3);
            }else{
                deplace_carre_digaonale(bebou, 0);
            }
        }
        case 5: {
            if(compteur3 < 4){
                deplace_carre_digaonale(bebou, 1);
            }else{
                deplace_carre_digaonale(bebou, 0);
            }
        }
        case 6: {
            if(compteur3 < 4){
                deplace_carre_digaonale(bebou, 1);
            }else{
                deplace_carre_digaonale(bebou, 2);
            }
        }
        case 7: {
            if(compteur3 < 4){
                deplace_carre_digaonale(bebou, 3);
            }else{
                deplace_carre_digaonale(bebou, 2);
            }
        }
        case 8: {
            if(compteur3 < 4){
                deplace_carre_digaonale(bebou, 3);
            }else{
                deplace_carre_digaonale(bebou, 2);
            }
        }
    }
}

void Generator::move(Nourriture& n){
    cout << "move autre chose" << endl;
}

void Defensor::move(Nourriture& n){
    cout << "move autre chose" << endl;
}

void Predator::move(Nourriture& n){
    cout << "move autre chose" << endl;
}