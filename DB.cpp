//
// Created by rhys on 22/11/2020.
//

#include "DB.h"

using namespace std;

DB::DB(const char *path) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()){
        cerr << "Error: connection with database failed\n";
    }else{
        cout << "Database: connection ok\n";
    }
}

DB::~DB() {
    db.close();
}

std::vector<Recipe> DB::get_recipes() {
    std::vector<Recipe> out;

    QSqlQuery query = db.exec("SELECT * FROM recipes");

    if (!query.lastError().isValid()){
        while(query.next()){
            Recipe r = {
                query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toString(),
                query.value(4).toString(),
                query.value(5).toString(),
                query.value(6).toString(),
                query.value(7).toString(),
                query.value(8).toString()
            };

            out.push_back(r);
        }
    }else{
        cout << query.lastError().text().toStdString() << "\n";
    }

    return out;
}
