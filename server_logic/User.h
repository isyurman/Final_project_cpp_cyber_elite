#pragma once
#include <iostream>
#include <string>
using namespace std;
/*
	User class with name and if hes currently banned or not.
*/
namespace CyberServer{

	class User {
		bool banned;
		std::string username;
		std::string ipAdress;
	public:
		User(const std::string u, const std::string ip);
		User();
		~User();
		bool isBanned() const;
		bool unBan();
		bool Ban();
		std::string getName() const;
		std::string getIP() const;
		bool setName(const std::string u);
		bool setIP(const std::string u);
		bool compareUser(const User u) const; 
		bool compareUserbyStringandIP(const std::string u) const;
		bool printDetails() const;
		friend ostream& operator<<(ostream& os, const User& dt);
		friend bool operator==(const User& d1, const User& d2);
		void operator=(User& d1);
	};
}
