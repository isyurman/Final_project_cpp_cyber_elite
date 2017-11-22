#pragma once
#include <iostream>
using namespace std;
/*
	User class with name and if hes currently banned or not.
*/
namespace CyberServer{

	class User {
		bool banned;
		std::string username;
	public:
		User(std::string username);
		User();
		~User();
		bool isBanned();
		bool unBan();
		bool Ban();
		std::string getName();
		bool setName(std::string username);
		bool compareUser(User u);
		bool compareUserbyString(std::string username);
	};
}
