#include "simulation.h"
#include <iostream>
#include <vector>
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
