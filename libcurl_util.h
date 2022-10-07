/*
* created by ysbaekFox
*/

#ifndef LIBCURL_UTIL_H
#define LIBCURL_UTIL_H

#include <curl/curl.h>

#include <map>
#include <vector>

namespace libcurl::utill
{
	class CurlBuilder
	{
	public:
		CURL* GetCurl();

		void SetHost(const char* host);
		void SetScheme(const char* scheme);
		void SetUser(const char* user);
		void SetPassword(const char* password);
		void SetPort(const char* port);
		void SetPath(const char* path);
		void SetFragment(const char* fragment);
		void AppendQuery(const char* query);
		void SetHeader(const char* curl_slist);

	private:
		const char* m_host = nullptr;
		const char* m_scheme = nullptr;
		const char* m_user = nullptr;  
		const char* m_password = nullptr;
		const char* m_port = nullptr;
		const char* m_path = nullptr;
		const char* m_fragment = nullptr;

		std::vector<const char*> m_queries;

		struct curl_slist* m_curl_slist = nullptr;
	};
}

#endif