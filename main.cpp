#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>

#if defined(VC16)
#include <Winsock2.h>
#pragma comment(lib, "wldap32.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "CRYPT32.lib")
#pragma comment(lib, "Normaliz.lib")
#endif

int main()
{
	char* url_post = "www.google.com";
	char* url_get = "www.google.com";
	
	CURL* curl;
	CURLcode res;
	curl = curl_easy_init();

	struct curl_slist* list = NULL;

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, url_get);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}

	return 0;
}