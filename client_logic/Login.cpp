#include "Login.h"
#include <iostream>
using namespace std;



Server Login::getServer()
{
	return m_server;
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
		while (!(cin >> port))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: " << endl;
		}
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
			m_server.setUser(userName);
			system("cls");
			cout << "logged in as " << m_server.getUser().getName() << endl;
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
