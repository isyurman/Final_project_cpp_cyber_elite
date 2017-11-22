#include "com.h"

com::com()
{
}

com::~com()
{
}

void com::lisetn() 
{
	try
	{
		this->listener
			.open()
			.then([this->listener]() {TRACE(L"\nstarting to listen\n");})
			.wait();

		while (true);
	}
	catch (exception const & e)
	{
		throw e.what();
	}
}