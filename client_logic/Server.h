#pragma once
#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

class Server
{
private:
	string m_serverName;
	int m_port;
	map<std::string, stack<std::string> > m_usersNewMessages;
public:
	bool connectServer(string serverName, int port);
	bool login(string userName);
	void SendMessage(const std::string, const std::string) const;
	int userNewMessagesCount(const std::string userName);
	void printUserNewMessages(const std::string userName);


	Server();
	~Server();
};

