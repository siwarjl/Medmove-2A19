#include "localisation.h"
#include "employe.h"

#include "ui_localisation.h"

localisation::localisation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::localisation)
{
    ui->setupUi(this);
}

localisation::~localisation()
{
    delete ui;
}

void localisation::map()
{
QSettings settings(QSettings::IniFormat, QSettings::UserScope,//
QCoreApplication::organizationName(), QCoreApplication::applicationName());
//QCoreApplication::applicationName()); - Cette ligne initialise un objet de type QSettings pour stocker les paramètres de l'application. Il utilise le format Ini pour stocker les paramètres et UserScope pour limiter l'accès à l'utilisateur actuel. Les deux derniers arguments sont utilisés pour identifier l'application

ui->map->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/Centre+hospitalier+international+Carthag%C3%A8ne/@36.8454516,10.1998697,15z/data=!4m6!3m5!1s0x12fd34c5b03fb787:0x882d729c47e37885!8m2!3d36.8454516!4d10.1998697!16s%2Fg%2F11bzyyl1tw");
}

void localisation::on_pushButton_26_clicked()
{
    employe e ;
    hide ();
    e.exec ();

}
