#include "Login.h"
#include <iostream>
using namespace std;



Server Login::getServer()
{
	return m_server;
}

user Login::getUser()
{
	return m_me;
}

Login::Login()
{
	string serverName, userName;
	int port;
	bool connected = false;
	bool loggedIn = false;

	cout << "hello" << endl;
	while (!connected)
	{
		cout << "please enter server name" << endl;
		cin >> serverName;
		cout << "port:" << endl;
		cin >> port;
		if (m_server.connectServer(serverName, port))
		{
			connected = true;
		}
		else
		{
			cout << "server not exists" << endl;
		}
	}

	while (!loggedIn)
	{
		cout << "user name:" << endl;
		cin >> userName;
		if (m_server.login(userName))
		{
			m_me.setName(userName);
			system("cls");
			cout << "logged in as " << m_me.getName() << endl;
			loggedIn = true;
		}
		else
		{
			cout << "user already exists" << endl;
		}
	}



}


Login::~Login()
{
}
