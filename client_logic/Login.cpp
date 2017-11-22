#include "Login.h"
#include <iostream>
using namespace std;



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
		//if (m_server.connectServer(serverName, port))
	}



}


Login::~Login()
{
}
