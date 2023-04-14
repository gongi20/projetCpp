#ifndef FACTURE_H
#define FACTURE_H
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

#include <QDialog>

namespace Ui {
class facture;
}

class facture : public QDialog
{
    Q_OBJECT

public:
    explicit facture(QWidget *parent = nullptr);
    ~facture();

private slots:
    void on_ajouter_3_clicked();
    void print(QPrinter *printer);
private:
    Ui::facture *ui;
    QTextEdit *texte;

};

#endif // FACTURE_H
