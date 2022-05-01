//projet.cc
//Mouhamad: 50%
//Louis: 50%
#include "simulation.h"
#include "gui.h"
using namespace std;

int main(int argc, char * argv[])
{
	Simulation s;
	if(argc == 2){
        s.lancement(argv[1]);
        argc = 1;
	}
	
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
	
	MyEvent win;
	win.set_simulation(&s);
	win.set_title("Side Drawing");
	win.set_default_size(300, 200);
	
	return app->run(win);
}
