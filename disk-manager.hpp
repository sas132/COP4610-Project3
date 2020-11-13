//Sarah Stevenson
//COP4610
//Project 3

#ifndef DISKMANAGER
#define DISKMANAGER

#include "locations.hpp"
#include <iostream>
#include <string>

class DiskManager
{
private:
	int numCylinders;
	Location* firstLocation;
	void FCFS();
	void SSTF();
public:
	DiskManager();
	void MakeLocations();
};

#endif
