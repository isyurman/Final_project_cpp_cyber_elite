#pragma once
#include <cpprest/http_listener.h>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

//#pragma comment(lib, "cpprest140d_2_9")

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;
using namespace web::http::client;

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

#define TRACE(msg)            wcout << msg
#define TRACE_ACTION(a, k, v) wcout << a << L" (" << k << L", " << v << L")\n"

map<utility::string_t, utility::string_t> dictionary;

class com
{
public:
	com(void(*massege_handler)(json::value));
	~com();
	void lisetn();
	void send(json::value, wstring ip);
private:
	void(*massege_handler)(json::value);

};

int main()
{

	return 0;
}