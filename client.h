#ifndef CLIENT_H
#define CLIENT_H
#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QPropertyAnimation>
#include <QDialog>
#include <QString>
#include <client_b.h>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTextEdit>
#include "arduino.h"
namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT






public:
    explicit client(QWidget *parent = nullptr);

    ~client();
    void filtrer(QString recherche);
   void  filterTable(QTableView *tableView, QString searchStr);

private:
    Ui::client *ui;
    QTextEdit *texte;

private slots:

    void on_pushButton_15_clicked();

    void on_pushButton_21_clicked();

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_supprimer_2_clicked();

    void on_tab_client_activated(const QModelIndex &index);

    void on_modifier_clicked();

    void on_recherche_2_cursorPositionChanged(int arg1, int arg2);
    void print(QPrinter *printer);
void sauvegarderPDF();
    void on_imp_clicked();



  void on_facture_clicked();

  void on_pdf_3_clicked();

  void on_imp_2_clicked();

  void on_facture_2_clicked();

  void on_facture_3_clicked();

private:
    QPushButton *menuButton ;
    QWidget *side_menu;
    QPropertyAnimation *sideBarAnimation;
    client_b c;
    arduino a;
     QByteArray data;

};

#endif // CLIENT_H
