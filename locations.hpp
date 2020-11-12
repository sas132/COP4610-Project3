#ifndef LOCATIONS
#define LOCATIONS

class Location
{
private:
	int cylinderNum;
	Location* nextLoc;
public:
	Location(int newNum);
	~Location();
	void setNext(Location* newLoc);
	Location* getNext();
	int getCylNum();
};

#endif
