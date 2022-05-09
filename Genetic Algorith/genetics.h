#include "itemGroup.h"
#include <time.h>


// Header guards
#ifndef GENETICS_H
#define GENETICS_H




class genetics
{
private:
	vector<itemGroup*> geneticExample;									// A vector that holds all the itemGroup (solutions)
	int* populationSize = NULL;											// A pointer that will hold the population size of the genetic class



public:

	genetics(string dataFile, int populationSizes);						// Constructor

	~genetics();														// Destructor



	int getPopulation();												// A getter to return the population of the geneticExample

	vector<itemGroup*> getGeneticExample();								// A getter to return the geneticExample

	void setGeneticExample(vector<itemGroup*> geneticExample);			// A setter to set a new geneticExample

	int calculateMin();													// A function to get the min value among the solutions
	int calculateMax();													// A function to get the max value among the solutions
	int calculateAverage();												// A function to get the avg value among the solutions

};



#endif // !GENETICS_H
