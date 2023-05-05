#ifndef HISTO_H
#define HISTO_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QPropertyAnimation>
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QSqlRecord>
namespace Ui {
class histo;
}

class histo : public QDialog
{
    Q_OBJECT

public:
    explicit histo(QWidget *parent = nullptr);
    ~histo();
    void ecrirefichier(int n);


private slots:
    void on_ajouter_2_clicked();

    void on_ajouter_3_clicked();

    void on_supprimer_2_clicked();
    void deleteTxtFile(const QString fileName);

    void on_ajouter_4_clicked();

private:
    Ui::histo *ui;
};

#endif // HISTO_H
