//
// Created by rhys on 23/11/2020.
//

#include "Network.h"

using string = std::string;

size_t Network::str_callback(void *ptr, size_t size, size_t nmemb, string *s){
    s->append((const char*) ptr);

    return size*nmemb;
}

string Network::get_to_string(const string& url){
    CURL *curl;
    CURLcode res;
    string s;

    curl = curl_easy_init();
    if(curl){

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, str_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }

    return s;
}

void Network::get_to_file(const string &url, const string &path) {
    CURL *curl;
    CURLcode res;
    string s;

    FILE* fp = fopen(path.c_str(), "wb");

    curl = curl_easy_init();
    if(curl){

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, file_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }

    fclose(fp);
}

size_t Network::file_callback(void *ptr, size_t size, size_t nmemb, FILE* f) {
    size_t written = fwrite((FILE*)ptr, size, nmemb, f);
    return written;
}
