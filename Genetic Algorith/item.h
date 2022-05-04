#include <string>


#ifndef ITEM_H
#define ITEM_H


using std::string;



class item
{
private:
	string* name = NULL;
	int* weight = NULL;
	int* value = NULL;
	int* geneticValue = NULL;

public:
	item() {};
	item(string itemName, int itemWeight, int itemValue, int itemGeneticValue);

	~item();

	void mutateGenetic();
	int* getGeneticValue();
	int* getValue();
	int* getWeight();
	string* getName();
	void setValue(int itemValue);
	void setWeight(int itemWeight);
	void setName(string itemName);
};





#endif // !ITEM_H
