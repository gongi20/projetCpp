#include "histo.h"
#include "ui_histo.h"
#include "facture.h"
#include "ui_facture.h"
#include "client.h"
#include "client_b.h"
#include "facture.h"
#include "ui_client.h"
#include "vehicule.h"
#include "ui_vehicule.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QTextEdit>
#include <QPainter>
#include <QPdfWriter>
#include <QMessageBox>
#include <QPrinter>
#include <QFile>
#include<QTextStream>
#include<QFileDialog>
#include <QMessageBox>
#include<QDir>
#include <QTimer>
#include <QDateTime>
histo::histo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::histo)
{
    ui->setupUi(this);
}

histo::~histo()
{
    delete ui;
}
void histo::ecrirefichier(int n){
    QString res = QString::number(n);
    QSqlQuery query;
    histo b;
    QSqlQueryModel * m;

    client_b a;
   m=a.chercherre(n);

   QString  date=m->record(0).value("DATE_RDV").toString();
    query.prepare("select * from GS_CLIENT where CIN=:CIN ");
    query.bindValue(":CIN",n);
    if(query.exec()) {
        while(query.next()) {
            QString m= query.value("NOM").toString();
            QString pm= query.value("PRENOM").toString();
            QString am= query.value("ADRESSE").toString();


        int numborne=query.value("NUM_TEL").toInt();
        int ci=query.value("CIN").toInt();
        QString c= QString::number(numborne);
        QString cc= QString::number(ci);
 QDate current= QDate::currentDate();
        QString fmt="yyyy-MM-ddThh:mm:ss";
        QDateTime dt=QDateTime::fromString(date,fmt);
        QString timeStr=current.toString("yyyy-MM-dd")+".txt";
        QFile file(timeStr);
        if(!file.open(QFile::Append | QFile::Text)){
            QMessageBox::warning(this,"title","file not open");
        }
        QTextStream out(&file);
      out<<"CIN : "<<ci<<" Date : "<<date<<" Capacite : "<<numborne <<" Pourcentage : "<<am<<endl;
        file.flush();
        file.close();

        }
    }

}



void histo::on_ajouter_2_clicked()
{
  histo p;

p.ecrirefichier(ui->lineEdit_16->text().toInt());
}

void histo::on_ajouter_3_clicked()
{

       QString filter="("+ui->lineEdit_18->text()+".txt);;";
       QDir currentdir= QDir::current();
      // QString filename=QFileDialog::getOpenFileName(this,"open a file",currentdir.path(),filter);
       QFile file(ui->lineEdit_18->text()+".txt");
       if(!file.open(QFile::ReadOnly | QFile::Text)){
           QMessageBox::warning(this,"title","file not open");
       }
       QTextStream in(&file);
       QString text=in.readAll();
       ui->plainTextEdit->setPlainText(text);
       file.close();

}



void histo::deleteTxtFile(const QString fileName) {
    QFile file(fileName);
    if (file.exists()) {
        if (file.remove()) {
            QMessageBox::information(nullptr, "Suppression réussie", "Le fichier a été supprimé avec succès.");
        } else {
            QMessageBox::warning(nullptr, "Erreur de suppression", "Le fichier n'a pas pu être supprimé.");
        }
    } else {
        QMessageBox::warning(nullptr, "Fichier introuvable", "Le fichier n'existe pas.");
    }
}


void histo::on_supprimer_2_clicked()
{
    histo p;
    p.deleteTxtFile(ui->lineEdit_16->text());
}

void histo::on_ajouter_4_clicked()
{
    QString filter="(*.txt);;";
    QDir currentdir= QDir::current();
    QString filename=QFileDialog::getOpenFileName(this,"open a file",currentdir.path(),filter);
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"title","file not open");
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();

}
