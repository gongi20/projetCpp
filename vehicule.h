#ifndef VEHICULE_H
#define VEHICULE_H
#include <QPushButton>
//#include <QFrame>
#include <QWidget>
#include <QPropertyAnimation>
#include <QDialog>

namespace Ui {
class vehicule;
}

class vehicule : public QDialog
{
    Q_OBJECT

public:
    explicit vehicule(QWidget *parent = nullptr);
    ~vehicule();

private:
    Ui::vehicule *ui;


private slots:

    void on_pushButton_13_clicked();

private:
    QPushButton *menuButton ;
    QWidget *side_menu;
    QPropertyAnimation *sideBarAnimation;
};

#endif // VEHICULE_H
