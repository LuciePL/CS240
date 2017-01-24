#include <iostream>
#include <string>
#include "user.h"
#include "MovieChart.h"

void MovieChart::create(){
			std::string first;
			std::string last;
			int age;
			std::string user;
			std::string pass;
			std::cout<< "Please enter first name: ";
			std::cin>> first;
			std::cout << first << std::endl;
			std::cout << "Please enter last name: ";
			std::cin >> last;
			std::cout << last <<std::endl;
			std::cout << "Please enter age: ";
			std::cin >>age;
			std::cout << age << std::endl;
			std::cout << "Please enter username: ";
			std::cin >> user;
			std::cout << user << std::endl;
			std::cout << " Please enter password: ";
			std::cin >> pass;
			std::cout << pass << std::endl;
			User* user1 = new User(first,last,age,user,pass);
			users[num_users] = *user1;
			num_users++;
		}

void MovieChart::logout(){
			current_user = NULL;
		}

bool MovieChart::login(){
			std::string user;
			std::string pass;
			std::cout << "Please enter your username: ";
			std::cin >> user;
			std::cout << user << std::endl;
			std::cout << "Please enter your password: ";
			std::cin >> pass;
			std::cout << pass <<std::endl;
			for(int i = 0; i<num_users; i++){
				if(user == users[i].getUsername()){
					if(users[i].authenticate(pass)){
						current_user = &users[i];
						return true;
					}
					else{
						std::cout << "Invalid username/password combination" <<std::endl;
						return false;
					}
				}
			}
			std::cout << "Invalid username/password combination" << std::endl;
			return false;
		}

void MovieChart::update(){
	std::string newInput;
	std::string newInput2;
	if(current_user != NULL){
		std::cout<< "Please enter which attribute to update (Password, Favorites):";
		std::cin >> newInput;
		if(newInput == "Password"){
			std::cout << "Please input your new password";
			std::cin >> newInput2;
			current_user->setPassword(newInput2);
		}
		else if(newInput == "Favorites"){
			std::string movies;
			std::string* listMovie = current_user -> movieList();
			std::cout << "Please input your new 5 Favorite Movies" <<std::endl;
			getline(std::cin,movies);
			for(int i =0; i<5; i++){
				getline(std::cin,movies);
				listMovie[i] = movies;
				std::cout << listMovie[i];
			}
		}
	}
	else{
		std::cout << "Please login before continuing.";
	}
}

void MovieChart::view(){
	std::string* ptr = current_user ->movieList();
	std::cout << "First name:"; 
	std::cout << current_user-> fname << std::endl;
	std::cout << "Last name:"; 
	std::cout << current_user-> lname << std::endl;
	std::cout << "Age:"; 
	std::cout << current_user-> age << std::endl;
	std::cout << "Username:"; 
	std::cout << current_user->getUsername() << std::endl;
	std::cout << "Favorite Movies:"; 
	for(int i=0; i<5; i++){
		std::cout << ptr[i]<< std::endl;
	}
}
