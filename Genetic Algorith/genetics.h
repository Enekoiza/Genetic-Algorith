#include <vector>
#include "itemGroup.h"
#include <time.h>


#ifndef GENETICS_H
#define GENETICS_H


using std::vector;


class genetics
{
private:
	vector<itemGroup *> geneticExample;
	int populationSize = 50;
	string dataFile = "data_file.csv";

public:

	genetics();

	~genetics();



	int getPopulation();

	vector<itemGroup*> getGeneticExample();

	void setGeneticExample(vector<itemGroup *> geneticExample);

	int calculateMin();
	int calculateMax();
	int calculateAverage();

};



#endif // !GENETICS_H
