#include "historique.h"
#include<QDateTime>

historique::historique()
{

}
void historique:: enregistrer_txt(QString matricule ,QString marque,QString datec,QString dispo,QString etat)
{
   QFile file ("C:/Users/siwar/Desktop/histo.txt");
        if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
         qDebug()<<"erreur";
        QTextStream out(&file);
        QString d_info = QDateTime::currentDateTime().toString();

        QString message2=d_info+" - Une Ambulance a été ajoutée avec la matricule "+ matricule +"\n";
        out << message2;
         out << "matricule: " +matricule+ " marque: "+marque+ " date: "+datec+ " disponibilite: "+dispo+ " etat: "+etat+ "" << "\n";


}
QString historique::imprimer_hist()
{
   chaine="";
      QFile file("C:/Users/siwar/Desktop/histo.txt");
      if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        chaine="";

      QTextStream in(&file);

     while (!in.atEnd()) {

           QString myString = in.readLine();
           chaine+=myString+"\n";

     }
     return chaine;
}
void historique:: enregistrer_txt1(QString matricule ,QString marque,QString datec,QString dispo,QString etat)
{
   QFile file ("C:/Users/siwar/Desktop/histo.txt");
        if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
         qDebug()<<"erreur";
        QTextStream out(&file);
        QString d_info = QDateTime::currentDateTime().toString();

        QString message2=d_info+" - Une Ambulance a été modifiée avec la matricule "+ matricule +"\n";
        out << message2;
         out << "matricule: " +matricule+ " marque: "+marque+ " date: "+datec+ " disponibilite: "+dispo+ " etat: "+etat+ "" << "\n";


}
void historique:: enregistrer_txt2(QString matricule)
{
   QFile file ("C:/Users/siwar/Desktop/histo.txt");
        if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
         qDebug()<<"erreur";
        QTextStream out(&file);
        QString d_info = QDateTime::currentDateTime().toString();

        QString message2=d_info+" - Une Ambulance a été supprimée avec la matricule "+ matricule +"\n";
        out << message2;


}

