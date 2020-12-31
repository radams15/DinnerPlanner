//
// Created by rhys on 23/11/2020.
//

#ifndef DINNERPLANNER_GUI_NETWORK_H
#define DINNERPLANNER_GUI_NETWORK_H

#include <iostream>
#include <fstream>

#include <curl/curl.h>


namespace Network {
    using string = std::string;

    size_t str_callback(void *ptr, size_t size, size_t nmemb, string* s);
    size_t file_callback(void *ptr, size_t size, size_t nmemb, FILE* f);

    string get_to_string(const string &url);

    void get_to_file(const string &url, const string &path);
}

#endif //DINNERPLANNER_GUI_NETWORK_H
