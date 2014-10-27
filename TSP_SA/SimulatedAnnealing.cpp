
#include "SimulatedAnnealing.h"
#include <algorithm>
#include <iostream>
#include <ctime>

SimulatedAnnealing::SimulatedAnnealing(TravelingSalesmanProblem& t) :
tsp(t)
{
}


SimulatedAnnealing::~SimulatedAnnealing()
{
}

void SimulatedAnnealing::startAlgorithm()
{
	srand(time(NULL));
	
	int current_cost;
	int new_cost;
	std::vector <int> current_solution(generateRandomSolution());
	current_cost = countCost(current_solution);
	std::vector <int> new_solution;

	float current_temperature;
	float delta = 0;
	float temp_delta;

	for (int i = 1; i < std::pow(tsp.getCitiesCount(), 2); i++)
	{
		new_solution = generateRandomSolution();
		new_cost = countCost(new_solution);
		temp_delta = new_cost - current_cost;
		if (temp_delta > delta)
		{
			delta = temp_delta;
		}
		current_solution = new_solution;
		current_cost = new_cost;
	}
	current_temperature = delta;
	delta = 0.9999f;
	
	the_best_solution = generateRandomSolution();
	min_cost = countCost(the_best_solution);
	while (current_temperature > 0.5)
	{
		swapTwoRandomCities(new_solution);
		new_cost = countCost(new_solution);
		if (new_cost < current_cost)
		{
			current_solution = new_solution;
			current_cost = new_cost;
			if (new_cost < min_cost)
			{
				the_best_solution = new_solution;
				min_cost = new_cost;
			}
		}
		else
		{
			if (float(rand() % 101) / 100.0f < countProbability(current_cost, new_cost, current_temperature))
			{
				current_solution = new_solution;
				current_cost = new_cost;
			}
		}
		current_temperature *= delta;
		//std::cout << min_cost << std::endl;
	}
	
}

std::vector <int> SimulatedAnnealing::generateRandomSolution()
{
	std::vector <int> solution;
	for (int i = 0; i < tsp.getCitiesCount(); i++)
	{
		solution.push_back(i);
	}
	std::random_shuffle(solution.begin(), solution.end());
	return solution;
}

int SimulatedAnnealing::countCost(std::vector<int> path)
{
	int cost = 0;
	for (std::size_t i = 0; i < path.size() - 1; i++)
	{
		cost += tsp.getEdgeCost(path[i], path[i + 1]);
	}
	cost += tsp.getEdgeCost(path[path.size() - 2], path[0]);

	return cost;
}

void SimulatedAnnealing::swapTwoRandomCities(std::vector<int>& path)
{
	int firstPosition = rand() % path.size();
	int secondPosition = rand() % path.size();

	int buffor = path[firstPosition];
	path[firstPosition] = path[secondPosition];
	path[secondPosition] = buffor;
}

float SimulatedAnnealing::countProbability(int current_cost, int new_cost, float current_temperature)
{
	return std::powf(2.7182818f, -(float(new_cost - current_cost) / current_temperature));
}

std::string SimulatedAnnealing::getSolutionToString()
{
	std::string str = "";
	str.append("Koszt przejscia sciezki:\n");
	str.append(std::to_string(min_cost));
	str.append("\nSciezka:\n");
	for (std::size_t i = 0; i < the_best_solution.size(); i++)
	{
		str.append(std::to_string(the_best_solution[i]));
		str.append(" ");
	}
	str.append("\n");
	for (std::size_t i = 0; i < the_best_solution.size() - 1; i++)
	{
		str.append(std::to_string(tsp.getEdgeCost(the_best_solution[i], the_best_solution[i + 1])));
		str.append(" ");
	}
	str.append(std::to_string(tsp.getEdgeCost(the_best_solution[the_best_solution.size() - 2], the_best_solution[0])));
	return str;
}