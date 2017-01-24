#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>

class User{
	private:
		std::string* faveMovies;
		std::string username;
		std::string password;
	public:
		std::string lname;
		std::string fname;
		int age;
		
		User(std::string fname, std::string lname, int age, std::string username, std::string password){
			this->fname = fname;
			this->lname = lname;
			this->age = age;
			this-> username = username;
			this-> password = password;
			this-> faveMovies = new std::string[5];
		}
		User(){
			this-> faveMovies = new std::string[5];
		}
		
		bool authenticate(std::string password){
			return this->password == password;
		}
		std::string getUsername(){
			return this->username;
		}
		void setPassword(std::string new_password){
			this->password = new_password;
		}

		std::string* movieList(){
			return this->faveMovies;
		}


};

#endif
