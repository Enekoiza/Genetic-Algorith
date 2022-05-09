#include <string>
#include "genetics.h"
#include <fstream>


// Header guards
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

using std::string;


class environment
{
private:
	int* generationsNumber = NULL;						// A pointer that holds the number of loops
	string* selectionMethod = NULL;						// A pointer that holds the type of selection
	int* tournamentSize = NULL;							// A pointer that holds the number of participants in a tournament selection method
	string* crossoverMethod = NULL;						// A pointer that holds the method selected for crossover
	float* crossoverTreshold = NULL;					// A pointer that holds the percentage where the crossover would come to action
	float* mutationTreshold = NULL;						// A pointer that holds the percentage where the mutation would come to action
	string* dataFile = NULL;							// A pointer that holds a string with the name of the file that must be read to create the items
	int* populationSize = NULL;							// A pointer that holds the size of the genetic example.


public:
	
	environment();										// Constructor
	~environment();										// Destructor




	void run();											// Method to run the genetic algorithm where the selection method is tournament

};














#endif // !ENVIRONMENT_H
