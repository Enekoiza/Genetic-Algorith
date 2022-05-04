#include "item.h"

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

item::~item()
{
	if (name != NULL) delete name;
	if (weight != NULL) delete weight;
	if (value != NULL) delete value;
	if (geneticValue != NULL) delete geneticValue;
}

void item::mutateGenetic()
{
	*geneticValue == 1 ? *geneticValue = 0 : *geneticValue = 1;
}

int* item::getGeneticValue()
{
	return geneticValue;
}

int* item::getValue()
{
	return value;
}

int* item::getWeight()
{
	return weight;
}

string* item::getName()
{
	return name;
}

void item::setValue(int itemValue)
{
	*value = itemValue;
}

void item::setWeight(int itemWeight)
{
	*weight = itemWeight;
}

void item::setName(string itemName)
{
	*name = itemName;
}





