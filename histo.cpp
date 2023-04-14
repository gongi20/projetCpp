#include "histo.h"
#include "ui_histo.h"

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
