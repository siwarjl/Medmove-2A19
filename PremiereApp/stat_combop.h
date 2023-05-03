#ifndef STAT_COMBOP_H
#define STAT_COMBOP_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

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


QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat_combop;
}

class stat_combop : public QDialog
{
    Q_OBJECT

public:
    explicit stat_combop(QWidget *parent = nullptr);
    ~stat_combop();
    QChartView *chartView ;
    void choix_pie();
private:
    Ui::stat_combop *ui;

};


#endif // STAT_COMBOP_H
