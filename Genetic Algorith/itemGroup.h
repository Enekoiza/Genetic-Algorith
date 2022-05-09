#include "item.h"



// Header guards
#ifndef ITEMGROUP_H
#define ITEMGROUP_H



//This class will hold the group of items or as called solution
class itemGroup
{
private:
	vector<item*> solution;						// Vector to hold all the items
	int* solutionFitness = NULL;				// Solution fitness that will start at 0 and will be recalculated in the constructor
	int* solutionLenght = NULL;					// Specification requires a solution lenght of 25

public:
	itemGroup() {};								//Defual constructor
	
	itemGroup(vector<item*> list);				// Constructor that will be used to generate new itemGroup while running the environment.run()

	itemGroup(string fileName);					// Constructor that will be used while creating the item group from the given .csv file

	~itemGroup();								// Destructor to get rid of all the pointer that are inside the solution


	vector<item *> getSolution();				// A funtion that returns the solution vector


	int getTotalValue();						// A function that will return the summatory value of all the items which have the geneticValue = 1
	int getTotalWeight();						// A function that will return the summatory weight of all the items which have the geneticValue = 1
	int getSolutionFitness();					// A funtion to return the solution fitness
	int getSolutionLenght();					// A function that returns the solution lenght

};




#endif // !ITEMGROUP_H
