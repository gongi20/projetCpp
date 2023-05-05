#include "menu.h"
#include "ui_menu.h"
#include "client.h"
#include "vehicule.h"
#include "equi.h"
#include "rendv.h"
#include "emp.h"


menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
   client c;
   c.setModal(true);
   c.exec();
}

void menu::on_pushButton_3_clicked()
{
   vehicule v;
   v.setModal(true);
   v.exec();
}

void menu::on_pushButton_4_clicked()
{
    Equi e;
    e.setModal(true);
    e.exec();
}



void menu::on_pushButton_5_clicked()
{
    Rendv r;
    r.setModal(true);
    r.exec();
}

void menu::on_pushButton_2_clicked()
{
    emp r;
    r.setModal(true);
    r.exec();
}
