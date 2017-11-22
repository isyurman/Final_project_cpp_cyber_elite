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
