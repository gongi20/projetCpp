#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include "emp.h"
#include "client.h"
#include "client_b.h"
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QLabel>
#include <QTableView>
#include "arduino.h"
#include <QDebug>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include <QSqlRecord>
#include <QTimer>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ ui->setupUi(this);
    int ret=a.connect_arduino();
    switch (ret) {
    case (0):qDebug()<<"arduino is availible and connectd to : "<<a.getarduino_port_name();
        break;
    case (1):qDebug()<<"arduino is availible but not connectd to : ";
        break;
    case(-1):qDebug()<<"arduino is not  availible and  not connectd to : ";
        break;
    default:qDebug()<<"chay  ";

    }

 connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(serial_read()));

//Object::connect(a.getserial(),SIGNAL(readyRead()), this, SLOT(on_ajouter_clicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_9_clicked()
{
    menu m;
    m.setModal(true);
    m.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    emp e;
    e.setModal(true);
    e.exec();
}

void MainWindow::serial_read()
{
    data=a.read_from_arduino();
    //data.chop(2);
    int b=data.toInt();
    QString myString = QString::number(b);
    az=QString::fromStdString(data.toStdString());
//ui->lineEdit_9->setText("sfggfg");
       //  data=serial->readAll(); //récupérer les données reçues

   qDebug() << "receivehjhjd data:" <<data.toInt();

if(data=="888" || data=="88" || data=="8")
{
 //data="888";
 test=1;
//ui->lineEdit_9->setText("sfggfg");

}

if(data=="777" || data=="77" || data=="7")
{
    client_b n2;
    QSqlQueryModel * modele2=n2.cherchernbv();
    QString nbrinit =modele2->record(0).value("NBR").toString();
    QByteArray nbrard = nbrinit.toUtf8();
    a.write_to_arduino(nbrard);

}

if(data=="999" || data=="99" || data=="9")
{
    data="999";
    test=0;
 //  ui->lineEdit_9->setText("gongi");
}

 myInt = data.toInt();

//client_b n;
//QSqlQueryModel * modele=n.chercher(1466);
//QString nomSponsor =modele->record(0).value("NOM").toString();
/*if(nomSponsor!="")
{
   a.write_to_arduino("555") ;

}
else
{
    a.write_to_arduino("741") ;
}*/

}








void MainWindow::on_ajouter_clicked()
{
    if(test==1){
    client_b n;
    QTime currentT = QTime::currentTime();
 QString pe=currentT.toString("hh:mm:ss");
     QDate current= QDate::currentDate();
    QString timeStr=current.toString("yyyy-MM-dd")+"T00:00:00";;
int na=ui->lineEdit_9->text().toInt();
      QSqlQueryModel * modele=n.chercherve(na,timeStr);
      QString nomSponsor =modele->record(0).value("DATE_RDV").toString();

     //ui->lineEdit_9->setText(pe);


    if(nomSponsor==timeStr)
    {
        for(int i=0;i<100;i++)
        {client_b b;
       a.write_to_arduino("5");
       b.modifierp(5);
        }
   n.ajouterparking(ui->lineEdit_9->text(),pe);
    }
    else if(nomSponsor=="")
    {
        a.write_to_arduino("7") ;
        QMessageBox::critical(nullptr, QObject::tr("Erreur de saisie"),
                              QObject::tr(" pas de rendez vous ."),QMessageBox::Cancel);
    }
    else if(nomSponsor!="" && nomSponsor!=timeStr )
    {

        a.write_to_arduino("7") ;
        QMessageBox::critical(nullptr, QObject::tr("Erreur de saisie"),
                              QObject::tr("le rendez vous est : , %1").arg(nomSponsor),
                              QMessageBox::Cancel);

    }
    else
    {
    }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Erreur de saisie"),
                              QObject::tr("il n y a pas une voiture ."),QMessageBox::Cancel);
    }
     // a.write_to_arduino("555") ;
}

void MainWindow::update_label()
{
  /*  data=a.read_from_arduino();
 qDebug()<<"dato :"<<data.toInt();
ui->label_9->setText("OghN");
ui->label_9->setText("dqfsqfezsgfe");
    if(data=="1466")
    {
       // si les données reçues de arduino via la liaison série sont égales à 1
    }// alors afficher ON

    else if (data=="0")
        ui->label_9->setText("OFF");  */ // si les données reçues de arduino via la liaison série sont égales à
}
