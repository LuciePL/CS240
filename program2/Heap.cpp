#include <iostream>
#include "Heap.h"
#include <fstream>
#include <vector>
#include "Player.h"
using namespace std;

Heap::Heap(string filename){
	fstream players;
	string line;
	string name;
	int budget;
	bool toggle = true;
	players.open(filename);
	while(getline(players,line)){
		if(toggle){
			name = line;
			toggle = false;
		}
		else{
			budget = atoi(line.c_str());
			addPlayer(Player(name,budget));
			toggle= true;
			//std::cout<< "yo";
		}
	}
	for(auto i : playerList ){
		cout << i.getBudget() << ' ';
	}
	cout << endl;
	
}

void Heap::heapify(){
	for(int i = (playerList.size()-2)/2; i >= 0; --i){
		siftdown(i);
	}
}

void Heap::siftdown(int i){
	if(i>= playerList.size() || i<0){
		return;
	}
	else{
		while(!isLeaf(i)){
			int max = (2*i)+1;
			if(max+1 < playerList.size() && playerList[max].getBudget() < playerList[max+1].getBudget()){
				max = max++;
			}
			if(playerList[max].getBudget() < playerList[i].getBudget()){
				return;
			}
			swap(max, i);
			i = max;
		}
		
	}
}

void Heap::swap(int player1, int player2){
	Player temp = playerList[player1];
	playerList[player1] = playerList[player2];
	playerList[player2] = temp;
}

bool Heap::isLeaf(int i){
			if((2*i)+1 >= playerList.size()){
				return true;
			}
			else{
				return false;
			}
	return false;
}


void Heap::addPlayer(Player newPlayer){
	playerList.push_back(newPlayer);
	heapify();
	
}

Heap::Heap(const Heap &copy){
	
	
}

vector<Player> Heap::getArray(){
/*for(auto i : playerList ){
		cout << i.getName() << ' ';
	}
	cout << endl;*/
	return playerList;
}

Player Heap::getPlayer(){
	Player p = playerList.front();
	playerList.erase(playerList.begin());
	heapify();
	return p;
	
}

unsigned int Heap::size(){
	return playerList.size();
	
}

bool Heap::empty(){
	if(playerList.empty()){
		return true;
	}
	else{
		return false;
	}
}
