#include <string>
#include <iostream>
#include "user.h"
using namespace std;

int main(){
	User u1; //= new user();
	string command;
	while (command != "Quit"){
	cout <<"Please enter a command (Create, Update, View, Favorites, or Quit):";
	cin >> command;
		if (command == "Create"){
			create(&u1);
		}
		else if(command == "Update"){
			update(&u1);
		}
		else if(command == "View"){
			view(&u1);
		}
		else if(command == "Favorites"){
			favorites(&u1);
		}

		else{
			cout<< "INVALID COMMAND";
		}
	}
}