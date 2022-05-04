#include <vector>
#include "item.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>



#ifndef ITEMGROUP_H
#define ITEMGROUP_H


using std::string;
using std::vector;
using std::ifstream;
using std::getline;
using std::stringstream;
using std::fstream;

class itemGroup
{
private:
	vector<item*> solution;
	int solutionFitness;
	int solutionLenght = 25;

public:
	itemGroup() {};
	
	itemGroup(vector<item*> list);

	itemGroup(string fileName);

	~itemGroup();


	vector<item *> getGroup();


	int getTotalValue();
	int getTotalWeight();
	int getSolutionFitness();
	int getSolutionLenght();

};














#endif // !ITEMGROUP_H
