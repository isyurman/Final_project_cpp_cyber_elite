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
			same = username.compare(u.getName());
		return !same;
	}
	bool User::compareUserbyStringandIP(const std::string u) const
	{
		return !(username.compare(u));
	}
	bool User::printDetails() const
	{
		cout << "Username: " << username << endl << "Ip Adress: " << ipAdress << endl << "Currently banned: " << banned << endl;
		return true;
	}
	void User::operator=(User & d1)
	{
		User(d1.getName(), d1.getIP());
	}
	ostream & operator<<(ostream & os, const User & dt)
	{
		dt.printDetails();
		return os;
	}
	bool operator==(const User & d1, const User & d2)
	{
		return d1.compareUser(d2);
	}
}