#include "locations.hpp"

Location::Location(int newNum)
{
	cylinderNum = newNum;
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
