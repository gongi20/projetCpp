#include "client.h"
#include "client_b.h"
#include "ui_client.h"
#include "vehicule.h"
#include "ui_vehicule.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>

client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
  ui->tab_client->setModel(c.afficher());
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
    QString ad=ui->lineEdit_5->text();
    int ci=ui->lineEdit_8->text().toInt();
    int nu=ui->lineEdit_7->text().toInt();
     client_b c(n,p,nu,ci,ad);
     QRegExp rx("^[A-Za-z]+$");
     bool is_int;



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
                               QObject::tr("Le champ Nom est vide. Veuillez entrer un nom."),QMessageBox::Cancel);
         return;



     }
     else if(!rx.exactMatch(p))
     {
         QMessageBox::critical(nullptr, QObject::tr("Erreur de saisie"),
                               QObject::tr("Le champ Nom ne doit contenir que des lettres. Veuillez vérifier votre saisie."),QMessageBox::Cancel);
         //return;
     }
     else
     {
         a++;
     }





bool test;
  if(a==2)
 {
   bool test=c.ajouter();
}
     if(test!=true && a==2)
     {
      ui->tab_client->setModel(c.afficher());
          QMessageBox::information(nullptr, QObject::tr("OK"),
           QObject::tr("ajouter effectue .\n" "click cancel to exsit"),QMessageBox::Cancel);

     }
     else
     {
       ui->tab_client->setModel(c.afficher());
          QMessageBox::critical(nullptr, QObject::tr("not ok "),
                                QObject::tr("ajouter non effectuer. \n" "click cancel to exsit"),QMessageBox::Cancel);
     }
     //c.ajouter();

}

void client::on_supprimer_clicked()
{
client_b c;
c.setcin(ui->id_sup->text().toInt());
bool test=c.supprimer(c.getcin());
if(test)
{
ui->tab_client->setModel(c.afficher());
     QMessageBox::information(nullptr, QObject::tr("OK"),
      QObject::tr("supp avec succes .\n" "click cancel to exsit"),QMessageBox::Cancel);

}
else
{

     QMessageBox::critical(nullptr, QObject::tr("not ok "),
                           QObject::tr("echec de supp. \n" "click cancel to exsit"),QMessageBox::Cancel);
}

}

void client::on_supprimer_2_clicked()
{
    client_b v;
   client_b c;
   //QString x;
   v.setcin(ui->id_sup->text().toInt());
    c=v.afficherr(132);
   /* if(c=="")
    {
        c="mmmm";
    }*/
//QString myString = QString::number(c);

    //ui->lineEdit_3->se
    ui->lineEdit_9->setText(c.getnom());

    // ui->lineEdit_3->setText(c.getcin());
    //ui->lineEdit_3->setText(c.getcin());

}



void client::on_modifier_clicked()
{



    QString n=ui->lineEdit_3->text();
    QString p=ui->lineEdit_6->text();
    QString ad=ui->lineEdit_5->text();
    int ci=ui->lineEdit_8->text().toInt();
    int nu=ui->lineEdit_7->text().toInt();
     client_b c(n,p,nu,ci,ad);


    bool test=c.modifier(ci);
    if(test)
    {

         QMessageBox::critical(nullptr, QObject::tr("not ok "),
                               QObject::tr("ajouter non effectuer. \n" "click cancel to exsit"),QMessageBox::Cancel);

    }
    else
    {

       ui->tab_client->setModel(c.afficher());

       QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("modifer  effectue .\n" "click cancel to exsit"),QMessageBox::Cancel);

    }
}
