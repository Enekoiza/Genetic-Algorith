#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>



using std::string;
using std::vector;
using std::ifstream;
using std::getline;
using std::stringstream;
using std::fstream;

// Header guards
#ifndef ITEM_H
#define ITEM_H


using std::string;



class item
{
private:
	string* name = NULL;															// A pointer that holds the name of the item
	int* weight = NULL;																// A pointer that holds the weight of the item
	int* value = NULL;																// A pointer that holds the value of the item
	int* geneticValue = NULL;														// A pointer that holds the genetic value of the item

public:
	item() {};																		// Default constructor
	item(string itemName, int itemWeight, int itemValue, int itemGeneticValue);		// Constructor

	~item();

	void mutateGenetic();															// Method to swap between 1 and 0 the geneticValue
	
	//Getters
	int* getGeneticValue();															// Method to return the genetic value
	int* getValue();																// Method to return the value of the item
	int* getWeight();																// Method to return the weight of the item
	string* getName();																// Method to return the name of the item
};





#endif // !ITEM_H
