#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>

#include <QDialog>
#include <QWidget>


namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QDialog *parent = nullptr);
    ~statistique();

    int Stat_partie1() ;
    int Stat_partie2();
    void paintEvent(QPaintEvent *);



private:
    Ui::statistique *ui;
};

#endif // STATISTIQUE_H
