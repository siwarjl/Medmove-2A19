#include "mainwindow.h"
<<<<<<< HEAD
=======
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>


>>>>>>> origin/produit
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< HEAD
    MainWindow w;
    w.show();
=======



    MainWindow w;
>>>>>>> origin/produit
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::warning(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
<<<<<<< HEAD



    return a.exec();
}
<<<<<<< HEAD

=======
>>>>>>> origin/gestionAmbulance
=======
    return a.exec();
}
>>>>>>> origin/produit
