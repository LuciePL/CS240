#include "Table.h"
#include "Card.h"
#include "Deck.h"
#include <vector>
using namespace std;

bool Table::emptySeat(){
	if(tablePlay.size()< num_seats){
		return true;
	}
	else{
		return false;
	}
}

void Table::addPlayer(Player p){
	tablePlay.push_back(p);
}

void Table::deal(){
	deck->shuffle();
	for(auto i : tablePlay){
		i.hand = deck->draw();
	}
}

vector<Player> Table::playRound(){
	vector<Player> losers;
	/*deal();
	int winnerPot;
	Player winner = tablePlay.front();
	tablePlay.erase(tablePlay.begin());
	for(auto i : tablePlay){
		i.bet(ante);
		winnerPot+=ante;
		if(winner.hand.getValue()< i.hand.getValue()){
			losers.push_back(winner);
			winner = i;
		}
		else if(winner.hand.getValue() == i.hand.getValue()){
			if(winner.hand.getSuit() < i.hand.getSuit()){
				losers.push_back(winner);
				winner = i;
			}
		}
		else{
			tablePlay.erase(i);
		}
	}
	tablePlay[0].collectWinnings(winnerPot);*/
	return losers;
}
