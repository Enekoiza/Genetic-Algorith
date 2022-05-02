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
	item(string name, int weight, int value, int geneticValue);

	~item();

	void mutateGenetic();
	int* getGeneticValue();
	int* getValue();
	int* getWeight();
	string* getName();
};





#endif // !ITEM_H
