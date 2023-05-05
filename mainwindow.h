#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client_b.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void filtrer(QString recherche);

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();
    void serial_read();
  void  update_label();

  void on_ajouter_clicked();

private:
    Ui::MainWindow *ui;
    arduino a;
     QByteArray data;
   /*  QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
     //et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.
     static const quint16 arduino_uno_vendor_id=9025;
     static const quint16 arduino_uno_producy_id=67;
     QString arduino_port_name;
     bool arduino_is_available;*/
     QString az;
     int myInt;
     int test;

};
#endif // MAINWINDOW_H
