//
// Created by rhys on 29/12/2020.
//
#include "network.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

int write_memory_callback(void *contents, size_t size, size_t nmemb, void *userp){
    int realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char* ptr = (char*) realloc(mem->memory, mem->size + realsize + 1);

    if(ptr == NULL) {
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = (guint8*) ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

struct MemoryStruct get_url(const char* url){
    CURL *curl_handle;
    CURLcode res;

    struct MemoryStruct chunk;

    chunk.memory = (guint8*) malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();

    curl_easy_setopt(curl_handle, CURLOPT_URL, url);

    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_memory_callback);

    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    res = curl_easy_perform(curl_handle);

    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    }else {
        //printf("%lu bytes retrieved\n", (unsigned long)chunk.size);
    }

    curl_easy_cleanup(curl_handle);

    curl_global_cleanup();

    return chunk;
}
