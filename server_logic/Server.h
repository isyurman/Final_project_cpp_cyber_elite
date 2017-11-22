#pragma once
#include <string>
#include <vector>
#include "User.h"

namespace CyberServer
{
	class Server
	{
	private:
		
		std::string m_serverName;
		unsigned int m_serverPort;
		std::vector<User *> m_listOfuser;
	
	public:

		Server(std::string, unsigned int);
		~Server();

		void SetServerName(const std::string);
		void SetServerPort(unsigned int);
		
		std::string GetServerName(void) const;
		unsigned int GetServerPort(void) const;

		bool SendMessageToUser(const std::string, const std::string) const;
		bool SendMessageToAllusers(const std::string) const;

		std::vector<User *> ListAllCurrentUsers() const;
		std::vector<User *> ListAllBannedUser() const;
		std::vector<User *> ListAllNotBannedUser() const;

		bool BanUser(std::string);
		bool BanUser(User *);

		bool UnbanUser(std::string);
		bool UnbanUser(User *);

		bool LogOutUser(std::string);
		bool LogOutUser(User *);

	};

}
