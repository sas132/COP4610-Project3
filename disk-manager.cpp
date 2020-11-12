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
	numCylinders = 1;

	MakeLocations();

	bool continuing = true;

	while(continuing) {
		std::cout << "\n\nPlease enter a choice: 1. FCFS    2. SSTF    3. QUIT\t";
		int choice;
		std::cin >> choice;

		switch(choice) {
		case 1:
			std::cout << "Running the FCFS algorithm now...\n\n";
			FCFS();
			break;
		case 2:
			std::cout << "Running the SSTF algorithm now...\n\n";
			SSTF();
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
			numCylinders++;
		}
		else
		{
			std::cerr << "ERROR: Invalid Input.\n";
		}
	}

	Location* temp = new Location(current);
	lastLoc->setNext(temp);
	numCylinders++;
}

void DiskManager::FCFS()
{
	Location* current = firstLocation;
	Location* next = current->getNext();
	int totalTravel = 0;

	std::cout << "The sequence of visits to the cylinders:\n";

	for(int i = 0; i < numCylinders - 1; i++)
	{
		int currentNum = current->getCylNum();
		int nextNum = next->getCylNum();

		if(currentNum < nextNum)
		{
			totalTravel += (nextNum - currentNum);
		}
		else if(currentNum > nextNum)
		{
			totalTravel += (currentNum - nextNum);
		}

		std::cout << "\t" << currentNum;

		current = next;
		next = next->getNext();

		if(next == nullptr)
		{
			i = numCylinders + 20;
		}
	}
	std::cout << "\t" << current->getCylNum();
	std::cout << "\nTotal cylinder travel for FCFS: " << totalTravel << "\n";
}

void DiskManager::SSTF()
{
	Location* current = firstLocation;
	Location* next = nullptr;
	int totalTravel = 0;
	Location* visited[numCylinders];
	int visits = 0;

	std::cout << "The sequence of visits to the cylinders:\n";

	for(int i = 0; i < numCylinders; i++)
	{
		visited[i] = nullptr;
	}

	int tempDistance = 1000;
	for(int j = 0; j < numCylinders -1; j++)
	{
		Location* temp = firstLocation;
		for(int k = 0; k < numCylinders; k++)
		{
			int tempCylNum = temp->getCylNum();
			int currentCylNum = current->getCylNum();
			bool works = true;

			if(tempCylNum < currentCylNum)
			{
				if(tempDistance < currentCylNum - tempCylNum)
				{
					for(int m = 0; m < numCylinders; m++)
					{
						if(temp == visited[k])
						{
							works = false;
						}
					}
				}
				else
				{
					works = false;
				}
			}
			else if(tempCylNum > currentCylNum)
			{
				if(tempDistance < tempCylNum - currentCylNum)
				{
					for(int m = 0; m < numCylinders; m++)
					{
						if(temp == visited[k])
						{
							works = false;
						}
					}
				}
				else
				{
					works = false;
				}
			}
			else
			{
				for(int m = 0; m < numCylinders; m++)
				{
					if(temp == visited[k])
					{
						works = false;
					}
				}
			}

			if(works)
			{
				next = temp;
				if(tempCylNum < currentCylNum)
				{
					tempDistance = currentCylNum - tempCylNum;
				}
				else if(tempCylNum > currentCylNum)
				{
					tempDistance = tempCylNum - currentCylNum;
				}
			}

			temp = temp->getNext();
		}
		totalTravel += tempDistance;
		tempDistance = 1000;
		std::cout << "\t" << current->getCylNum();
		visited[visits] = current;
		visits++;
		current = next;
	}

	std::cout << "\t" << current->getCylNum();
	std::cout << "\nTotal cylinder travel for SSTF: " << totalTravel;
}
