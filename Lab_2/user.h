#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>

class User{
	public:
		std::string lastName;
		std::string firstName;
		int age;
		std::string faveMovies[]= {"Deadpool", "Click", "Ants", "Cars", "300"};
};
void create(User* user);
void update(User* user);
void view(User* user);
void favorites(User* user);
#endif