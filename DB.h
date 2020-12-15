//
// Created by rhys on 22/11/2020.
//

#ifndef DINNERPLANNER_GUI_DB_H
#define DINNERPLANNER_GUI_DB_H

#include <vector>
#include <iostream>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

#include "Recipe.h"

class DB {
private:
    QSqlDatabase db;
public:
    DB(const char* path);

    ~DB();

    std::vector<Recipe> get_recipes();
};


#endif //DINNERPLANNER_GUI_DB_H
