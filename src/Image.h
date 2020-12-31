//
// Created by rhys on 25/11/2020.
//

#ifndef DINNERPLANNER_GUI_IMAGE_H
#define DINNERPLANNER_GUI_IMAGE_H

#include <string>
#include <iostream>

#include <gtkmm.h>

#include "Network.h"

#define TEMP_FILE "temp.jpg"

using string = std::string;

class Image {
private:
    string path;
public:
    explicit Image(string url);

    Gtk::Image get_image();
};


#endif //DINNERPLANNER_GUI_IMAGE_H
