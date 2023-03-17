#ifndef CLIENT_H
#define CLIENT_H
#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QPropertyAnimation>
#include <QDialog>
#include <QString>
#include <client_b.h>

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT






public:
    explicit client(QWidget *parent = nullptr);

    ~client();

private:
    Ui::client *ui;

private slots:

    void on_pushButton_15_clicked();

    void on_pushButton_21_clicked();

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_supprimer_2_clicked();

    void on_tab_client_activated(const QModelIndex &index);

    void on_modifier_clicked();

private:
    QPushButton *menuButton ;
    QWidget *side_menu;
    QPropertyAnimation *sideBarAnimation;
    client_b c;

};

#endif // CLIENT_H
