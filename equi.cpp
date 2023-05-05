#include "equi.h"
#include "ui_equi.h"

Equi::Equi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Equi)
{
    ui->setupUi(this);

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
    side_menu->setStyleSheet(" background-color: #071e26;; border:1px solid #071e26;");

    //create buttons
    QPushButton *button1 = new QPushButton("Notification", side_menu);
    QPushButton *button2 = new QPushButton("Code QR", side_menu);
    QPushButton *button3 = new QPushButton("Statistique", side_menu);
    QPushButton *button4 = new QPushButton("Exportation PDF", side_menu);
    button1->setGeometry(100, 2, 111, 45);
    button2->setGeometry(220, 2, 111, 45);
    button3->setGeometry(340, 2, 111, 46);
    button4->setGeometry(460, 2, 111, 46);
    button1->setStyleSheet("background-color: rgb(172, 172, 172);");
    button2->setStyleSheet("background-color: rgb(172, 172, 172);");
    button3->setStyleSheet("background-color: rgb(172, 172, 172);");
    button4->setStyleSheet("background-color: rgb(172, 172, 172);");


    // Create the QPropertyAnimation object


    sideBarAnimation = new QPropertyAnimation(side_menu, "geometry");

    // Connect the menu button's clicked() signal to the toggleSideBar() slot
    connect(menuButton, &QPushButton::clicked, this, &Equi::on_pushButton_13_clicked);
}

Equi::~Equi()
{
    delete ui;
}



void Equi::on_pushButton_13_clicked()
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
