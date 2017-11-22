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

user::~user()
{
}
