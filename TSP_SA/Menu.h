#pragma once

#include "TravelingSalesmanProblem.h"

class Menu
{
private:
	TravelingSalesmanProblem tsp;
	void readCitiesMatrixFromFile();
	void printCitiesMatrix();
public:
	Menu();
	~Menu();
	void start();
};

