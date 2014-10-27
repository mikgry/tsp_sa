#include "Menu.h"
#include "SimulatedAnnealing.h"
#include <iostream>

void main()
{
	//Menu menu;
	//menu.start();
	TravelingSalesmanProblem tsp;
	SimulatedAnnealing sa(tsp);
	tsp.readCitiesDataFromFileToCitiesMatrix("br17.atsp");
	sa.startAlgorithm();
	std::cout << tsp.getMatrixToString() << std::endl << std::endl << sa.getSolutionToString();
	getchar();
}