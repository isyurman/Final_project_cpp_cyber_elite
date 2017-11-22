#pragma once
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <set>
using namespace std;

class Server
{
private:
	string m_serverName;
	int m_port;
	map<std::string, stack<std::string> > m_usersNewMessages;
	set<string> m_userList;
	void updateUsersListFromServer();

public:
	bool connectServer(string serverName, int port);
	bool login(string userName);
	void SendMessage(const std::string, const std::string) const;
	int userNewMessagesCount(const std::string userName);
	void printUserNewMessages(const std::string userName);
	set<string> getAllUsers();

	Server();
	~Server();
};

