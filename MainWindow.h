//
// Created by rhys on 11/12/2020.
//

#ifndef DINNERPLANNER_GUI_MAINWINDOW_H
#define DINNERPLANNER_GUI_MAINWINDOW_H

#include <QWidget>
#include <QtWidgets/QPushButton>

#include "DB.h"

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow {
Q_OBJECT
private:
    Ui_MainWindow* ui;
    DB* db;

    std::vector<Recipe> recipes;

    void populateTable();

public slots:
    void cellDoubleClicked(int row, int col);

public:
    MainWindow(QWidget *parent = 0, const char *name = 0);
};


#endif //DINNERPLANNER_GUI_MAINWINDOW_H
