#include "MessageManger.h"



void MessageManger::SendMessage(Server & myServer, const std::string userName, const std::string message) const
{
	myServer.SendMessage(userName, message);
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
