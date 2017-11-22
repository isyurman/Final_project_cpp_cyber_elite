#pragma once
#include "user.h"
#include "Server.h"
class Login
{
private:
	Server m_server;

public:
	Server getServer();
	Login();
	~Login();
};

