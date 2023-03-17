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

class client_b
{
private:

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

};

#endif // CLIENT_B_H
