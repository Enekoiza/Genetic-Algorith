#include <string>


#ifndef ITEM_H
#define ITEM_H


using std::string;



class item
{
private:
	string name;
	int weight;
	int value;
	int geneticValue;

public:
	item() {};
	item(string name, int weight, int value, int geneticValue);

	~item() {};

};



#endif // !ITEM_H
