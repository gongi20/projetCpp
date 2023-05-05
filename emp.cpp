#include "emp.h"
#include "ui_emp.h"

emp::emp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::emp)
{
    ui->setupUi(this);
}

emp::~emp()
{
    delete ui;
}
