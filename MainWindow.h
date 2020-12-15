//
// Created by rhys on 11/12/2020.
//

#ifndef DINNERPLANNER_GUI_MAINWINDOW_H
#define DINNERPLANNER_GUI_MAINWINDOW_H

#include <QWidget>
#include <QtWidgets/QPushButton>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QtNetwork>
#include <QPixmap>

#include "json.hpp"
#include "DB.h"

#include "ui_MainWindow.h"

using json = nlohmann::json;

class MainWindow : public QMainWindow {
Q_OBJECT
private:
    Ui_MainWindow* ui;
    QGraphicsScene* imageScene;
    DB* db;

    std::vector<Recipe> recipes;
    std::vector<Recipe> displayed;

    void populateTable(QString searchTerm = "");

    void setRecipeView(Recipe recipe);

public slots:
    void cellDoubleClicked(int row, int col);
    void textChanged(QString data);

public:
    MainWindow(QWidget *parent = 0, const char *name = 0);
};

#endif //DINNERPLANNER_GUI_MAINWINDOW_H
