#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>

#include <Winsock2.h>
#pragma comment(lib, "wldap32.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "CRYPT32.lib")
#pragma comment(lib, "Normaliz.lib")

int main()
{
	char* url_post = "https://www.example.com/";
	char* url_get = "https://www.example.com/";
	
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