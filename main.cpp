#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {



         w.show();
         QMessageBox::information(nullptr, QObject::tr("database is open"),
          QObject::tr("coonection successful.\n" "click cancel to exsit"),QMessageBox::Cancel);

    }
    else
    {
         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("coonection faild .\n" "click cancel to exsit"),QMessageBox::Cancel);
    }



    return a.exec();
}
