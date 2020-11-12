#include "disk-manager.hpp"
#include "locations.hpp"
#include <iostream>
#include <string>

DiskManager::DiskManager()
{
	int startLocation = 0;

	std::cout << "Please enter the current location of the arm: ";
	
	std::string str;
	std::getline(std::cin, str);

	for(int i = 0; i < str.size(); i++)
	{
		startLocation = (startLocation * 10) + ((int)str.at(i) - 48);
	}
	
	Location* first = new Location(startLocation);
	firstLocation = first;

	MakeLocations();

	bool continuing = true;

	while(continuing) {
		std::cout << "\n\nPlease enter a choice: 1. FCFS\t2. SSTF\t3. QUIT\t";
		int choice;
		std::cin >> choice;

		switch(choice) {
		case 1:
			std::cout << "Running the FCFS algorithm now...\n\n";
			break;
		case 2:
			std::cout << "Running the SSTF algorithm now...\n\n";
			break;
		case 3:
			std::cout << "Ending the program now...";
			continuing = false;
			break;
		}
	}
}

void DiskManager::MakeLocations()
{
	std::string str;
	std::cout << "Please enter the list of the cylinder numbers for the file: ";
	std::getline(std::cin, str);
	int current = 0;
	Location* lastLoc = new Location(-1);

	for(int i = 0; i < str.size(); i++)
	{
		if(isdigit(str.at(i)))
		{
			current = (current * 10) + ((int)str.at(i) - 48);
		}
		else if(str.at(i) == ' ')
		{
			if(lastLoc->getCylNum() == -1)
			{
				Location* temp = new Location(current);
				firstLocation->setNext(temp);
				delete lastLoc;
				lastLoc = temp;
			}
			else
			{
				Location* temp = new Location(current);
				lastLoc->setNext(temp);
				lastLoc = temp;
			}
			current = 0;
		}
		else
		{
			std::cerr << "ERROR: Invalid Input.\n";
		}
	}

	Location* temp = new Location(current);
	lastLoc->setNext(temp);
}
