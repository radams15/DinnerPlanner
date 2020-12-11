//
// Created by rhys on 22/11/2020.
//

#ifndef DINNERPLANNER_GUI_RECIPE_H
#define DINNERPLANNER_GUI_RECIPE_H

#include <string>
#include <QtCore/QString>

using string = std::string;

struct Recipe{
    int id;
    QString name;
    QString author;
    QString description;
    QString image_url;
    QString category;
    QString ingredients;
    QString method;
    QString url;
};

#endif //DINNERPLANNER_GUI_RECIPE_H
