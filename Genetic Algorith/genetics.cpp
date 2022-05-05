#include "genetics.h"

genetics::genetics()
{
	srand(time(NULL));

	for (int i = 0; i < populationSize; i++)
	{
		geneticExample.push_back(new itemGroup(dataFile));
	}

}

genetics::~genetics()
{
	for (int j = populationSize - 1; j >= 0; j--)
	{
		delete geneticExample[j];
	}
}

int genetics::getPopulation()
{
	return populationSize;
}

vector<itemGroup*> genetics::getGeneticExample()
{
	return geneticExample;
}

void genetics::setGeneticExample(vector<itemGroup*> geneticExample)
{
	this->geneticExample = geneticExample;
}

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

int genetics::calculateAverage()
{
	int temp = 0;
	int averageValue = 0;

	for (auto it : geneticExample)
	{
		averageValue += it->getSolutionFitness();
	}

	averageValue = averageValue / populationSize;


	return averageValue;
}


