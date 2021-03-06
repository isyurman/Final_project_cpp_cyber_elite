#include "Server.h"

namespace CyberServer
{
	Server::Server(std::string serverName, unsigned int serverPort) : m_serverName(serverName), m_serverPort(serverPort)
	{
		//DoNothing
	}

	Server::~Server()
	{
		//DoNothing
	}

	//Set a new Server Name
	void Server::SetServerName(const std::string serverName)
	{
		m_serverName = serverName;
	}

	//Set a new Server Port
	void Server::SetServerPort(unsigned int serverPort)
	{
		m_serverPort = serverPort;
	}

	//Get the server name
	std::string Server::GetServerName(void) const
	{
		return m_serverName;
	}

	//Get the server port
	unsigned int Server::GetServerPort(void) const
	{
		return m_serverPort;
	}

	//Send a message to a user
	bool Server::SendMessageToUser(const std::string userName,const std::string message) const
	{
		for (auto it = m_listOfuser.begin(); it != m_listOfuser.end(); ++it)
		{
			if (userName == (*it)->getName())
			{
				//ToDo sendMessageToUser()
				return true;
			}
		}
		return false;
	}

	//BroadCast a message to all users
	bool Server::SendMessageToAllusers(const std::string) const
	{
		for (auto it = m_listOfuser.begin(); it != m_listOfuser.end(); ++it)
		{
			//ToDo send to all
		}

		return true;
	}

	//Return a vector with all users in the server
	std::vector<User*> Server::ListAllCurrentUsers() const
	{
		return m_listOfuser;
	}

	//Return a vector with all banned users
	std::vector<User*> Server::ListAllBannedUser() const
	{
		std::vector<User *> bannedUsers;

		for (auto it = m_listOfuser.begin(); it != m_listOfuser.end(); ++it)
		{
			if ((*it)->isBanned())
			{
				bannedUsers.push_back((*it));
			}
		}

		return bannedUsers;
	}


	//Return a vector with all users that are not banned
	std::vector<User*> Server::ListAllNotBannedUser() const
	{
		std::vector<User *> notBanneduser;
		
		for (auto it = m_listOfuser.begin(); it != m_listOfuser.end(); ++it)
		{
			if (!(*it)->isBanned())
			{
				notBanneduser.push_back((*it));
			}
		}

		return notBanneduser;
	}

	//Ban a specific user
	bool Server::BanUser(std::string userName)
	{
		for (auto it = m_listOfuser.begin(); it != m_listOfuser.end(); ++it)
		{
			if ((*it)->getName() == userName)
			{
				return (*it)->Ban();
			}
		}

		return false;
	}

	//Ban a specific user
	bool Server::BanUser(User * user)
	{
		for (auto it = m_listOfuser.begin(); it != m_listOfuser.end(); ++it)
		{
			if ((*it) == user)
			{
				return (*it)->Ban();
			}
		}

		return false;
	}

	//Unban a specific user
	bool Server::UnbanUser(std::string userName)
	{
		for (auto it = m_listOfuser.begin(); it != m_listOfuser.end(); ++it)
		{
			if ((*it)->getName() == userName)
			{
				return (*it)->unBan();
			}
		}

		return false;
	}

	//Unban a specific user
	bool Server::UnbanUser(User * user)
	{
		for (auto it = m_listOfuser.begin(); it != m_listOfuser.end(); ++it)
		{
			if ((*it) == user)
			{
				return (*it)->unBan();
			}
		}

		return false;
	}

	//Log out a user - remove it from list of users
	bool Server::LogOutUser(std::string userName)
	{
		for (auto it = m_listOfuser.begin(); it != m_listOfuser.end(); ++it)
		{
			if ((*it)->getName() == userName)
			{
				m_listOfuser.erase(it);
				return true;
			}
		}

		return false;
	}

	//Log out a user - remove it from list of users
	bool Server::LogOutUser(User * user)
	{
		for (auto it = m_listOfuser.begin(); it != m_listOfuser.end(); ++it)
		{
			if ((*it) == user)
			{
				m_listOfuser.erase(it);
				return true;
			}
		}

		return false;
	}

	void Server::start(void)
	{
		//Subscribe fucntions
		//listen(handle_function& func(jsonObject))
		//start listener.start()

		//to send message: send(jsonObject, ip)

	}

}
