
#include "Menu.h"

#include <iostream>
#include <string>

Menu::Menu() :
sa(tsp)
{
}


Menu::~Menu()
{
}

void Menu::start()
{
	int choice;
	while (true)
	{
		std::cout << "1. Wczytaj macierz miast z pliku." << std::endl;
		std::cout << "2. Wprowadz macierz miast z klawiatury." << std::endl;
		std::cout << "3. Wyswietl macierz miast." << std::endl;
		std::cout << "4. Uruchom algorytm." << std::endl;
		std::cout << "5. Uruchom algorytm w trybie krok po kroku." << std::endl;
		std::cout << "0. Zakoncz program.";
		std::cout << std::endl << "Wybierz opcje: ";

		std::cin >> choice;

		std::cout << std::endl << std::endl;

		switch (choice)
		{
			case 1:
				readCitiesMatrixFromFile();
				break;
			case 2:
				readCitiesMatrixFromKeyboard();
				break;
			case 3:
				printCitiesMatrix();
				break;
			case 4:
				startAlgorithm();
				break;
			case 5:
				startAlgorithmStepByStep();
				break;
			case 0:
				return;
		}
	}
}

void Menu::readCitiesMatrixFromFile()
{
	std::cout << "Podaj sciezke do pliku z macierza miast:\n";
	std::string path;
	std::cin >> path;

	if (tsp.readCitiesDataFromFileToCitiesMatrix(path))
	{
		std::cout << "Pomyslne wczytano macierz miast.\n";
	}
	else
	{
		std::cout << "Nie powiodlo sie wczytywanie macierzy miast z pliku.\n";
	}
}

void Menu::printCitiesMatrix()
{
	std::cout << std::endl << std::endl << tsp.getMatrixToString() << std::endl;
}

void Menu::readCitiesMatrixFromKeyboard()
{
	std::cout << "Podaj ilosc miast:\n";
	std::string cities_count;
	std::cin >> cities_count;
	int cost;
	int matrix_size = atoi(cities_count.c_str());
	tsp.setCitiesCount(matrix_size);

	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			if (i != j)
			{
				std::cout << "Podaj wartosc sciezki z miasta " << i << " do miasta " << j << "\t";
				std::cin >> cost;
				tsp.setEdgeCost(cost, i, j);
			}
				
		}
	}
}

void Menu::startAlgorithm()
{
	sa.startAlgorithm();
	std::cout << std::endl << sa.getSolutionToString(sa.the_best_solution, sa.min_cost) << std::endl;
}


void Menu::startAlgorithmStepByStep()
{
	sa.startAlgorithmStepByStep();
}

