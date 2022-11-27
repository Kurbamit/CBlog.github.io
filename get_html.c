#define CURL_STATICLIB
#include <stdio.h>
#include <stdlib.h>
#include "curl/curl.h"


static size_t writeData(void* ptr, size_t size, size_t nmemb, void* stream)
{
	size_t written = fwrite(ptr, size, nmemb, (FILE* )stream);
	return written;
}

int main()
{
	CURL* curl;
	CURLcode result;
	static const char* bodyFileName = "body.txt";
	FILE* bodyFile;

	// init the curl session
	curl = curl_easy_init();

	if (!curl)
	{
		fprintf(stderr, "init failed\n");
		return EXIT_FAILURE;
	}
	// https://curl.se/libcurl/c/CURLOPT_URL.html
	curl_easy_setopt(curl, CURLOPT_URL, "https://kurbamit.github.io/CBlog.github.io/?fbclid=IwAR0iGS3zg1yVwrid7hPKfbDQzbwyt6DqicTVqGdEazHRzbNi6oQNmvbAj30");

	bodyFile = fopen(bodyFileName, "w+");
	if (!bodyFile)
	{
		curl_easy_cleanup(curl);
		return EXIT_FAILURE;
	}

	// https://curl.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);

	// https://curl.se/libcurl/c/CURLOPT_WRITEDATA.html
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, bodyFile);

	result = curl_easy_perform(curl);
	if (result != CURLE_OK)
	{
		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
		curl_easy_cleanup(curl);
	}

	fclose(bodyFile);
	curl_easy_cleanup(curl);

	return 0;
}