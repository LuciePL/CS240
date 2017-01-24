#include "Card.h"
#include "Deck.h"
using namespace std;
#include <iostream>

int main(){
	Deck* deck = new Deck();
	for(int i=0;i<52;i++){
		Card nCard =deck->draw();
		cout<< nCard.getSuitName() << " "<< nCard.getValue() <<endl;
	}
	cout<< "\n";
	Deck* deck2 = new Deck();
	deck2->shuffle();
	for(int i=0; i<52; i++){
		Card nCard =deck2->draw();
		cout<< nCard.getSuitName() << " "<< nCard.getValue() <<endl;
	}
}