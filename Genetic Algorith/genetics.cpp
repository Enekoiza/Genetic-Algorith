#include "genetics.h"



// Constructor
genetics::genetics(string dataFile, int populationSizes)
{
	populationSize = new int;

	// The population size will be pass through the constructor
	*populationSize = populationSizes;

	// Use the file to create itemGroup pointers
	for (int i = 0; i < *populationSize; i++)
	{
		geneticExample.push_back(new itemGroup(dataFile));
	}


}

// Destructor
genetics::~genetics()
{
	// Delete every itemGroup pointer that conforms the geneticExample.
	for (int j = *populationSize - 1; j >= 0; j--) delete geneticExample[j];

	// Delete the population size pointer
	if (populationSize != NULL) delete populationSize;

}

// A getter to return the population of the geneticExample
int genetics::getPopulation()
{
	return *populationSize;
}

// A getter to return the geneticExample
vector<itemGroup*> genetics::getGeneticExample()
{
	return geneticExample;
}

// A setter to set a new geneticExample
void genetics::setGeneticExample(vector<itemGroup*> geneticExample)
{
	this->geneticExample = geneticExample;
}

// A function to get the min value among the solutions
int genetics::calculateMin()
{
	int minValue = 0;
	int temp = 0;

	for (auto it : geneticExample)
	{
		temp = it->getSolutionFitness();
		if (temp < minValue) minValue = temp;
	}

	return minValue;
}

// A function to get the max value among the solutions
int genetics::calculateMax()
{

	int maxValue = 0;
	int temp = 0;
	
	for (auto it : geneticExample)
	{
		temp = it->getSolutionFitness();
		if (temp > maxValue) maxValue = temp;
	}

	return maxValue;
}

// A function to get the avg value among the solutions
int genetics::calculateAverage()
{
	int temp = 0;
	int averageValue = 0;


	// Iterate through the geneticExample vector and get the solution fitnes, and sum them
	for (auto it : geneticExample)
	{
		averageValue += it->getSolutionFitness();
	}

	// Divided by the population that conform the geneticExample vector to calculate the average.
	averageValue = averageValue / *populationSize;


	return averageValue;
}


