#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <list>
#include <vector>
//#include "Map.h"

class City{
	private:
	std::string cityName;
	int xCoor;
	int yCoor;
	
	public:
	City* optimalPrev;
	unsigned int dist;
	bool visited;
	City(std::string cityName, int xCoor, int yCoor){
		this->cityName = cityName;
		this->xCoor = xCoor;
		this->yCoor = yCoor;
		this->visited = false;
		this-> dist = -1;
		this->optimalPrev = NULL;
	}
	
	std::list<City*> adjacencyList;
	void setAdjacent(City * adjacent);
	std::string getName();
	int getXCoor();
	int getYCoor();
	std::list<City*> getAdjacent();

	bool operator< (City &c){
		if(this->cityName < c.cityName){
			return true;
		}
		else{
			return false;		
		}
	}
};
#endif
