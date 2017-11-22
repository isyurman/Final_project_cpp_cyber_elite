#include "Server.h"



bool Server::connectServer(string serverName, int port)
{
	//TODO use the server
	if (serverName == "true")
	{
		m_serverName = serverName;
		m_port = port;
		return true;
	}
	else
		return false;
}

bool Server::login(string userName)
{
	//TODO use the server
	if (userName == "true")
		return true;
	else
		return false;
}

void Server::SendMessage(const std::string userName, const std::string message) const
{
	//TODO
	if (userName == "")//send to all
	{

	}
	else
	{

	}
}

int Server::userNewMessagesCount(const std::string userName)
{
	int messagesCount = 0;
	if (m_usersNewMessages.count(userName) > 0)
	{
		messagesCount = m_usersNewMessages[ userName ].size();
	}

	return messagesCount;
}

void Server::printUserNewMessages(const std::string userName)
{
	if (m_usersNewMessages.count(userName) > 0)
	{
		cout << "messages to " << userName << ":" << endl;
		while (m_usersNewMessages[ userName ].size() > 0)
		{
			cout << (m_usersNewMessages[ userName ]).top();
			(m_usersNewMessages[ userName ]).pop();
		}
	}
}


Server::Server()
{
}


Server::~Server()
{
}

void Server::updateUsersListFromServer()
{
	m_userList.clear();
	m_userList.emplace("Yechiel");
	m_userList.emplace("Mord");
	m_userList.emplace("Israel");
	m_userList.emplace("Izik");
	m_userList.emplace("Alex");
	m_userList.emplace("Yosef");
}

set<string> Server::getAllUsers()
{
	updateUsersListFromServer();
	return m_userList;
}
