#include <iostream>
#include <string>
#include "Login.h"
#include "Server.h"
#include "MessageManger.h"

using namespace std;
void conversation(Server &myServer, int countNewMessege, string userName);

void menu(Server &myServer)
{
	set<string> users;
	int state = 1;
	int countNewMessege = 0;

	while (state)
	{
		system("cls");
		cout << "All users that are connected:\n";
		users = myServer.getAllUsers();
		int i = 2;
		for (set<string>::iterator it = users.begin(); it != users.end(); ++it, ++i)
		{
			cout << i << " " << *it;
			countNewMessege = myServer.userNewMessagesCount(*it);
			if (countNewMessege)
			{
				cout << " - " << countNewMessege << " new messeges";
			}
			cout << "\n\n";
		}

		cout << "What you want to do:\n"
			<< "To send a messege to all users press 1.\n"
			<< "To open a conversation with a user choose a user.\n"
			<< "To exit press 0.\n\n";
		cin >> state;
		switch (state)
		{
			case 0:				
				break;
			case 1:
				
				break;
			default:
				if (state > 1 && state < users.size())
				{
					set<string>::iterator it = users.begin();
					for (int i = 0; i < state+2; i++)
					{
						it++;
					}
					conversation(myServer, countNewMessege, *it);
				}
				else
				{
					cout << "Not recognized command\n";
				}
				break;
		}
	}
}

void conversation(Server &myServer, int countNewMessege, string userName)
{
	int state = 1;
	string messege;

	while (state)
	{
		if (countNewMessege)
		{
			myServer.printUserNewMessages(userName);
		}
		cout << "To send a messege press 1.\n";
		// if (!ban)
		//{	
			cout << "To ban the user press 2.\n";
		//}
		//else
		//{
			cout << "To unban the user press 2.\n";
		//}
			cout << "To Exit press 0.\n";
		cin >> state;
		switch (state)
		{
			case 1:
				cin >> messege;
				myServer.SendMessage(userName, messege);
				break;
			case 2:
				// if (!ban)
				//{	
				//	bun
				//}
				//else
				//{
				//	unban
				//}
				break;
			case 0:
				break;
			default:
				cout << "Not recognized command\n";
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