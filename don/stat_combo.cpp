#include "stat_combo.h"
#include "ui_stat_combo.h"
#include "dons.h"

stat_combo::stat_combo(QWidget * parent) :
    QDialog(parent),
    ui(new Ui::stat_combo)
{
    ui->setupUi(this);
}

stat_combo::~stat_combo()
{
    delete ui;
}

//pie chart
    void stat_combo::choix_pie()
    {
    QSqlQuery q1,q2,q3;
    qreal tot=0,c1=0,c2=0;

    q1.prepare("SELECT * FROM DONS");
    q1.exec();

    q2.prepare("SELECT * FROM DONS WHERE dispo='1'");
    q2.exec();

    q3.prepare("SELECT * FROM DONS WHERE dispo='0'");
    q3.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}



    c1=c1/tot;
    c2=c2/tot;

    // Define slices and percentage of whole they take up
    QPieSeries * series = new QPieSeries();
    series->append("1",c1);
    series->append("0",c2);



    // Create the chart widget
    QChart*chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();


    // Used to display the chart
    chartView = new QChartView(chart,ui->graphicsView);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(600,600);

    chartView->show();
    }

void stat_combo::on_pushButton_37_clicked()
{
    Dons d ;
        hide ();
        d.exec ();
}
