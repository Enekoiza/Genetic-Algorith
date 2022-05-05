#include "environment.h"
#include <map>

void environment::run()
{

	string filename("test.txt");

	fstream output_fstream;


	output_fstream.open(filename, std::ios::ios_base::out);

	if (!output_fstream.is_open())
	{
		std::cerr << "Failed to open " << filename << '\n';
	}

	 
	genetics* simulation = new genetics;

	vector<itemGroup*> tempItemList;
	tempItemList = simulation->getGeneticExample();

	int population = simulation->getPopulation();

	int solutionLenght = tempItemList[0]->getSolutionLenght();


	std::map<int, int> tournamentParticipants;

	vector<int> tournamentWinners;
	vector<int> tournamentLosers;

	int minimumFitness, averageFitness, maximumFitness;

	int equalityFlag = 0;

	std::map<int, int>::iterator it;
	int roundCounter = -1;

	for(int q = 0; q < generationsNumber; q++)
	{
		minimumFitness = 0;
		averageFitness = 0;
		maximumFitness = 0;

		roundCounter++;
		equalityFlag = 0;
		while (equalityFlag == 0)
		{
			for (int f = 0; f < 2; f++)
			{
				//Get 4 participants
				for (int y = 0; y < tournamentSize; y++)
				{
					int index = rand() % population;
					int solutionfitness = tempItemList[index]->getSolutionFitness();
					tournamentParticipants.insert({ index, solutionfitness });
				}

				int maxValue = 0;
				int keyValue = 0;

				//Get the winner between the 4 participants
				for (it = tournamentParticipants.begin(); it != tournamentParticipants.end(); it++)
				{
					if (it->second > maxValue)
					{
						keyValue = it->first;
						maxValue = it->second;
					}
				}
				//Store the losers index
				tournamentWinners.push_back(keyValue);
				tournamentParticipants.clear();

			}
			if (tournamentWinners[0] != tournamentWinners[1])
			{
				equalityFlag = 1;
			}
			else
			{
				tournamentWinners.clear();
			}
		}

		//Crossover treshold
		int crossoverPercentage = crossoverTreshold * 100;

		int randomCrossover = rand() % 101;

		vector<item*> participant1;
		vector<item*> participant2;

		participant1 = tempItemList[tournamentWinners[0]]->getGroup();
		participant2 = tempItemList[tournamentWinners[1]]->getGroup();

		vector<vector<item*>> thresholdParticipants;
		vector<item*> temp1;
		vector<item*> temp2;

		thresholdParticipants.push_back(temp1);
		thresholdParticipants.push_back(temp2);

		if (randomCrossover <= crossoverPercentage)
		{

			int crossoverIndex = solutionLenght - 1;

			while ((crossoverIndex == 0) || (crossoverIndex == (solutionLenght - 1)))
			{
				crossoverIndex = rand() % solutionLenght;
			}



			for (int o = 0; o < crossoverIndex; o++)
			{

				thresholdParticipants[0].push_back(new item(*(participant1[o]->getName()), *(participant1[o]->getWeight()), *(participant1[o]->getValue()), *(participant1[o]->getGeneticValue())));
				thresholdParticipants[1].push_back(new item(*(participant2[o]->getName()), *(participant2[o]->getWeight()), *(participant2[o]->getValue()), *(participant2[o]->getGeneticValue())));

			}


			for (int u = crossoverIndex; u < tempItemList[0]->getSolutionLenght(); u++)
			{
				thresholdParticipants[1].push_back(new item(*(participant2[u]->getName()), *(participant2[u]->getWeight()), *(participant2[u]->getValue()), *(participant2[u]->getGeneticValue())));
				thresholdParticipants[0].push_back(new item(*(participant1[u]->getName()), *(participant1[u]->getWeight()), *(participant1[u]->getValue()), *(participant1[u]->getGeneticValue())));

			}

		}
		else
		{

			for (int l = 0; l < tempItemList[0]->getSolutionLenght(); l++)
			{
				thresholdParticipants[0].push_back(new item(*(participant1[l]->getName()), *(participant1[l]->getWeight()), *(participant1[l]->getValue()), *(participant1[l]->getGeneticValue())));
				thresholdParticipants[1].push_back(new item(*(participant2[l]->getName()), *(participant2[l]->getWeight()), *(participant2[l]->getValue()), *(participant2[l]->getGeneticValue())));

			}
		}

		int mutationPercentage = mutationTreshold * 100;

		int mutationAttempt = 0;


		for (int r = 0; r < thresholdParticipants.size(); r++)
		{

			for (int x = 0; x < solutionLenght; x++)
			{

				mutationAttempt = rand() % 101;

				if (mutationAttempt <= 2)
				{
					thresholdParticipants[r][x]->mutateGenetic();
				}

			}

		}

		equalityFlag = 0;
		while (equalityFlag == 0)
		{
			for (int f = 0; f < 2; f++)
			{
				//Get 4 participants
				for (int y = 0; y < tournamentSize; y++)
				{
					int index = rand() % population;
					int solutionfitness = tempItemList[index]->getSolutionFitness();
					tournamentParticipants.insert({ index, solutionfitness });
				}

				int minValue = 10000 * 10000;
				int keyValue = 0;

				//Get the loser between the 4 participants
				for (it = tournamentParticipants.begin(); it != tournamentParticipants.end(); it++)
				{
					if (it->second == 0)
					{
						keyValue = it->first;
						minValue = it->second;
						break;
					}
					else if (it->second < minValue)
					{
						keyValue = it->first;
						minValue = it->second;
					}
				}
				//Store the losers index
				tournamentLosers.push_back(keyValue);
				tournamentParticipants.clear();
			}
			if (tournamentLosers[0] != tournamentLosers[1])
			{
				equalityFlag = 1;
			}
			else
			{
				tournamentLosers.clear();
			}
		}

		delete tempItemList[tournamentLosers[0]];
		delete tempItemList[tournamentLosers[1]];

		itemGroup* Holder1 = new itemGroup(thresholdParticipants[0]);
		itemGroup* Holder2 = new itemGroup(thresholdParticipants[1]);



		tempItemList[tournamentLosers[0]] = Holder1;
		tempItemList[tournamentLosers[1]] = Holder2;

		thresholdParticipants.clear();
		tournamentLosers.clear();
		tournamentWinners.clear();
		tournamentParticipants.clear();
		
		
		simulation->setGeneticExample(tempItemList);

		minimumFitness = simulation->calculateMin();
		averageFitness = simulation->calculateAverage();
		maximumFitness = simulation->calculateMax();

		output_fstream << minimumFitness << "," << averageFitness << "," << maximumFitness << std::endl;


	}
	output_fstream.close();
}
