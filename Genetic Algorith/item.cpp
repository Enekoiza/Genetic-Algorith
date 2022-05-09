#include "item.h"


//Constructor to create an item with the desired data values
item::item(string itemName, int itemWeight, int itemValue, int itemGeneticValue)
{
	
	name = new string;
	weight = new int;
	value = new int;
	geneticValue = new int;


	*name = itemName;
	*weight = itemWeight;
	*value = itemValue;
	*geneticValue = itemGeneticValue;

}


//Destructor to get rid of the generated pointer if they exist
item::~item()
{
	if (name != NULL) delete name;
	if (weight != NULL) delete weight;
	if (value != NULL) delete value;
	if (geneticValue != NULL) delete geneticValue;
}


//Swap the value of the genetic value when a mutate is called
void item::mutateGenetic()
{
	*geneticValue == 1 ? *geneticValue = 0 : *geneticValue = 1;
}


//return the genetic value
int* item::getGeneticValue()
{
	return geneticValue;
}

//return the value
int* item::getValue()
{
	return value;
}

//return the weight
int* item::getWeight()
{
	return weight;
}


//return the name
string* item::getName()
{
	return name;
}





