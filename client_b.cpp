#include "client_b.h"
#include "client.h"
#include "ui_client.h"
#include "vehicule.h"
#include "ui_vehicule.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QObject>
#include <QSqlRecord>

client_b::client_b()
{

     id=0;
    number=0;
    nom="";
    prenom="";
    cin=0;
    adresse="";

}
client_b::client_b(QString nom,QString prenom,int number,int cin,QString adresse)
{

this->cin=cin;
   this->id=id;
    this->number=number;
    this->adresse=adresse;
 this->nom=nom;
  this->prenom=prenom;
}
int client_b::getid(){return  id;}
QString client_b::getnom(){return nom;}
QString client_b::getprenom(){return  prenom;}
void client_b::setid(int id){this->id=id;}
void client_b::setnom (QString nom){this->nom=nom;}
void client_b::setprenom(QString prenom){this->prenom=prenom;}
void client_b::setcin(int cin){this->cin=cin;}
int client_b::getcin(){return  cin;}

bool client_b::ajouter()
{

    QSqlQuery query;

    QString id_string=QString::number(id);
          query.prepare("INSERT INTO GS_CLIENT (CIN,ID,NOM,PRENOM,ADRESSE,NUM_TEL)"
                        "VALUES (:cin, :id, :nom,:prenom,:adresse,:number)");


           query.bindValue(":cin",cin);
           query.bindValue(":id",id_string);
           query.bindValue(":nom",nom);
           query.bindValue(":prenom",prenom);
             query.bindValue(":adresse",adresse);
             query.bindValue(":number",number);

          //query.exec();

         /*    query.prepare("INSERT INTO GS_EMPLOYÉ (CIN,NOM,PRENOM,NUM_TEL,ADRESSE,MAIL,FONCTION,MOT_DE_PASSE)" "values (:CIN, :nom, :prenom, :num, :adresse, :mail, :fonction, :mdp)");
             query.bindValue(":CIN",c);
             query.bindValue(":nom",nom);
             query.bindValue(":prenom",prenom);
             query.bindValue(":num",num);
             query.bindValue(":adresse",adresse);
             query.bindValue(":mail",mail);
             query.bindValue(":fonction",fonction);
             query.bindValue(":mdp",mdp);*/














    return  query.exec();
}

QSqlQueryModel *client_b::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();


    model->setQuery("select * from GS_CLIENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("NUM"));

    return  model;
}
bool client_b::supprimer(int cin)
{
    QSqlQuery query;

          query.prepare("Delete from GS_client where cin=:cin");


           query.bindValue(":cin",cin);
           return  query.exec();



}



client_b client_b::afficherr(int cin)
{
   /* QSqlQueryModel * model=new QSqlQueryModel();
      QSqlQuery query;
    query.prepare("select * from GS_CLIENT where cin=cin");
client_b c;

    model->setQuery("select * from GS_CLIENT where cin=:cin");
   c.cin= model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    c.id=model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    c.nom=model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    c.prenom=model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
    c.adresse=model->setHeaderData(4,Qt::Horizontal,QObject::tr("ADRESSE"));
    c.number=model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM"));*/
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    // query.prepare("SELECT * FROM GS_CLIENT where cin=:cin");
     //query.bindValue(":cin", cin);
     //model->setQuery(query);
     model->setQuery("select * from GS_CLIENT where cin=:cin");

    query.prepare("SELECT * FROM GS_CLIENT WHERE CIN=:cin");
       query.bindValue(":CIN", cin);
 query.exec();
      client_b c;
      //if (model->rowCount() > 0) {
          //c.cin =model->record(0).value("cin").toInt();
          //c.id =model->record(1).value("id").toInt();
         QSqlRecord record = query.record();
          c.nom=record.value(2).toString();
          c.prenom = query.value(0).toString();
          c.nom=model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
          //c.adresse = model->record(4).value("adresse").toString();
          //c.number = model->record(5).value("num").toInt();

//}
 //if(query.value("nom").toString()=="ds")
 //{
   //  c.nom="eererer";

 //}
  //c.nom=query.value("NOM").toString();
       return  c;
}


 bool client_b::modifier(int cin )
 {


     QSqlQuery query;
     supprimer(cin);
     ajouter();
       /*query.prepare("UPDATE GS_CLIENT SET nom =:nom, prenom=:prenom, adresse=:adresse number=:number WHERE cin =:cin ");

       query.bindValue(":cin",cin);

       query.bindValue(":nom",nom);
       query.bindValue(":prenom",prenom);
         query.bindValue(":adresse",adresse);
         query.bindValue(":number",number);*/



        return  query.exec();
 }
