#include <curl/curl.h>
#include <stdio.h>

#include "prototype.h"


unsigned int send_post_request(char ip, char action) {
	CURL *hnd = curl_easy_init();

	curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
	curl_easy_setopt(hnd, CURLOPT_URL, "http://192.168.1.26:5000/volets/status");

	struct curl_slist *headers = NULL;
	headers = curl_slist_append(headers, "postman-token: ac28d81a-beb7-c273-455a-e099a8c210c6");
	headers = curl_slist_append(headers, "cache-control: no-cache");
	headers = curl_slist_append(headers, "content-type: application/json");
	curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

	if (action == "ouvrir") {
		curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "{\"action\":\"ouvrir\"}");
	}
	else if (action == "fermer") {
		curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "{\"action\":\"fermer\"}");
	}

	CURLcode ret = curl_easy_perform(hnd);

	if (ret == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
