#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <vector>
#include "Player.h"
#include "Heap.h"
#include "Card.h"
#include "Deck.h"


class Table{

	public:
	int num_seats;
	int ante;
	Deck* deck = new Deck();
	std::vector<Player> tablePlay;

	Table(int num_seats, int ante){
		this->num_seats = num_seats;
		this->ante = ante;
	}
	bool emptySeat();
	void addPlayer(Player p);
	void deal();
	std::vector<Player> playRound();
};
#endif
