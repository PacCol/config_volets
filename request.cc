#include <curl/curl.h>
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

	if ((strcmp(action,"ouvrir")) == 0) {
		curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "{\"action\":\"ouvrir\"}");
	}
	else if ((strcmp(action,"fermer")) == 0) {
		curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "{\"action\":\"fermer\"}");
	}

	curl_easy_setopt(hnd, CURLOPT_TIMEOUT, 4L);
	CURLcode ret = curl_easy_perform(hnd);

	if (ret == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

unsigned int programmer_heure(char* ip, int activation, int heure_ouverture, int minute_ouverture, int heure_fermeture, int minute_fermeture) {
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

	if (activation == 0) {
		curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "{\"action\":\"programmer_false\"}");
	}
	else {
		char requete[42] = "{\"action\":\"programmer_true(";
		char heure[2];
		sprintf(heure, "%d", heure_ouverture);
		strcat(requete, heure);
		strcat(requete, ",");
		sprintf(heure, "%d", minute_ouverture);
		strcat(requete, heure);
		strcat(requete, ",");
		sprintf(heure, "%d", heure_fermeture);
		strcat(requete, heure);
		strcat(requete, ",");
		sprintf(heure, "%d", minute_fermeture);
		strcat(requete, heure);
		strcat(requete,")\"}");
		curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, requete);
	}
	curl_easy_setopt(hnd, CURLOPT_TIMEOUT, 4L);
	CURLcode ret = curl_easy_perform(hnd);

	if (ret == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
