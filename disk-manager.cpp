#include "disk-manager.hpp"
#include "locations.hpp"
#include <iostream>
#include <string>

DiskManager::DiskManager()
{
	int startLocation;

	std::cout << "Please enter the current location of the arm: ";
	std::cin >> startLocation;
	
	Location* first = new Location(startLocation);
	firstLocation = first;

	MakeLocations();
}

void DiskManager::MakeLocations()
{
	std::string str;
	std::cout << "Please enter the list of the cylinder numbers for the file: ";
	std::getline(std::cin, str);
	int current = 0;

	std::cout << "\n\n" << firstLocation->getCylNum();
}
