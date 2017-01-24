#include <iostream>
#include <string>
#include "user.h"
#include "MovieChart.h"
using namespace std;

int main(){
	MovieChart movieChart;
	string command;
	while (command != "Quit"){
	cout <<"Please enter a command (Create, Update, View, Login, Logout, or Quit):"<<endl;
	cin >> command;
	cout << command <<endl;
		if (command == "Create"){
			movieChart.create();
		}
		else if(command == "Update"){
			movieChart.update();
		}
		else if(command == "View"){
			movieChart.view();
		}
		else if(command == "Login"){
			movieChart.login();
		}
		else if(command == "Logout"){
			movieChart.logout();
		}

		else if(command != "Quit"){
			cout<< "INVALID COMMAND" << endl;
		}
	}
}
