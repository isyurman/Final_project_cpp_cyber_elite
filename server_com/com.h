#pragma once
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#pragma comment(lib, "cpprest110_1_1")

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

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
	com();
	~com();
	void lisetn();

private:
	http_listener listener(L"");
};