#include "com.h"

com::com(void(*massege_handler)(json::value))
{
	this->massege_handler = massege_handler;
}

com::~com()
{
}

void com::lisetn()
{
	try
	{
		http_listener listener(L"http://localhost/");
		listener.support(
			methods::POST, 
			[this](http_request request) 
			{
				this->massege_handler(request.extract_json().get());
			}
		);

		listener
			.open()
			.then([&listener]() {TRACE(L"\nstarting to listen\n");})
			.wait();

		while (true);
	}
	catch (exception const & e)
	{
		wcout << e.what() << endl;
	}
}

void com::send(json::value jobj, wstring ip)
{
	http_client client(ip + L"::3000");
	client.request(methods::POST, L"/", jobj);
}

