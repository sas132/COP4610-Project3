#ifndef DISKMANAGER
#define DISKMANAGER

#include "locations.hpp"
#include <iostream>
#include <string>

class DiskManager
{
private:
	//int startLocation;
	Location* firstLocation;
public:
	DiskManager();
	void MakeLocations();
};

#endif
