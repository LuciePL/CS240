#include "City.h"
using namespace std;

int City::getXCoor(){
	return xCoor;
}

int City::getYCoor(){
	return yCoor;
}

list<City*> City::getAdjacent(){
	return adjacencyList;
}

string City::getName(){
	return cityName;
}

void City::setAdjacent(City* adjacent){
	adjacencyList.push_back(adjacent);
}




