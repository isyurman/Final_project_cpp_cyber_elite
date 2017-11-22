#pragma once
#include <iostream>
using namespace std;

class Server
{
public:
	bool connectServer(string serverName, int port);
	
	Server();
	~Server();
};

