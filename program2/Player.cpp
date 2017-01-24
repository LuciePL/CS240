#include "Player.h"
bool Player::bet(int amount){
	if(budget > amount){
		budget = budget-amount;
		return true;
	}
	else{
		return false;
	}
}
void Player::collectWInnings(int amount){
	budget+=amount;
}
