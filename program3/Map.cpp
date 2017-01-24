#include "City.h"

#include "Map.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

Map::Map(std::string filename){
	fstream cities;
	string name;
	string line;
	int toggle;
	int x;
	int y;
	cities.open(filename);
	while(getline(cities, line)){
		istringstream city(line);
		city>>name>>x>>y;
		City* city1 = new City(name,x,y);
		cityList.push_back(city1);
	}
	for(auto currCity : cityList){
		vector<City *> north;
		vector<City *> south;
		vector<City *> east;
		vector<City *> west;
		for(auto i: cityList){
			if(i->getXCoor() ==  currCity->getXCoor()){
				if(i->getYCoor() > currCity->getYCoor()){
					north.push_back(i);
				}
				else if(i->getYCoor() < currCity->getYCoor()){
					south.push_back(i);
				}
			}
			else if(i->getYCoor() == currCity->getYCoor()){
				if(i->getXCoor() > currCity->getXCoor()){
					east.push_back(i);
				}
				else if(i->getXCoor() < currCity ->getXCoor()){
					west.push_back(i);
				}
			}
		}

		if(!west.empty()){
			City* closestW = west.front();
			for(auto i: west){
				if(closestW->getXCoor()< i->getXCoor()){
					closestW = i;
				}
			}
			currCity->setAdjacent(closestW);
		}

		if(!north.empty()){
			City* closestN = north.front();
			for(auto i: north){
				if(closestN->getYCoor()> i->getYCoor()){
                                        closestN = i;
                    }
			}
			currCity->setAdjacent(closestN);
		}
		if(!east.empty()){
			City* closestE = east.front();
			for(auto i: east){
				if(closestE->getXCoor()> i->getXCoor()){
	                    closestE = i;
                    }
               }
			currCity->setAdjacent(closestE);
		}
		if(!south.empty()){
			City* closestS = south.front();
			for(auto i: south){
				if(closestS->getYCoor()< i->getYCoor()){
                    	closestS = i;
                    }
             	}
			currCity->setAdjacent(closestS);
		}	
	}
}

City* Map::findByName(string cityName){
	for(auto i : cityList){
		if(i->getName() == cityName){
			return i;
		}
	}
	return 0;
}

unsigned int Map::pathDistance(City* start, City* dest){
	unsigned int path;
	City* currCity = start;
	for(auto b : cityList){
			b->dist = -1;
			b->optimalPrev = NULL;
			b->visited = false;
	}
  	currCity->dist = 0;
	while(!currCity->visited){
		currCity->visited = true;
		list<City *> cList = currCity->getAdjacent();
		vector<City *> adjCities;
		for(auto a = cList.begin(); a != cList.end(); ++a){
			adjCities.push_back((*a));
		}
		for(auto i : adjCities){
			int actualDist = 0;
			if(i->getXCoor() == currCity->getXCoor()){
				actualDist = i->getYCoor() - currCity->getYCoor();
				actualDist = abs(actualDist);
				if(i->dist > currCity->dist + actualDist){
					i-> dist = currCity->dist + actualDist;
					i->optimalPrev = currCity;
				}
			}
			else{
				actualDist = i->getXCoor() - currCity->getXCoor();
				actualDist = abs(actualDist);
				if(i->dist > currCity->dist + actualDist){
					i->dist = currCity->dist + actualDist;
					i->optimalPrev = currCity;
				}

			}
		}
		unsigned int smallest = -1;
		City* temp = NULL;
		for(auto i : cityList){
			if(i == dest && i->visited == true){
				path = i->dist;
				return path;
			}
			else if(!i->visited){
				if(i->dist < smallest){
					smallest = i->dist;
					temp = i;
				}
			}
		}
		if(smallest == -1){
			return -1;
		}
		currCity = temp;
	}
}

vector<City *> Map::shortestPath(City * start, City * dest){
	vector<City *> shortest;
	City* currCity = start;
	for(auto b : cityList){
		b->dist = -1;
		b->optimalPrev = NULL;
		b->visited = false;
	}
	currCity->dist = 0;
	while(!currCity->visited){
		currCity->visited = true;
		list<City *> cList = currCity->getAdjacent();
		vector<City *> adjCities;
		for(auto a = cList.begin(); a != cList.end(); ++a){
			adjCities.push_back((*a));
		}
		int num =0;
		for(auto i : adjCities){
			int actualDist;
			if(i->getXCoor() == currCity->getXCoor()){
				actualDist = i->getYCoor() - currCity->getYCoor();
				actualDist = abs(actualDist);
				if(i->dist > currCity->dist + actualDist){
					i-> dist = currCity->dist + actualDist;
					i->optimalPrev = currCity;
				}
			}
			else{
				actualDist = i->getXCoor() - currCity->getXCoor();
				actualDist = abs(actualDist);
				if(i->dist > currCity->dist + actualDist){
					i->dist = currCity->dist + actualDist;
					i->optimalPrev = currCity;
				}

			}
			num++;
		}
		unsigned int smallest = -1;
		City* temp = NULL;
		for(auto i : cityList){
			if(i == dest && i->visited == true){
				City* a = i;
				while(a){
					shortest.push_back(a);
					a = a->optimalPrev;
				}
				reverse(shortest.begin(),shortest.end());
	        		return shortest;
                        }
			else if(!i->visited){
				if(i->dist < smallest){
					smallest = i->dist;
					temp = i;
				}
			}
                }
		if(smallest == -1){
			return shortest;
		}
		currCity = temp;
	}

}
