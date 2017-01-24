#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include "Deck.h"
#include <iostream>

class Player{
	private:
	std::string name;
	int budget;

	public:
	Card hand;

	Player(std::string name, int budget){
		this->name = name;
		this->budget = budget;
		//this->hand = new card(1,1);
		
	}
	std::string getName(){
		return this->name;
	}
	int getBudget(){
		return this->budget;
	}

	bool bet(int amount);
	void collectWInnings(int amount);
};

#endif
