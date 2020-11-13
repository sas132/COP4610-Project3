//Sarah Stevenson
//COP4610
//Project 3

#include "locations.hpp"

Location::Location(int newNum)
{
	cylinderNum = newNum;
	nextLoc = nullptr;
}

Location::~Location()
{

}

void Location::setNext(Location* newLoc)
{
	nextLoc = newLoc;
}

Location* Location::getNext()
{
	return nextLoc;
}

int Location::getCylNum()
{
	return cylinderNum;
}
