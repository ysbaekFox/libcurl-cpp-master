#include "libcurl_util.h"

#if defined(VC16)
#include <Winsock2.h>
#pragma comment(lib, "wldap32.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "CRYPT32.lib")
#pragma comment(lib, "Normaliz.lib")
#endif

using namespace libcurl::utill;

CURL* CurlBuilder::GetCurl()
{
	CURL* handle = curl_easy_init();

	CURLU* urlp = curl_url();
	if (nullptr != m_host)     curl_url_set(urlp, CURLUPART_HOST, m_host, 0);
	if (nullptr != m_scheme)   curl_url_set(urlp, CURLUPART_SCHEME, m_scheme, 0);
	if (nullptr != m_user)     curl_url_set(urlp, CURLUPART_USER, m_user, 0);
	if (nullptr != m_password) curl_url_set(urlp, CURLUPART_PASSWORD, m_password, 0);
	if (nullptr != m_port)     curl_url_set(urlp, CURLUPART_PORT, m_port, 0);
	if (nullptr != m_path)     curl_url_set(urlp, CURLUPART_PATH, m_path, 0);
	if (nullptr != m_fragment) curl_url_set(urlp, CURLUPART_FRAGMENT, m_fragment, 0);

	for (const char* query : m_queries)
	{
		curl_url_set(urlp, CURLUPART_QUERY, query, CURLU_APPENDQUERY | CURLU_URLENCODE);
	}

	curl_easy_setopt(handle, CURLOPT_CURLU, urlp);

	if (nullptr != m_curl_slist) curl_easy_setopt(handle, CURLOPT_HTTPHEADER, m_curl_slist);

	return handle;
}

void CurlBuilder::SetHost(const char* host)
{
	m_host = host;
}

void CurlBuilder::SetScheme(const char* scheme)
{
	m_scheme = scheme;
}

void CurlBuilder::SetUser(const char* user)
{
	m_user = user;
}

void CurlBuilder::SetPassword(const char* password)
{
	m_password = password;
}

void CurlBuilder::SetPort(const char* port)
{
	m_port = port;
}

void CurlBuilder::SetPath(const char* path)
{
	m_path = path;
}

void CurlBuilder::SetFragment(const char* fragment)
{
	m_fragment = fragment;
}

void CurlBuilder::AppendQuery(const char* query)
{
	m_queries.push_back(query);
}

void CurlBuilder::SetHeader(const char* curl_slist)
{
	m_curl_slist = curl_slist_append(m_curl_slist, curl_slist);
}