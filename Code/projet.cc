//projet.cc
//Mouhamad: 50%
//Louis: 50%
#include "simulation.h"

using namespace std;

int main(int argc, char * argv[])
{
	Simulation s;
	if(argc != 2){
		exit(0);
	}
	
	s.lancement(argv[1]);
	
	return 0;
}
