#pragma once
#include <iostream>
#include "Server.h"
using namespace std;

class MessageManger
{
public:
	void SendMessage(Server&, const std::string, const std::string) const;
	bool CheckNewMassages(Server & myServer);
	MessageManger();
	~MessageManger();
};

