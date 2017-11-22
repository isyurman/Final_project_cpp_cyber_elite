#include "com.h"

void com::display_json(
	json::value const & jvalue,
	utility::string_t const & prefix)
{
	wcout << prefix << jvalue.serialize() << endl;
}

void com::handle_request(
	http_request request,
	function<void(json::value const &, json::value &)> action)
{
	auto answer = json::value::object();

	request
		.extract_json()
		.then([&answer, &action](pplx::task<json::value> task) {
		try
		{
			auto const & jvalue = task.get();
			this->display_json(jvalue, L"R: ");

			if (!jvalue.is_null())
			{
				action(jvalue, answer);
			}
		}
		catch (http_exception const & e)
		{
			wcout << e.what() << endl;
		}
	})
		.wait();


	display_json(answer, L"S: ");

	request.reply(status_codes::OK, answer);
}


void com::handle_post(http_request request)
{
	TRACE("\nhandle POST\n");

	handle_request(
		request,
		[](json::value const & jvalue, json::value & answer)
	{
		for (auto const & e : jvalue.as_array())
		{
			if (e.is_string())
			{
				auto key = e.as_string();
				auto pos = dictionary.find(key);

				if (pos == dictionary.end())
				{
					answer[key] = json::value::string(L"<nil>");
				}
				else
				{
					answer[pos->first] = json::value::string(pos->second);
				}
			}
		}
	});
}

com::com(void(*massege_handler)(json::object))
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
		listener.support(methods::POST, handle_post);

		listener
			.open()
			.then([&listener]() {TRACE(L"\nstarting to listen\n");})
			.wait();

		while (true);
	}
	catch (exception const & e)
	{
		throw e.what();
	}
}

