
#include "Menu.h"

#include <iostream>
#include <string>

Menu::Menu()
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
		std::cout << "2. Wyswietl macierz miast." << std::endl;
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
				printCitiesMatrix();
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