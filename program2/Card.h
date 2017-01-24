#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <map>

class Card{
	private:
		int suit;
		int value;

	public:
		Card(int suit, int value){
			this->suit = suit;
			this->value = value;
			findSuit.insert(std::pair<int,std::string>(1,"Spades"));
			findSuit.insert(std::pair<int,std::string>(2,"Hearts"));
			findSuit.insert(std::pair<int,std::string>(3,"Clubs"));
			findSuit.insert(std::pair<int,std::string>(4,"Diamonds"));
		}
		
		Card(){
			this->suit = 0;
			this->value = 0;
			findSuit.insert(std::pair<int,std::string>(1,"Spades"));
			findSuit.insert(std::pair<int,std::string>(2,"Hearts"));
			findSuit.insert(std::pair<int,std::string>(3,"Clubs"));
			findSuit.insert(std::pair<int,std::string>(4,"Diamonds"));
		}
		int getValue(){
			return this->value;
		}
		
		int getSuit(){
			return this->suit;
		}

		std::map<int,std::string> findSuit;
		
		std::string getSuitName(){
			return findSuit.find(suit)->second;
		}
		
};

#endif
