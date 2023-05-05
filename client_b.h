#ifndef CLIENT_B_H
#define CLIENT_B_H
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
#include "arduino.h"
class client_b
{


private:
    int id,cin,number;
    QString nom,prenom,adresse;
public:
    client_b();
    client_b(QString nom,QString prenom,int number,int cin,QString adresse);
    int getid();
    QString getnom();
    QString getprenom();
    void setid(int id);
    void setnom (QString nom);
    void setprenom(QString prenom);
      void setcin(int cin);
      int getcin();
    bool ajouter();
    bool supprimer(int cin);
   client_b afficherr(int cin );
   bool modifier(int cin );
    QSqlQueryModel* afficher();
    QSqlQueryModel * chercher(int cin );
    void filtrer(QString recherche);
   void filterTable(QTableView *tableView, QString searchStr);
   QSqlQueryModel *chercher_vehi(QString MATRICULE);
   int calcul();
   QSqlQueryModel *chercherr(QString n);
   QSqlQueryModel *trie(QString s,QString f);
 bool verifierint(int x,int y);
  bool verifierint1(int x);
   QSqlQueryModel * chercherre(int cin);
   int calcultunis();
   int calculben();
   int calculmanouba();
   int calculariana();
   int calculaut();
QSqlQueryModel* chercherve(int cin,QString p);
QSqlQueryModel * cherchernbv();
bool ajouterparking(QString a,QString b);
bool modifierp(int a);
QSqlQueryModel* afficherpa();
};

#endif // CLIENT_B_H
