#include "ard.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include <QDateTime>
#include <QPrinter>
#include <QPainter>
#include <QTableView>
#include <QHeaderView>

ard::ard()
{

    lum="";

}
ard::ard(QString lum)
{  this->lum=lum;



}
bool ard::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO ARDUINO (LUM) VALUES (:LUM)");


    query.bindValue(":LUM",lum);

 return   query.exec();
}

QSqlQueryModel* ard::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ARDUINO");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Luminosite"));


    QTableView* tableView = new QTableView();
    tableView->setModel(model);

    // Mettre en forme le TableView
    tableView->setStyleSheet("QTableView {background-color: white; alternate-background-color: #FFB4B4; border: none; font-size: 12px;}"
                             "QTableView::item {padding: 5px;}"
                             "QHeaderView::section {background-color: #d8d8d8; color: #333; font-size: 12px;}"
                             "QTableView::horizontalHeader {border: none;}"
                             "QTableView::verticalHeader {border: none;}"
                             "QTableView::item:selected {background-color: #0078D7; color: white;}");

    return model;
}
