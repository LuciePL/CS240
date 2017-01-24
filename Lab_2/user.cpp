#include <iostream>
#include <string>
#include "user.h"
using namespace std;

void create(User* user){
	string input;
	string input2;
	string input3;
	
	cout << "Please enter first name:";
	cin >> input;
	user->firstName = input;
	
	cout << "Please enter last name:";
	cin >> input2;
	user -> LastName = input2;
	
	cout << "Please enter age:";
	cin >> input3;
	user -> age = input3;
	
	for(int i =0; i<5; i++){
		user ->faveMovies[i]=null;
	}
}

void update(User* user){
	string newInput;
	cout << "Please enter which attribute to update (First, Last, Age):";
	cin >> newInput;
	if(newInput = "First"){
		user ->firstName = newInput;
	}
	else if(newInput = "Last"){
		user -> lastName = newInput;
	}
	else{
		user -> age = newInput;
	}
	
}

void view(User* user){
	cout << "First name:" << user -> firstName << '\n';
	cout << "Last name:" << user -> lastName << '\n';
	cout << "Age:" << user -> age << '\n';
	cout << "Favorite Movies:" << user -> faveMovies[0] << '\n' << user -> faveMovies[1] <<'\n' << user -> faveMovies[2]<<'\n' << user -> faveMovies[3] <<'\n' << user -> faveMovies[4];
}

void favorites(User* user){
	cout << "Please input your new 5 Favorite Movies";
	getLine(cin,movies);
	for(int i =0; i<5; i++){
		getLine(cin,user-> faveMovies[0] = movies);
		
	}
	
}