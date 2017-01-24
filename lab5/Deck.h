#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <iostream>
#include <algorithm>
#include <deque>
class Deck{
	std::deque<Card> cardDeck;
	
	public:
		Deck(){
			for(int val=1; val<14; val++){
				for(int suit=1; suit<5; suit++){
					Card* newCard = new Card(suit,val);
					cardDeck.push_back(*newCard);
					//std::cout<< newCard->getValue();
				}
			}

		}
		void shuffle(){
			std::random_shuffle(cardDeck.begin(), cardDeck.end());
			//std::cout<< newCard->getValue();
		}
		
		Card draw(){
			Card toRet = cardDeck.front();
			cardDeck.pop_front(); 
			return toRet;
		}
};

#endif
