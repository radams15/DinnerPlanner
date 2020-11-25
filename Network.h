//
// Created by rhys on 23/11/2020.
//

#ifndef DINNERPLANNER_GUI_NETWORK_H
#define DINNERPLANNER_GUI_NETWORK_H

#include <iostream>

#include <curl/curl.h>


namespace Network {
    using string = std::string;

    size_t writefunc(void *ptr, size_t size, size_t nmemb, string *s);

    string get_url(const string &url);
}

#endif //DINNERPLANNER_GUI_NETWORK_H
