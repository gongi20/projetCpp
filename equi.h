#ifndef EQUI_H
#define EQUI_H
#include <QWidget>
#include <QPushButton>
//#include <QFrame>
#include <QPropertyAnimation>
#include <QDialog>


namespace Ui {
class Equi;
}

class Equi : public QDialog
{
    Q_OBJECT

public:
    explicit Equi(QWidget *parent = nullptr);
    ~Equi();

private:
    Ui::Equi *ui;

private slots:

    void on_pushButton_13_clicked();

private:
    QPushButton *menuButton ;
    QWidget *side_menu;
    QPropertyAnimation *sideBarAnimation;
};

#endif // EQUI_H
