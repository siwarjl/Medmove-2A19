#include "stat_combo.h"
#include "ui_stat_combo.h"
#include "employe.h"

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
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM EMPLOYE");
    q1.exec();

    q2.prepare("SELECT * FROM EMPLOYE WHERE TACHE='infermier'");
    q2.exec();

    q3.prepare("SELECT * FROM EMPLOYE WHERE TACHE='medecin'");
    q3.exec();
    q4.prepare("SELECT * FROM EMPLOYE WHERE TACHE='chauffeur'");
    q4.exec();


    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}



    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;
    //le pourcentage
    qreal c1_percent = c1 * 100;
          QString c1_label = "infermier " + QString::number(c1_percent, 'f', 0) + "%";

          qreal c2_percent = c2 * 100;
          QString c2_label = "medecin " + QString::number(c2_percent, 'f', 0) + "%";
          qreal c3_percent = c3 * 100;
          QString c3_label = "chauffeur " + QString::number(c3_percent, 'f', 0) + "%";

    // Define slices and percentage of whole they take up
    QPieSeries * series = new QPieSeries();
    series->append("infermier",c1);
    series->append("medecin",c2);
    series->append("chauffeur",c3);

    // Set labels visible for slices and set label text
    series->setLabelsVisible();
    series->slices().at(0)->setLabel(c1_label);
    series->slices().at(1)->setLabel(c2_label);
    series->slices().at(2)->setLabel(c3_label);
    QPieSlice *slice = series->slices().at(1);
    series->slices().at(0)->setBrush(QColor("#cd5c5c"));
    series->slices().at(1)->setBrush(QColor("#ffb6c1"));
    series->slices().at(2)->setBrush(QColor("#db7093"));
        slice->setExploded(false);

        slice->setLabelVisible(true);


    // Create the chart widget
    QChart*chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);

    chart->legend()->show();
    chart->setAnimationOptions(QChart::AllAnimations);


    // Used to display the chart
    chartView = new QChartView(chart,ui->graphicsView);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(600,600);

    chartView->show();
    }



void stat_combo::on_pushButton_26_clicked()
{
    employe e ;
    hide ();
    e.exec ();
}
