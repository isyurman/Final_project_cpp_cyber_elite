#include "Server.h"

void Server::getMessageHandler(/*json::object*/)
{
	//logic ot user and messege


	std::string user, messege;

	/*"Opcode" "1"
	user = "Username" 
	messege "Message"*/

	
	if (!m_user.isBanedUser(user))
	{
		m_usersNewMessages[ user ].push(messege);
	}
}

bool Server::connectServer(string serverName, int port)
{
	//TODO use the server
	if (serverName == "true")
	{
		m_serverName = serverName;
		m_port = port;
		return true;
		//listen(handle_function& func(json::object))
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
		/*"Opcode" "2"
		"Username" m_user.getName()
		"Message" message */
	}
	else
	{
		/*"Opcode" "1"
		"Username" m_user.getName()
			"Message" message
			"to" userName */
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

void Server::setUser(std::string userName)
{
	m_user.setName(userName);
}

user Server::getUser()
{
	return m_user;
}
