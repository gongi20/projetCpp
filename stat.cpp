#include "stat.h"
#include "ui_stat.h"
#include "client.h"
#include "client_b.h"
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

stat::stat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat)
{
    ui->setupUi(this);
}

stat::~stat()
{
    delete ui;
}
