#include <iostream>
#include <string>
#include "user.h"
#ifndef MOVIECHART_H
#define MOVIECHART_H

class MovieChart{
	private:
		User users[255]; //= new User[255];
		int num_users;
		User* current_user;

	public:
		MovieChart(){
			this->num_users = 0;
		}
		bool login();
		void logout();
		void create();
		void update();
		void view();
};

#endif
