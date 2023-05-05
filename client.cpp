#include "client.h"
#include "client_b.h"
#include "graph.h"
#include "facture.h"
#include "histo.h"
#include "ui_client.h"
#include "vehicule.h"
#include "ui_vehicule.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QTextEdit>
#include <QPainter>
#include <QPdfWriter>
#include <QMessageBox>
#include <QPrinter>
#include<QDir>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include "arduino.h"
client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
     ui->setupUi(this);
int ret=a.connect_arduino();
switch (ret) {
case (0):qDebug()<<"arduino is availible and connectd to : "<<a.getarduino_port_name();
    break;
case (1):qDebug()<<"arduino is availible but not connectd to : ";
    break;
case(-1):qDebug()<<"arduino is not  availible and  not connectd to : ";
    break;

}
QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


 ui->tab_client->setModel(c.chercherr(ui->recherche_2->text()));





// QPrinter


   //  c.filtrer("mehdi");
    // Create and set up the menu button
    menuButton = new QPushButton("", this);
    menuButton->setGeometry(20, 43, 71, 41);
    QIcon icon(":/new/prefix1/icons/menu.png");
    menuButton->setIcon(icon);

    // resize the icon to fit the button
    menuButton->setIconSize(QSize(40, 40));

    // Create and set up the side bar
    side_menu = new QWidget(this);
    side_menu->setGeometry(120, 40, 0, 50);
    side_menu->setStyleSheet(" background-color: rgb(0,0,0); border:1px solid rgb(0,0,0);");

    //create buttons
    QPushButton *button1 = new QPushButton("historique", side_menu);
    QPushButton *button2 = new QPushButton("Facturation", side_menu);
    QPushButton *button3 = new QPushButton("statistique", side_menu);
    QPushButton *button4 = new QPushButton("exportation PDF", side_menu);
    button1->setGeometry(100, 2, 111, 45);
    button2->setGeometry(220, 2, 111, 45);
    button3->setGeometry(340, 2, 111, 46);
    button4->setGeometry(460, 2, 111, 46);
    button1->setStyleSheet("background-color:  rgb(172, 172, 172);");
    button2->setStyleSheet("background-color:  rgb(172, 172, 172);");
    button3->setStyleSheet("background-color:  rgb(172, 172, 172);");
    button4->setStyleSheet("background-color:  rgb(172, 172, 172);");


    // Create the QPropertyAnimation object


    sideBarAnimation = new QPropertyAnimation(side_menu, "geometry");

    // Connect the menu button's clicked() signal to the toggleSideBar() slot
    connect(menuButton, &QPushButton::clicked, this, &client::on_pushButton_15_clicked);
}

client::~client()
{
    delete ui;
}

void client::filtrer(QString recherche)
{

    QTableView *tableau = ui->tab_client ; // Remplacez "tableView" par le nom de votre widget de vue de tableau
    QStandardItemModel *model = qobject_cast<QStandardItemModel *>(tableau->model());
    if (!model) {
        return;
    }

    for (int i = 0; i < model->rowCount(); i++) {
        bool correspondance = false;
        for (int j = 0; j < model->columnCount(); j++) {
            QString texte = model->data(model->index(i, j)).toString();
            if (texte.contains(recherche, Qt::CaseInsensitive)) {
                correspondance = true;
                break;
            }
        }
        tableau->setRowHidden(i,!correspondance);
    }
}




void client::on_pushButton_15_clicked()
{
    if (side_menu->width() < 1 ) {
        // If the side bar is currently hidden, animate it into view
        sideBarAnimation->setDuration(500);
        sideBarAnimation->setEasingCurve(QEasingCurve::OutQuad);
        sideBarAnimation->setEndValue(QRect(120, 40, 821, 50));
        sideBarAnimation->start();
    } else {
        // If the side bar is currently visible, animate it out of view
        sideBarAnimation->setDuration(500);
        sideBarAnimation->setEasingCurve(QEasingCurve::OutQuad);
        sideBarAnimation->setEndValue(QRect(120, 40, 0, 50));
        sideBarAnimation->start();
    }
}

void client::on_pushButton_21_clicked()
{
    vehicule v;
    v.setModal(true);
    v.exec();

}



void client::on_ajouter_clicked()
{
int a=0;
    QString n=ui->lineEdit_3->text();
    QString p=ui->lineEdit_6->text();
    QString ad=ui->lineEdit_5->currentText();
    int ci=ui->lineEdit_8->text().toInt();
    int nu=ui->lineEdit_7->text().toInt();
     client_b c(n,p,nu,ci,ad);
     QRegExp rx("^[A-Za-z]+$");
     bool is_int;


bool num=c.verifierint(nu,ci);

     if(n.isEmpty() )
     {

         QMessageBox::critical(nullptr, QObject::tr("Erreur de saisie"),
                               QObject::tr("Le champ Nom est vide. Veuillez entrer un nom."),QMessageBox::Cancel);
         return;



     }
     else if(!rx.exactMatch(n))

     {
         QMessageBox::critical(nullptr, QObject::tr("Erreur de saisie"),
                               QObject::tr("Le champ Nom ne doit contenir que des lettres. Veuillez vérifier votre saisie."),QMessageBox::Cancel);
         //return;
     }
     else
     {
         a++;
     }
     if(p.isEmpty() )
     {

         QMessageBox::critical(nullptr, QObject::tr("Erreur de saisie"),
                               QObject::tr("Le champ PReNom est vide. Veuillez entrer un nom."),QMessageBox::Cancel);
         return;



     }
     else if(!rx.exactMatch(p))
     {
         QMessageBox::critical(nullptr, QObject::tr("Erreur de saisie"),
                               QObject::tr("Le champ PRENNom ne doit contenir que des lettres. Veuillez vérifier votre saisie."),QMessageBox::Cancel);
         //return;
     }
     else
     {
         a++;
     }
     if(num!=true)
     {
         QMessageBox::critical(nullptr, QObject::tr("Erreur de saisie"),
                               QObject::tr("Le champ CIN est numero  ne doit contenir que des chiffrs. Veuillez vérifier votre saisie."),QMessageBox::Cancel);
     }
     else
     {
         a++;
     }


     QDate current= QDate::currentDate();
     QTime currentT = QTime::currentTime();
    QString timeStr=current.toString("yyyy-MM-dd")+".txt";
    QFile file(timeStr);
    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"title","file not open");
    }


bool test;
  if(a==3)
 {
   bool test=c.ajouter();
}
     if(test==true && a==3)
     {
      ui->tab_client->setModel(c.afficher());
          QMessageBox::information(nullptr, QObject::tr("OK"),
           QObject::tr("ajouter effectue .\n" "click cancel to exsit"),QMessageBox::Cancel);

          QTextStream out(&file);
        out<<" Le  client  est  ajouter avec id :"<<ci<<" nom :"<<n <<" prenom : "<< p<<" adress: "<<ad << " a : "<<  currentT.toString("hh:mm:ss")<<endl;
          file.flush();
          file.close();


     }
     else
     {
       ui->tab_client->setModel(c.afficher());
          QMessageBox::critical(nullptr, QObject::tr("not ok "),
                                QObject::tr("ajouter non effectuer. \n" "click cancel to exsit"),QMessageBox::Cancel);
     }
     //c.ajouter();
      ui->lineEdit_3->clear();
      ui->lineEdit_6->clear();
     //ui->lineEdit_5->clear();
     ui->lineEdit_8->clear();
     ui->lineEdit_7->clear();


}

void client::on_supprimer_clicked()
{


client_b c;

int cie=ui->id_sup->text().toInt();
client_b monClient;
QSqlQueryModel * modele=monClient.chercher(cie);
QString nomSponsor =modele->record(0).value("NOM").toString();

QDate current= QDate::currentDate();
  QTime currentT = QTime::currentTime();
QString timeStr=current.toString("yyyy-MM-dd")+".txt";
QFile file(timeStr);
if(!file.open(QFile::Append | QFile::Text)){
   QMessageBox::warning(this,"title","file not open");
}
c.setcin(ui->id_sup->text().toInt());

if(nomSponsor!="")
{


bool test=c.supprimer(c.getcin());



if(test)
{
ui->tab_client->setModel(c.afficher());
     QMessageBox::information(nullptr, QObject::tr("OK"),
      QObject::tr("supp avec succes .\n" "click cancel to exsit"),QMessageBox::Cancel);
     QTextStream out(&file);
   out<<" client avec cin : " <<cie <<" est  supprimer a "<< currentT.toString("hh:mm:ss") <<endl;
     file.flush();
     file.close();
}
else
{

     QMessageBox::critical(nullptr, QObject::tr("not ok "),
                           QObject::tr("echec de supp. \n" "click cancel to exsit"),QMessageBox::Cancel);
}
}
else
{
    QMessageBox::critical(nullptr, QObject::tr("not ok "),
                          QObject::tr(" client nexsite deja  . \n" "click cancel to exsit"),QMessageBox::Cancel);
}

}

void client::on_supprimer_2_clicked()
{
       int ci=ui->id_sup->text().toInt();
    client_b monClient;

    // Appeler la fonction chercher avec un numéro d'identification
    QSqlQueryModel * modele=monClient.chercher(ci);
    QString nomSponsor =modele->record(0).value("NOM").toString();
     QString nomSponsor2=modele->record(0).value("PRENOM").toString();
     QString nomSponsor3=modele->record(0).value("ADRESSE").toString();
     int ent=modele->record(0).value("NUM_TEL").toInt();
     int entt=modele->record(0).value("CIN").toInt();
      //int entier=modele->record(0).value("NUM").toInt();
    ui->lineEdit_3->setText(nomSponsor);
    ui->lineEdit_6->setText(nomSponsor2);
    ui->lineEdit_5->addItem(nomSponsor3);
    QString myString = QString::number(ent);
    QString myStringg = QString::number(entt);
    ui->lineEdit_7->setText(myString);
    ui->lineEdit_8->setText(myStringg);
}



void client::on_modifier_clicked()
{



    QString n=ui->lineEdit_3->text();
    QString p=ui->lineEdit_6->text();
    QString ad=ui->lineEdit_5->currentText();
    int ci=ui->lineEdit_8->text().toInt();
    int nu=ui->lineEdit_7->text().toInt();
     client_b c(n,p,nu,ci,ad);

     // Créer un objet client_b
      int cip=ui->id_sup->text().toInt();
  client_b monClient;
  client_b monClientt;

  // Appeler la fonction chercher avec un numéro d'identification
  QSqlQueryModel * modele=monClient.chercher(cip);
  QString nomSponsor =modele->record(0).value("NOM").toString();
  QDate current= QDate::currentDate();
    QTime currentT = QTime::currentTime();
  QString timeStr=current.toString("yyyy-MM-dd")+".txt";
  QFile file(timeStr);
  if(!file.open(QFile::Append | QFile::Text)){
     QMessageBox::warning(this,"title","file not open");
  }

    /* QSqlQueryModel * modele=monClient.chercher(ci);
     QString nomSponsor = modele->record(0).value("NOM").toString();
     ui->lineEdit_9->setText(nomSponsor);*/
     if(nomSponsor!="")
     {
          QSqlQueryModel * modelee=monClientt.chercher(ci);
          QString nomSponsorr =modelee->record(0).value("NOM").toString();

         if(nomSponsorr!="" && ci!=cip)
         {
             QMessageBox::critical(nullptr, QObject::tr("not ok "),
                                   QObject::tr(" cin exsite deja  . \n" "click cancel to exsit"),QMessageBox::Cancel);

         }
         else
         {



         bool test=c.modifier(ci);
         if(test)
         {

              QMessageBox::critical(nullptr, QObject::tr("not ok "),
                                    QObject::tr(" modifer  non effectuer. \n" "click cancel to exsit"),QMessageBox::Cancel);

         }
         else
         {

            ui->tab_client->setModel(c.afficher());

            QMessageBox::information(nullptr, QObject::tr("OK"),
             QObject::tr("modifer  effectue .\n" "click cancel to exsit"),QMessageBox::Cancel);
            QTextStream out(&file);
          out<<" Le  client avec ce  cin : " <<ci <<" est  modifier a "<< currentT.toString("hh:mm:ss") <<endl;
            file.flush();
            file.close();
         }

     }
       }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("not ok "),
                               QObject::tr("nexsite pas . \n" "click cancel to exsit"),QMessageBox::Cancel);

     }



}


void client::on_recherche_2_cursorPositionChanged(int arg1, int arg2)
{
    client_b c;
    client cv;

    ui->tab_client->setModel(c.chercherr(ui->recherche_2->text()));

     //QString p=ui->recherche_2->text();

}
void client_b::filterTable(QTableView *tableView, QString searchStr)
{

    QStandardItemModel *model = qobject_cast<QStandardItemModel *>(tableView->model());
    if (!model) {
        return;
    }

    // Réinitialisation des lignes cachées
    for (int i = 0; i < model->rowCount(); i++) {
        tableView->setRowHidden(i, false);
    }

    // Filtrage des lignes correspondantes
    for (int i = 0; i < model->rowCount(); i++) {
        bool match = false;
        for (int j = 0; j < model->columnCount(); j++) {
            QString text = model->data(model->index(i, j)).toString();
            if (text.contains(searchStr, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        tableView->setRowHidden(i, !match);
    }
}


void client::print(QPrinter *printer)
{

    texte->print(printer);
}
void client::on_imp_clicked()
{
        QString n=ui->lineEdit_33->text();
    // Ouvrir un fichier PDF pour l'écriture
        QPdfWriter writer(" "+n+".pdf");

        // Créer un QPainter pour dessiner sur le PDF
        QPainter painter(&writer);
         int cie=ui->id_sup->text().toInt();
        client_b b;
  QSqlQueryModel * modelep=b.chercher(ui->id_sup->text().toInt());
  QString m= modelep->record(0).value("NOM").toString();
  QString nomSponsor =modelep->record(0).value("NOM").toString();
   QString nomSponsor2=modelep->record(0).value("PRENOM").toString();
   QString nomSponsor3=modelep->record(0).value("ADRESSE").toString();
   int ent=modelep->record(0).value("NUM_TEL").toInt();
   int entt=modelep->record(0).value("CIN").toInt();
   QString c= QString::number(entt);
   QString cc= QString::number(ent);


   QDate current= QDate::currentDate();
     QTime currentT = QTime::currentTime();
   QString timeStr=current.toString("yyyy-MM-dd")+".txt";
   QFile file(timeStr);
   if(!file.open(QFile::Append | QFile::Text)){
      QMessageBox::warning(this,"title","file not open");
   }


   QTextStream out(&file);
 out<<" Le  client avec ce  cin : " <<c <<" est  enregistrer dans ce ficher : "<< n << " a : "<< currentT.toString("hh:mm:ss") <<endl;
   file.flush();
   file.close();
        // Définir les options de mise en page
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.setRenderHint(QPainter::HighQualityAntialiasing);
        painter.setRenderHint(QPainter::NonCosmeticDefaultPen);
        int a=b.calcul();
        QString nb= QString::number(a);

        // Desiner un texte sur le PDF
        int x = 50; // position horizontale du tableau
        int y = 50; // position verticale du tableau


        // En-têtes de colonnes
        painter.drawText(x, y, " Cin ");
        painter.drawText(x + 2000, y, "Nom");
        painter.drawText(x + 4000, y, "Prenom");
         painter.drawText(x + 6000, y, "Adresse");
          painter.drawText(x + 8000, y, "Num_tel");

//for(int i=0;i<a-1;i++)
//{

       painter.drawText(x, y+500,c);
        painter.drawText(x + 2000, y+500,nomSponsor);
        painter.drawText(x + 4000, y + 500, nomSponsor2);
        painter.drawText(x+6000, y +500, nomSponsor3);
        painter.drawText(x + 8000, y +500, cc);
//}

        // Charger une image à partir d'un fichier
     /*   QImage image("images.jpg");
        if (image.isNull()) {
            QMessageBox::warning(nullptr, "Erreur", "Impossible de charger l'image !");

        }*/

        // Dessiner l'image sur le PDF
   // painter.drawImage(QRectF(100, 500,10000,10000), image);
        QMessageBox::information(nullptr, QObject::tr("OK"),
         QObject::tr(" PDF  effectue .\n" "click cancel to exsit"),QMessageBox::Cancel);

        // Finaliser le document PDF
        painter.end();
}



void client::on_facture_clicked()
{
    facture v;
    v.setModal(true);
    v.exec();
}


void client::on_imp_2_clicked()
{
    client_b a;
      ui->tab_client->setModel(a.trie(ui->comboBox_4->currentText(),ui->comboBox_5->currentText()));
}

void client::on_facture_2_clicked()
{
    histo c;
    c.setModal(true);
    c.exec();
}

void client::on_facture_3_clicked()
{


    graph c;
    c.setModal(true);
    c.exec();
}
