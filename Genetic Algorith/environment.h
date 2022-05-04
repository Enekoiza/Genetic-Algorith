#include <string>
#include "genetics.h"
#include <fstream>



#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

using std::string;


class environment
{
private:
	int generationsNumber = 300;
	string selectionMethod = "Tournament";
	int tournamentSize = 4;
	string crossoverMethod = "One-Point";
	float crossoverTreshold = 0.7;
	float mutationTreshold = 0.2;


public:
	environment() {};
	~environment() {};




	void run();

};














#endif // !ENVIRONMENT_H
