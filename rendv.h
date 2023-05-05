#ifndef RENDV_H
#define RENDV_H
#include <QWidget>
#include <QPushButton>
//#include <QFrame>
#include <QPropertyAnimation>
#include <QDialog>


namespace Ui {
class Rendv;
}

class Rendv : public QDialog
{
    Q_OBJECT

public:
    explicit Rendv(QWidget *parent = nullptr);
    ~Rendv();

private:
    Ui::Rendv *ui;

private slots:

    void on_pushButton_13_clicked();

private:
    QPushButton *menuButton ;
    QWidget *side_menu;
    QPropertyAnimation *sideBarAnimation;
};

#endif // RENDV_H
