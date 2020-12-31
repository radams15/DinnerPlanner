//
// Created by rhys on 25/11/2020.
//

#include "Image.h"

Image::Image(string url) {
    Network::get_to_file(url, TEMP_FILE);
    path = TEMP_FILE;
}

Gtk::Image Image::get_image() {
    Gtk::Image out;
    //out.set(path);

    return out;
}
