//
// Created by rhys on 23/11/2020.
//

#include "Network.h"

using string = std::string;

size_t Network::writefunc(void *ptr, size_t size, size_t nmemb, string *s){
    s->append((const char*) ptr);

    return size*nmemb;
}

string Network::get_url(const string& url){
    CURL *curl;
    CURLcode res;
    string s;

    curl = curl_easy_init();
    if(curl){

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }

    return s;
}