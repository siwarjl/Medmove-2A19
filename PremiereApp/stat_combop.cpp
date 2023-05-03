#include "stat_combop.h"
#include "ui_stat_combop.h"

stat_combop::stat_combop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_combop)
{
    ui->setupUi(this);
}

stat_combop::~stat_combop()
{
    delete ui;
}

//pie chart
    void stat_combop::choix_pie()
    {
    QSqlQuery q1,q2,q3;
    qreal tot=0,c1=0,c2=0;

    q1.prepare("SELECT * FROM PATIENTC");
    q1.exec();

    q2.prepare("SELECT * FROM PATIENTC WHERE ETAT='malade'");
    q2.exec();

    q3.prepare("SELECT * FROM PATIENTC WHERE ETAT='blesse'");
    q3.exec();



    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}


    c1=c1/tot;
    c2=c2/tot;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    QPieSlice *slice1 = series->append("malade", c1);
     QPieSlice *slice2 = series->append("blesse", c2);

    QString label1 = QString("%1 (%2%)").arg(slice1->label()).arg(qRound(c1*100));
      slice1->setLabel(label1);
      QString label2 = QString("%1 (%2%)").arg(slice2->label()).arg(qRound(c2*100));
      slice2->setLabel(label2);

    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();
chart->setAnimationOptions(QChart::AllAnimations);

    // Used to display the chart
    chartView = new QChartView(chart,ui->graphicsView);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();
    }
