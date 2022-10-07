#include <iostream>
#include "libcurl_util.h"

int main()
{
	curl_global_init(CURL_GLOBAL_ALL);

	libcurl::utill::CurlBuilder builder;
	builder.SetHost("www.google.com");
	builder.SetScheme("https");
	builder.SetHeader("Content-Type: application/x-www-form-urlencoded");

	CURL* curl = builder.GetCurl();

	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

	// curl_easy_setopt(curl, CURLOPT_POST, 1L); ??
	// curl_easy_setopt(curl, CURLOPT_POSTFIELDS, ""); ??

#if 0 // stdout
	curl_easy_setopt(curl, CURLOPT_WRITEHEADER, stdout);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
#else // callback... not work
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void* ptr, size_t size, size_t nmemb, std::string * stream)
	{
		size_t s_size = size * nmemb;
		stream->assign((char*)ptr, (char*)ptr + s_size);
		std::cout << *stream << std::endl;
		return s_size;
	});
#endif

	auto res = curl_easy_perform(curl);

	if (res != CURLE_OK)
	{
		std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
	}

	curl_easy_cleanup(curl);
	curl_global_cleanup();

	return 0;
}