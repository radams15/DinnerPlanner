//
// Created by rhys on 22/11/2020.
//

#ifndef DINNERPLANNER_GUI_DB_H
#define DINNERPLANNER_GUI_DB_H

#include <sqlite3.h>
#include <vector>
#include <cstring>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
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
