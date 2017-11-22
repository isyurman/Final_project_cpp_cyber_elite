#pragma once
#include "user.h"
#include "Server.h"
class Login
{
private:
	user m_me;
	Server m_server;

public:
	Server getServer();
	user getUser();
	Login();
	~Login();
};

