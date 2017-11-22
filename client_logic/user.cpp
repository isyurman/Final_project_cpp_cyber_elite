#include "user.h"



user::user()
{
	m_name = "";
}


void user::setName(std::string userName)
{
	m_name = userName;
}

std::string user::getName()
{
	return m_name;
}

user::user(std::string name)
{
	m_name = name;
}

void user::banUser(std::string userName)
{
	m_banUsers.emplace(userName);
}

void user::unBanUser(std::string userName)
{
	m_banUsers.erase(userName);
}

bool user::isBanedUser(std::string userName)
{
	return m_banUsers.count(userName);
}

user::~user()
{
}
