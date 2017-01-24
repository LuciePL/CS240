#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Player.h"

class Heap{
	private:
	

	public:
	std::vector<Player> playerList;

	Heap(std::string filename);
	Heap(const Heap &copy);
	void addPlayer(Player newPlayer);
	Player getPlayer();
	std::vector<Player> getArray();
	bool empty();
	unsigned int size();
	void heapify();
	bool isLeaf(int i);
	void siftdown(int i);
	void swap(int player1, int player2);
};
#endif
