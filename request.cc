#include <curl/curl.h>
#include <stdio.h>
#include <string.h>

#include "prototype.h"


unsigned int send_post_request(char* ip, char* action) {
	CURL *hnd = curl_easy_init();

	char adresse[38] = "http://";
	strcat(adresse,ip);
	strcat(adresse,":5000/volets/status");

	curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
	curl_easy_setopt(hnd, CURLOPT_URL, adresse);

	struct curl_slist *headers = NULL;
	headers = curl_slist_append(headers, "postman-token: ac28d81a-beb7-c273-455a-e099a8c210c6");
	headers = curl_slist_append(headers, "cache-control: no-cache");
	headers = curl_slist_append(headers, "content-type: application/json");
	curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

	if (strcmp(action,"ouvrir")) {
		curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "{\"action\":\"ouvrir\"}");
	}
	else if (strcmp(action,"fermer")) {
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
