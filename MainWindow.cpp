//
// Created by rhys on 11/12/2020.
//

#include <iostream>
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent, const char *name) : QMainWindow(parent) {
    ui = new Ui_MainWindow();
    ui->setupUi(this);
    setWindowTitle(name);

    db = new DB("/home/rhys/scripts/Projects/DinnerPlanner/DinnerPlannerGui_Qt/recipes.sqlite");

    recipes = db->get_recipes();

    ui->mainList->setColumnCount(3);
    ui->mainList->setRowCount(recipes.size());
    ui->mainList->hideColumn(0); // hide id col

    ui->mainList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

    ui->mainList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QTableWidget::connect(ui->mainList, &QTableWidget::cellDoubleClicked, this, &MainWindow::cellDoubleClicked);

    populateTable();
}

void MainWindow::populateTable() {
    int i=0;
    for(Recipe r : recipes){
        QTableWidgetItem* idItem = new QTableWidgetItem(r.id);
        QTableWidgetItem* nameItem = new QTableWidgetItem(r.name);
        QTableWidgetItem* authorItem = new QTableWidgetItem(r.author);

        ui->mainList->setItem(i, 0, idItem);
        ui->mainList->setItem(i, 1, nameItem);
        ui->mainList->setItem(i, 2, authorItem);
        i++;
    }

    ui->mainList->resizeColumnsToContents(); // resize all cols to fit the content
}

void MainWindow::cellDoubleClicked(int row, int col) {
    Recipe r = recipes[row];
    std::cout << r.image_url.toStdString() << "\n";
}
