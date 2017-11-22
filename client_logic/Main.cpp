#include <iostream>
#include "Login.h"
#include "Server.h"
#include "MessageManger.h"

using namespace std;

void menu(Server &myServer)
{
	set<string> users;
	int state = 1;

	while (state)
	{
		system("cls");
		cout << "All users that are connected:\n";
		users = myServer.getAllUsers();
		int i = 2;
		for (set<string>::iterator it = users.begin(); it != users.end(); ++it, ++i)
		{
			cout << i << " " << *it;
			int countNewMessege = myServer.userNewMessagesCount(*it);
			if (countNewMessege)
			{
				cout << " - " << countNewMessege << " new messeges";
			}
			cout << endl;
		}

		cout << "What you want to do:\n"
			<< "To send a messege to all users press 1.\n"
			<< "To open a conversation with a user choose a user.\n"
			<< "To exit press 0.\n";
		cin >> state;
		switch (state)
		{
			case 0:

				break;
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			default:
				break;
		}
	}
}

void main()
{
	Login login;
	MessageManger myMessageManger;
	menu(login.getServer());
}