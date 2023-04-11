#include "statistique.h"
#include "ui_statistique.h"
#include"produit.h"
#include <iostream>
#include "ui_produit.h"

using namespace std;

statistique::statistique(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}


int statistique::Stat_partie1()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("SELECT * FROM produit1 WHERE etat='bonne'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int statistique::Stat_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("SELECT * FROM produit1 WHERE etat='mauvaise'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}

void statistique::paintEvent(QPaintEvent *)
{

    int a=Stat_partie1();
    int b=Stat_partie2();

        float s1= a*100 ;
        float s2=b*100;
        float nb = a+b ;

        float q1 = s1/nb ;
        float q2 =s2/nb;

        float x = q1/100 ;

        float y = q2/100;



    QPainter painter(this);
    QRectF size=QRectF(100,80,this->width()-500,this->width()-500);
    painter.setBrush(Qt::white);
    painter.drawPie(size,0,5780*x);
    ui->label_2->setText("produit:bonne") ;
    painter.setBrush(QColor(240, 0, 32));
    painter.drawPie(size,5780*x,y*5780);
    ui->label_3->setText("produit:mauvaise") ;

    ui->stat2->setNum(q1) ;
    ui->stat3->setNum(q2) ;

}





