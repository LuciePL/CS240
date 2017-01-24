#ifndef MAP_H
#define MAP_H
#include "City.h"
#include <iostream>
#include <vector>

class Map{
	private:
	std::vector<City *> cityList;

	public:
	Map(std::string filename);
	City* findByName(std::string cityName);
	std::vector<City *> shortestPath(City * start, City * dest);
	unsigned int pathDistance(City* start, City* dest);
};
#endif
