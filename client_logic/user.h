#pragma once
#include <string>
#include <set>


class user
{
private:
	std::string m_name;
	std::set<std::string> m_banUsers;
public:
	void setName(std::string);
	std::string getName();
	user(std::string);
	void banUser(std::string userName);
	void unBanUser(std::string userName);
	bool isBanedUser(std::string userName);
	user();
	~user();
};

