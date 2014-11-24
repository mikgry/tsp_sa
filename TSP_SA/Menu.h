#pragma once

#include "TravelingSalesmanProblem.h"
#include "SimulatedAnnealing.h"

class Menu
{
private:

	SimulatedAnnealing sa;
	TravelingSalesmanProblem tsp;
	void readCitiesMatrixFromKeyboard();
	void readCitiesMatrixFromFile();
	void printCitiesMatrix();
	void startAlgorithm();
	void startAlgorithmStepByStep();
	
public:
	
	Menu();
	~Menu();
	void start();
};

