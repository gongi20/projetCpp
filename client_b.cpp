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
#include "mainwindow.h"

#include <QMainWindow>
#include "ui_mainwindow.h"

client_b::client_b()
{

     id=0;
    number=0;
    nom="";
    prenom="";
    cin=0;
    adresse="";
    arduino b;
    b.write_to_arduino("1");

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
          query.prepare("INSERT INTO GS_CLIENT (CIN,NOM,PRENOM,ADRESSE,NUM_TEL)"
                        "VALUES (:cin,:nom,:prenom,:adresse,:number)");


           query.bindValue(":cin",cin);

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


bool client_b::ajouterparking(QString a,QString b)
{

    QSqlQuery query;


          query.prepare("INSERT INTO PARKING (MATRICULE,TEMPS)"
                        "VALUES (:MATRICULE,:TEMPS)");


           query.bindValue(":MATRICULE",a);

           query.bindValue(":TEMPS",b);
















    return  query.exec();
}






QSqlQueryModel *client_b::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();


 model->setQuery("select * from GS_CLIENT");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));




    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("NUM"));

    return  model;
}



QSqlQueryModel *client_b::trie(QString s,QString f)
{
    QSqlQueryModel * model=new QSqlQueryModel();


 model->setQuery("select * from GS_CLIENT ORDER BY "+s+" "+f+" ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));




    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("NUM"));

    return  model;
}
QSqlQueryModel *client_b::chercherr(QString n)
{
    QSqlQuery query;
       QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM GS_CLIENT WHERE  NOM LIKE '%"+n+"%' ");



       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("NUM"));

       return model;

}
int client_b::calcul()
{
    QSqlQuery query;

          query.prepare("SELECT COUNT(*) FROM GS_client");
          if (query.exec() && query.next()) {
                  return query.value(0).toInt();
              } else {
                  // La requête a échoué ou n'a pas renvoyé de résultats
                  return -1; // Ou toute autre valeur d'erreur
              }
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

QSqlQueryModel * client_b::chercher(int cin)
{
    QSqlQueryModel * model=new QSqlQueryModel();


     QSqlQuery query;
        query.prepare("SELECT * FROM GS_CLIENT where cin=:cin");
        query.bindValue(":cin", cin);
        query.exec();
        model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));

     model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("ADRESSE"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("NUM"));
    return model;
}

QSqlQueryModel * client_b::chercher_vehi( QString MATRICULE)
{
    QSqlQueryModel * model=new QSqlQueryModel();


     QSqlQuery query;
        query.prepare("SELECT * FROM GS_VEHICULE where MATRICULE=:MATRICULE");
        query.bindValue(":MATRICULE", MATRICULE);
        query.exec();
        model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("MATRICULE"));

     model->setHeaderData(2,Qt::Horizontal,QObject::tr("MARQUE"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("MODELE"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("DESCRIPTION"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ANNEE_FABRICATION"));
      model->setHeaderData(7,Qt::Horizontal,QObject::tr("TYPE_CARBURANT"));
       model->setHeaderData(8,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    return model;
}
/*void MainWindow::on_rechercher_clicked()
{  Sponsor S;
    QString nom = ui->lineEdit_rechercher->text();
        QSqlQueryModel * model = S.chercher(nom);
        ui->tableView->setModel(model);
}*/




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
 bool client_b::verifierint(int x,int y){

     if(!x && !y){

             return false;}
     else if(!x && y && y>0){

             return false;}
     else if(!x && y && y<1){

             return false;}
     else if(x && x>0 && !y){

             return false;}
     else if(x && x<1 && !y){

             return false;}
     else if(x && y && x<1 && y<1){

             return false;}

     else {

         return true;}
 }
 bool client_b::verifierint1(int x){

     if(!x){

             return false;}

     else if(x && x>0 ){

             return false;}
     else if(x && x<1 ){

             return false;}
     else if(x  && x<1 ){

             return false;}

     else {

         return true;}
 }

 QSqlQueryModel * client_b::chercherre(int cin)
 {
     QSqlQueryModel * model=new QSqlQueryModel();


      QSqlQuery query;
         query.prepare("SELECT * GS_RENDEZV where ID_CLIENT=:ID_CLIENT");
         query.bindValue(":ID_CLIENT", cin);
         query.exec();
         model->setQuery(query);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_RDV"));

      model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_RDV"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("HEURE"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("STATUT"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID_CLIENT"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID_EMPLOYE"));
     return model;
 }

int client_b::calcultunis()
 {


     QSqlQuery query;
     QSqlQuery query2;

        int cp=0;
        int ca=0;
         int f;
         int count2=0;
         int count=0;
         query2.prepare("SELECT COUNT(CIN) FROM  GS_CLIENT ");
         query2.exec();
         while (query2.next()) {
              count2 =query2.value(0).toInt();

         }










query.prepare("SELECT COUNT (ADRESSE) FROM  GS_CLIENT where  ADRESSE=:ADRESSE");
query.bindValue(":ADRESSE","tunis");
 query.exec();

    // Récupération du résultat
    while (query.next()) {
         count = query.value(0).toInt();

    }

    return (count*100)/count2;







 }



int client_b::calculben()
{


    QSqlQuery query;
    QSqlQuery query2;

       int cp=0;
       int ca=0;
        int f;
        int count2=0;
        int count=0;
        query2.prepare("SELECT COUNT(CIN) FROM  GS_CLIENT ");
        query2.exec();
        while (query2.next()) {
             count2 =query2.value(0).toInt();

        }










query.prepare("SELECT COUNT (ADRESSE) FROM  GS_CLIENT where  ADRESSE=:ADRESSE");
query.bindValue(":ADRESSE","Ben arouse");
query.exec();

   // Récupération du résultat
   while (query.next()) {
        count = query.value(0).toInt();

   }

   return (count*100)/count2;







}

int client_b::calculmanouba()
{


    QSqlQuery query;
    QSqlQuery query2;

       int cp=0;
       int ca=0;
        int f;
        int count2=0;
        int count=0;
        query2.prepare("SELECT COUNT(CIN) FROM  GS_CLIENT ");
        query2.exec();
        while (query2.next()) {
             count2 =query2.value(0).toInt();

        }










query.prepare("SELECT COUNT (ADRESSE) FROM  GS_CLIENT where  ADRESSE=:ADRESSE");
query.bindValue(":ADRESSE","Manouba");
query.exec();

   // Récupération du résultat
   while (query.next()) {
        count = query.value(0).toInt();

   }

   return (count*100)/count2;







}

int client_b::calculariana()
{


    QSqlQuery query;
    QSqlQuery query2;

       int cp=0;
       int ca=0;
        int f;
        int count2=0;
        int count=0;
        query2.prepare("SELECT COUNT(CIN) FROM  GS_CLIENT ");
        query2.exec();
        while (query2.next()) {
             count2 =query2.value(0).toInt();

        }










query.prepare("SELECT COUNT (ADRESSE) FROM  GS_CLIENT where  ADRESSE=:ADRESSE");
query.bindValue(":ADRESSE","Ariana");
query.exec();

   // Récupération du résultat
   while (query.next()) {
        count = query.value(0).toInt();

   }

   return (count*100)/count2;







}

int client_b::calculaut()
{


    QSqlQuery query;
    QSqlQuery query2;

       int cp=0;
       int ca=0;
        int f;
        int count2=0;
        int count=0;
        query2.prepare("SELECT COUNT(CIN) FROM  GS_CLIENT ");
        query2.exec();
        while (query2.next()) {
             count2 =query2.value(0).toInt();

        }










query.prepare("SELECT COUNT (ADRESSE) FROM  GS_CLIENT where  ADRESSE=:ADRESSE");
query.bindValue(":ADRESSE","Autre");
query.exec();

   // Récupération du résultat
   while (query.next()) {
        count = query.value(0).toInt();

   }
   count++;

   return (count*100)/count2;







}

QSqlQueryModel * client_b::chercherve(int cin,QString p)
{
    QSqlQueryModel * model=new QSqlQueryModel();


     QSqlQuery query;
        query.prepare("SELECT * FROM GS_RENDEZV where MATRICULE=:MATRICULE  ");
        query.bindValue(":MATRICULE", cin);
        query.bindValue(":DATE_RDV", p);
        query.exec();
        model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_RDV"));

     model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_RDV"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("HEURE"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("STATUT"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("ID_EMPLOYE"));
     model->setHeaderData(8,Qt::Horizontal,QObject::tr("MATRICULE"));

    return model;
}

QSqlQueryModel * client_b::cherchernbv()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    int a;
    QString ve = "v";

     QSqlQuery query;
        query.prepare("SELECT NBR FROM NBR_VOITURE where ID=:id  ");
        query.bindValue(":id", ve);
        query.exec();
        model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("NBR"));

    return model;
}

bool client_b::modifierp(int a) {
    QSqlQuery query;

    QString ve="v";
    query.prepare("UPDATE NBR_VOITURE SET NBR=:NBR WHERE ID=:ve");
    query.bindValue(":NBR",a);

    return query.exec();
}

QSqlQueryModel *client_b::afficherpa()
{
    QSqlQueryModel * model=new QSqlQueryModel();


 model->setQuery("select * from NBR_VOITURE");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));




    return  model;
}
