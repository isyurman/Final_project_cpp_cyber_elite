#pragma once
#include <string>


class user
{
private:
	std::string m_name;
public:
	void setName(std::string);
	std::string getName();
	user(std::string);
	user();
	~user();
};

