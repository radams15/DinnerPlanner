//
// Created by rhys on 11/12/2020.
//

#include <iostream>
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent, const char *name) : QMainWindow(parent) {
    ui = new Ui_MainWindow();
    ui->setupUi(this);
    setWindowTitle("Dinner Planner");

    db = new DB("recipes.sqlite");

    imageScene = new QGraphicsScene();

    recipes = db->get_recipes();

    ui->mainList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

    ui->mainList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QTableWidget::connect(ui->mainList, &QTableWidget::cellDoubleClicked, this, &MainWindow::cellDoubleClicked);
    QTableWidget::connect(ui->searchBox, &QLineEdit::textChanged, this, &MainWindow::textChanged);

    ui->tabWidget->setCurrentIndex(0);

    populateTable();
}

void MainWindow::populateTable(QString searchTerm) {
    int i=0;
    ui->mainList->clear();
    displayed.clear();

    QStringList headers;
    headers << "id" << "Title" << "By";
    ui->mainList->setColumnCount(headers.size());
    ui->mainList->hideColumn(0); // hide id col

    ui->mainList->setHorizontalHeaderLabels(headers);

    for(Recipe r : recipes){
        if(r.name.toLower().contains(searchTerm.toLower()) || r.author.toLower().contains(searchTerm.toLower())){
            ui->mainList->setRowCount(i+1);
            QTableWidgetItem* idItem = new QTableWidgetItem(r.id);
            QTableWidgetItem* nameItem = new QTableWidgetItem(r.name);
            QTableWidgetItem* authorItem = new QTableWidgetItem(r.author);

            ui->mainList->setItem(i, 0, idItem);
            ui->mainList->setItem(i, 1, nameItem);
            ui->mainList->setItem(i, 2, authorItem);
            displayed.push_back(r);
            i++;
        }
    }

    ui->mainList->resizeColumnsToContents(); // resize all cols to fit the content
}

QPixmap downloadPixmap(const QString& url){

    QNetworkAccessManager nam;
    QEventLoop loop;
    QObject::connect(&nam,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    QNetworkReply *reply = nam.get(QNetworkRequest(url));
    loop.exec();

    QPixmap pm;
    QByteArray p = reply->readAll();
    pm.loadFromData(p);

    delete reply;
    return pm;
}

void MainWindow::setRecipeView(Recipe r){
    ui->nameLabel->setText(r.name + "\n" + r.author);

    ui->tabWidget->setTabText(1, r.name);

    json ingredients = json::parse(r.ingredients.toStdString());
    json method = json::parse(r.method.toStdString());

    ui->dishTabs->setCurrentIndex(0);

    ui->ingredientsList->clear();
    ui->methodList->clear();

    for(std::string i : ingredients){
        ui->ingredientsList->addItem(QString::fromStdString(i));
    }

    for(std::string m : method){
        ui->methodList->addItem(QString::fromStdString(m));
    }

    QString link = "<a href=\"" + r.url + "\">" + r.url + "</a>";

    ui->urlLabel->setText(link);

    imageScene->clear(); // clears the display
    QRectF d;
    d.setX(0); // sets the image size to 0
    d.setY(0);
    imageScene->setSceneRect(d);

    QPixmap p = downloadPixmap(r.image_url);

    imageScene->addPixmap(p);

    ui->imageView->setScene(imageScene);
}

void MainWindow::cellDoubleClicked(int row, int col) {
    Recipe r = displayed[row];

    setRecipeView(r);

    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::textChanged(QString data){
    populateTable(data);
}
