#include "User.h"
namespace CyberServer {
	User::User(const std::string u, const std::string i)
	{
		username.assign(u);
		ipAdress.assign(i);
		banned = false;
	}
	User::User()
	{
		username.assign("");
		ipAdress.assign("127.0.0.1");
		banned = false;
	}
	User::~User()
	{
		username.clear();
		ipAdress.clear();
	}
	bool User::isBanned() const
	{
		return banned;
	}
	bool User::unBan()
	{
		banned = false;
		return banned;
	}
	bool User::Ban()
	{
		banned = true;
		return banned;
	}
	std::string User::getName() const
	{
		return username;
	}
	std::string User::getIP() const
	{
		return ipAdress;
	}
	bool User::setName(const std::string u)
	{
		bool isempty = false;
		username.assign(u);
		if (username.empty())
		{
			isempty = true;
		}
		return isempty;
	}
	bool User::setIP(const std::string ip)
	{
		ipAdress.assign(ip);
		return true;
	}
	bool User::compareUser(User u) const
	{
		bool same = true;
		if (banned == u.isBanned())
			same = (username.compare(u.getName()) && ipAdress.compare(u.getIP()));
		return !same;
	}
	bool User::compareUserbyStringandIP(const std::string u, const std::string ip) const
	{
		return !(username.compare(u) && ipAdress.compare(ip));
	}
	bool User::printDetails() const
	{
		cout << "Username: " << username << endl << "Ip Adress: " << ipAdress << endl << "Currently banned: " << banned << endl;
		return true;
	}
}