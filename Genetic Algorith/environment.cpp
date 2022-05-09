#include "environment.h"


// Constructor
environment::environment()
{

	// seed for random generation
	srand(time(NULL));



	generationsNumber = new int;
	selectionMethod = new string;
	tournamentSize = new int;
	crossoverMethod = new string;
	crossoverTreshold = new float;
	mutationTreshold = new float;
	dataFile = new string;
	populationSize = new int;

	*generationsNumber = 300;
	*selectionMethod = "Tournament";
	*tournamentSize = 4;
	*crossoverMethod = "One-Point";
	*crossoverTreshold = 0.7;
	*mutationTreshold = 0.2;
	*dataFile = "data_file.csv";
	*populationSize = 50;

}

// Destructor
environment::~environment()
{
	if (generationsNumber != NULL) delete generationsNumber;
	if (selectionMethod != NULL) delete selectionMethod;
	if (tournamentSize != NULL) delete tournamentSize;
	if (crossoverMethod != NULL) delete crossoverMethod;
	if (crossoverTreshold != NULL) delete crossoverTreshold;
	if (mutationTreshold != NULL) delete mutationTreshold;
	if (dataFile != NULL) delete dataFile;
	if (populationSize != NULL) delete populationSize;

}

// Method to run the genetic algorithm where the selection method is tournament
void environment::run()
{
	// File where the data generated will be saved.
	string filename = "";

	if (*crossoverMethod == "One-Point") filename="run.csv";
	else if(*crossoverMethod == "Two-Point") filename="run2.csv";
	





	// Output stream to write in the file
	fstream output_fstream;


	output_fstream.open(filename, std::ios::ios_base::out);


	if (!output_fstream.is_open())
	{
		std::cerr << "Failed to open " << filename << '\n';	 // std:cerr is used to output errors
		std::cerr << "The most common problems are that the file is open, or the folder has no writting permissions." << std::endl;
		return;
	}


	// New instance fo genetics
	genetics* simulation = new genetics(*dataFile, *populationSize);


	// A vector that holds the genetics example
	vector<itemGroup*> tempItemList;
	tempItemList = simulation->getGeneticExample();

	// Get the population
	int population = simulation->getPopulation();


	// Get the solution lenght
	int solutionLenght = tempItemList[0]->getSolutionLenght();

	// A map to store the index of the selected participant (key) and the solution fitness (value)
	std::map<int, int> tournamentParticipants;

	// 2 vectors to hold the index of the winners and losers
	vector<int> tournamentWinners;
	vector<int> tournamentLosers;

	// Variables to hold the fitness values that will be printed into the file
	int minimumFitness, averageFitness, maximumFitness;

	// A flag to control that there is no collision between the winners
	int equalityFlag = 0;

	// An iterator to move through the map
	std::map<int, int>::iterator it;



	//Loop as many times as the generation number states
	for(int q = 0; q < *generationsNumber; q++)
	{
		// All the fitness values must be set to 0 before starting a new loop
		minimumFitness = 0;
		averageFitness = 0;
		maximumFitness = 0;

		equalityFlag = 0;
		
		// If the values are equals keep looping looking to the case where the participants are different
		while (equalityFlag == 0) 
		{
			for (int f = 0; f < 2; f++)
			{
				//Get 4 randomly selected participants
				for (int y = 0; y < *tournamentSize; y++)
				{
					int index = rand() % population;
					int solutionfitness = tempItemList[index]->getSolutionFitness();
					tournamentParticipants.insert({ index, solutionfitness });
				}

				int maxValue = 0;
				int keyValue = 0;

				//Get the winner (biggest solution value) between the 4 participants
				for (it = tournamentParticipants.begin(); it != tournamentParticipants.end(); it++)
				{
					if (it->second > maxValue)
					{
						keyValue = it->first;
						maxValue = it->second;
					}
				}
				//Store the winners index
				tournamentWinners.push_back(keyValue);
				tournamentParticipants.clear();

			}
			// If the winners are different get out of the loop
			if (tournamentWinners[0] != tournamentWinners[1])
			{
				equalityFlag = 1;
			}
			else
			{
				tournamentWinners.clear();
			}
		}

		// Calculate the crossover treshold over a 100%
		int crossoverPercentage = *crossoverTreshold * 100;

		// Generate a random number between 0 and 100. This values will be the chance of doing crossover or not
		int randomCrossover = rand() % 101;

		// Crossover participants
		vector<item*> participant1;
		vector<item*> participant2;

		// Get the solution of the winners index
		participant1 = tempItemList[tournamentWinners[0]]->getSolution();
		participant2 = tempItemList[tournamentWinners[1]]->getSolution();

		vector<item*> temp1;
		vector<item*> temp2;
		// Vector that will lead with the crossover and mutation
		vector<vector<item*>> thresholdParticipants{temp1, temp2};

		if (randomCrossover <= crossoverPercentage)
		{
			if (*crossoverMethod == "One-Point")
			{
				// The case where a crossover will be performed
				if (randomCrossover <= crossoverPercentage)
				{
					// An index where the crossover will be performed
					int crossoverIndex = solutionLenght - 1;

					// Make sure that the crossover are not the first and last index
					while ((crossoverIndex == 0) || (crossoverIndex == (solutionLenght - 1)))
					{
						crossoverIndex = rand() % solutionLenght;
					}


					// Push to the temp vector from the index 0 to the generated index for crossover
					for (int o = 0; o < crossoverIndex; o++)
					{

						thresholdParticipants[0].push_back(new item(*(participant1[o]->getName()), *(participant1[o]->getWeight()), *(participant1[o]->getValue()), *(participant1[o]->getGeneticValue())));
						thresholdParticipants[1].push_back(new item(*(participant2[o]->getName()), *(participant2[o]->getWeight()), *(participant2[o]->getValue()), *(participant2[o]->getGeneticValue())));

					}

					// Push to the temp vector from the index generated for crossover until the end of the solution lenght BUT INVERTED 
					for (int u = crossoverIndex; u < solutionLenght; u++)
					{
						thresholdParticipants[1].push_back(new item(*(participant2[u]->getName()), *(participant2[u]->getWeight()), *(participant2[u]->getValue()), *(participant2[u]->getGeneticValue())));
						thresholdParticipants[0].push_back(new item(*(participant1[u]->getName()), *(participant1[u]->getWeight()), *(participant1[u]->getValue()), *(participant1[u]->getGeneticValue())));

					}

				}
			}
			// Crossover to perform the two point
			else if (*crossoverMethod == "Two-Point")
			{

				

				vector<int*> crossoverIndex = { new int, new int };
				*crossoverIndex[0] = solutionLenght - 1;
				*crossoverIndex[1] = solutionLenght - 1;



				while ((*crossoverIndex[0] == 0) || (*crossoverIndex[0] == (solutionLenght - 1)))
				{
					*crossoverIndex[0] = rand() % solutionLenght;
				}
				while ((*crossoverIndex[1] == 0) || (*crossoverIndex[1] == (solutionLenght - 1)))
				{
					*crossoverIndex[1] = rand() % solutionLenght;
				}

				int max = 0, min = 0;

				if (*crossoverIndex[0] > *crossoverIndex[1])
				{
					max = *crossoverIndex[0];
					min = *crossoverIndex[1];
				}
				else
				{
					min = *crossoverIndex[0];
					max = *crossoverIndex[1];
				}

				for (int o = 0; o < min; o++)
				{
					thresholdParticipants[0].push_back(new item(*(participant1[o]->getName()), *(participant1[o]->getWeight()), *(participant1[o]->getValue()), *(participant1[o]->getGeneticValue())));
					thresholdParticipants[1].push_back(new item(*(participant2[o]->getName()), *(participant2[o]->getWeight()), *(participant2[o]->getValue()), *(participant2[o]->getGeneticValue())));
				}

				for (int j = min; j < max; j++)
				{
					thresholdParticipants[1].push_back(new item(*(participant1[j]->getName()), *(participant1[j]->getWeight()), *(participant1[j]->getValue()), *(participant1[j]->getGeneticValue())));
					thresholdParticipants[0].push_back(new item(*(participant2[j]->getName()), *(participant2[j]->getWeight()), *(participant2[j]->getValue()), *(participant2[j]->getGeneticValue())));

				}

				for (int x = max; x < solutionLenght; x++)
				{
					thresholdParticipants[0].push_back(new item(*(participant1[x]->getName()), *(participant1[x]->getWeight()), *(participant1[x]->getValue()), *(participant1[x]->getGeneticValue())));
					thresholdParticipants[1].push_back(new item(*(participant2[x]->getName()), *(participant2[x]->getWeight()), *(participant2[x]->getValue()), *(participant2[x]->getGeneticValue())));
				}

			}

		}
		// The case where the crossover is not performed and they keep the same as they were
		else
		{

			for (int l = 0; l < solutionLenght; l++)
			{
				thresholdParticipants[1].push_back(new item(*(participant1[l]->getName()), *(participant1[l]->getWeight()), *(participant1[l]->getValue()), *(participant1[l]->getGeneticValue())));
				thresholdParticipants[0].push_back(new item(*(participant2[l]->getName()), *(participant2[l]->getWeight()), *(participant2[l]->getValue()), *(participant2[l]->getGeneticValue())));

			}
		}



		// Calculate the mutation treshold over a 100%
		int mutationPercentage = *mutationTreshold * 100;

		int mutationAttempt = 0;

		// Iterate through the participants' items
		for (int r = 0; r < thresholdParticipants.size(); r++)
		{
			// Iterate through the solution of a participant
			for (int x = 0; x < solutionLenght; x++)
			{

				mutationAttempt = rand() % 101;

				// If the mutation must be performed call the item method to mutate its genetic Value
				if (mutationAttempt <= 2)
				{
					thresholdParticipants[r][x]->mutateGenetic();
				}

			}

		}


		equalityFlag = 0;

		// Make sure that not the same looser is being picked
		while (equalityFlag == 0)
		{
			for (int f = 0; f < 2; f++)
			{
				//Get 4 participants
				for (int y = 0; y < *tournamentSize; y++)
				{
					int index = rand() % population;
					int solutionfitness = tempItemList[index]->getSolutionFitness();
					tournamentParticipants.insert({ index, solutionfitness });
				}

				// Create an enormous value that it is sure that will never match the total value of a solution
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

		// Delete the unused pointers
		delete tempItemList[tournamentLosers[0]];
		delete tempItemList[tournamentLosers[1]];

		itemGroup* Holder1 = new itemGroup(thresholdParticipants[0]);
		itemGroup* Holder2 = new itemGroup(thresholdParticipants[1]);


		// Replace the losers' position with the children offsprings
		tempItemList[tournamentLosers[0]] = Holder1;
		tempItemList[tournamentLosers[1]] = Holder2;

		//Clear all the vector because a new iteration is coming
		thresholdParticipants.clear();
		tournamentLosers.clear();
		tournamentWinners.clear();
		tournamentParticipants.clear();
		
		
		simulation->setGeneticExample(tempItemList);

		// Calculate the file values
		minimumFitness = simulation->calculateMin();
		averageFitness = simulation->calculateAverage();
		maximumFitness = simulation->calculateMax();


		output_fstream << minimumFitness << "," << averageFitness << "," << maximumFitness << std::endl;


	}

	// Inform the user that the file is correctly created.
	std::cout << "File " << filename << " successfully created." << std::endl;
	
	output_fstream.close();
	delete simulation;
}
