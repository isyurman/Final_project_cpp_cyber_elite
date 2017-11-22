#include "MessageManger.h"



void MessageManger::SendMessage(Server & myServer, const std::string userName, const std::string message) const
{
	if (myServer.getUser().isBanedUser(userName))
	{
		cout << "user banned" << endl;
	}
	else
	{
		myServer.SendMessage(userName, message);
	}
}

bool MessageManger::CheckNewMassages(Server & myServer)
{
	return false;// myServer.hesNewMessages();
}

MessageManger::MessageManger()
{
}


MessageManger::~MessageManger()
{
}
