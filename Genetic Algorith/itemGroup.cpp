#include "itemGroup.h"

itemGroup::itemGroup(vector<item*> solution)
{
	this->solution = solution;
	
	int fitness = 0;
	int solutionWeight = 0;

	for (auto i : solution)
	{
		if (*i->getGeneticValue() == 1)
		{
			fitness += *i->getValue();
			solutionWeight += *i->getWeight();
		}
	}
	if (solutionWeight > 4000)
	{
		solutionFitness = 0;
	}
	else
	{
		solutionFitness = fitness;
	}

}

itemGroup::itemGroup(string fileName)
{

	fstream file;

	string itemName;
	int itemWeight;
	int itemValue;

	int title = 0;

	string token;

	file.open(fileName, std::ios::in);

	if (file.is_open()) {
		string line;



		while (getline(file, line))
		{
			if (title == 0)
			{
				title = 1;
				continue;
			}

			std::istringstream ss(line);

			

			getline(ss, token, ',');
			itemName = token;
			getline(ss, token, ',');
			itemWeight = std::stoi(token);
			getline(ss, token, ',');
			itemValue = std::stoi(token);
			

			solution.push_back(new item(itemName, itemWeight, itemValue, rand() % 2));
		}

		file.close();
	}

	int fitness = 0;
	int solutionWeight = 0;

	for (auto i : solution)
	{
		if(*i->getGeneticValue() == 1)
		{
			fitness += *i->getValue();
			solutionWeight += *i->getWeight();
		}
	}
	if (solutionWeight > 4000)
	{
		solutionFitness = 0;
	}
	else
	{
		solutionFitness = fitness;
	}
}

itemGroup::~itemGroup()
{
	for (int j = solution.size() - 1; j >= 0; j--)
	{
		if(solution[j] != NULL)
		{
			delete solution[j];
		}
	}
}

vector<item*> itemGroup::getGroup()
{
	return solution;
}



int itemGroup::getTotalValue()
{
	int total = 0;



	for (auto i : solution)
	{

		if (*i->getGeneticValue() == 1)
		{
			total += *i->getValue();
		}

	}

	return total;
}

int itemGroup::getTotalWeight()
{
	int total = 0;


	for (auto i : solution)
	{


		if (*i->getGeneticValue() == 1)
		{
			total += *i->getWeight();
		}

	}

	return total;
}

int itemGroup::getSolutionFitness()
{
	return solutionFitness;
}

int itemGroup::getSolutionLenght()
{
	return solutionLenght;
}

