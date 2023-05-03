#include "statistique.h"
#include "ui_statistique.h"
<<<<<<< HEAD
#include"ambulance.h"
#include <iostream>
#include "ui_ambulance.h"
=======
#include"produit.h"
#include <iostream>
#include "ui_produit.h"
>>>>>>> origin/produit

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
<<<<<<< HEAD
    QSqlQuery requete("SELECT * FROM AMBULANCE WHERE dispo='dispo'") ;
=======
    QSqlQuery requete("SELECT * FROM produit1 WHERE etat='bonne'") ;
>>>>>>> origin/produit
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
<<<<<<< HEAD
    QSqlQuery requete("SELECT * FROM AMBULANCE WHERE dispo='non dispo'") ;
=======
    QSqlQuery requete("SELECT * FROM produit1 WHERE etat='mauvaise'") ;
>>>>>>> origin/produit
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
<<<<<<< HEAD
    QRectF size=QRectF(100,100,this->width()-500,this->width()-500);

    painter.setBrush(QColor(235, 197, 197));
    painter.drawPie(size,0,5780*x);
    ui->label_2->setText("Ambulance:Dispo") ;
    painter.setBrush(Qt::gray);
    painter.drawPie(size,5780*x,y*5780);
    ui->label_3->setText("Ambulance:Non Dispo") ;
=======
    QRectF size=QRectF(100,80,this->width()-500,this->width()-500);
    painter.setBrush(Qt::white);
    painter.drawPie(size,0,5780*x);
    ui->label_2->setText("produit:bonne") ;
    painter.setBrush(QColor(240, 0, 32));
    painter.drawPie(size,5780*x,y*5780);
    ui->label_3->setText("produit:mauvaise") ;
>>>>>>> origin/produit

    ui->stat2->setNum(q1) ;
    ui->stat3->setNum(q2) ;

}





