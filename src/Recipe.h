//
// Created by rhys on 22/11/2020.
//

#ifndef DINNERPLANNER_GUI_RECIPE_H
#define DINNERPLANNER_GUI_RECIPE_H

#include <string>

using string = std::string;

struct Recipe{
    int id;
    string name;
    string author;
    string description;
    string image_url;
    string category;
    string ingredients;
    string method;
    string url;
};

#endif //DINNERPLANNER_GUI_RECIPE_H
