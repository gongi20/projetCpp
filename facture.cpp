#include "facture.h"
#include "ui_facture.h"
#include "client.h"
#include "client_b.h"
#include "facture.h"
#include "ui_client.h"
#include "vehicule.h"
#include "ui_vehicule.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QTextEdit>
#include <QPainter>
#include <QPdfWriter>
#include <QMessageBox>
#include <QPrinter>

facture::facture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::facture)
{
    ui->setupUi(this);
}

facture::~facture()
{
    delete ui;
}

void facture::on_ajouter_3_clicked()
{
    int ci=ui->lineEdit_12->text().toInt();
 client_b monClient;

QSqlQueryModel *de;
int aae=0;
de=monClient.chercher(ci);
  QString nomSponsor =de->record(0).value("NOM").toString();
if(nomSponsor!="")
{aae++;
}
else
{
    QMessageBox::critical(nullptr, QObject::tr("Erreur de saisie"),
                          QObject::tr(" le client nexsite pas et Le champ CIN est numero  ne doit contenir que des chiffrs."),QMessageBox::Cancel);
    return;


}




if(aae==1)
{

 // Appeler la fonction chercher avec un numéro d'identification
 QSqlQueryModel * modelea=monClient.chercher(ci);
 QString nomSponsor =modelea->record(0).value("NOM").toString();
  QString nomSponsor2=modelea->record(0).value("PRENOM").toString();
  QString nomSponsor3=modelea->record(0).value("ADRESSE").toString();
  int ent=modelea->record(0).value("NUM_TEL").toInt();
  int entt=modelea->record(0).value("CIN").toInt();
  QString en= QString::number(ent);
    long int al=rand();
    QString te = QString::number(al);
    texte=new QTextEdit();
    QString text;
    QString t="   rtrdujhujdriujtd     ";
    QString s=ui->lineEdit_12->text();
    QString prix=ui->lineEdit_16->text();
    float prixx=prix.toFloat();
     float prixx2=prix.toFloat();
        QString tva=ui->lineEdit_13->text();
         float tvaa=tva.toFloat();
         float tvaa3=tva.toFloat();
        tvaa=((tvaa*prixx)/100)+prixx;
       float tvaa2=(((tvaa3*prixx)/100));
      //QString  tvaf=QString::number(tvaa);
QString ad=ui->comboBox_4->currentText();
     QString tvaf= QString::number(tvaa, 'f', 0);
   QString d= ui->lineEdit_17->text();
    text+="<!DOCTYPE html>"
          "<html >"
          "<head>"
 "  <style>"
                "body {"
"background-image: url('images.jpg');"
                  "background-repeat :no-repeat;"
                   "background-size: cover ;"

                 "}"

           " h2{font-size: 40px; font-weight:normal; margin-top:300px; margin-bottom:0px; margin-left:200px;}"
   " p{font-size: 20px; font-weight:normal; margin-top:35px; margin-bottom:40px; margin-left:550px;}"

            " d{font-size: 28px; font-weight:normal; margin-top:35px; margin-bottom:0px; margin-left:500px;}"


 " c{font-size: 28px; font-weight:normal; margin-top:3px; margin-bottom:0px; margin-left:0px;}"
            " p2{font-size: 25px; font-weight:normal;margin-top:95px; margin-bottom:50px; margin-left:600px;}"

               "</style>"





          "</head>"
            "<body>"

"<h2>centre de viste technique</h2>"



            "<p>"+te+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+d+"</p>"
             "<c>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Cin:"+s+"</c>"
           "<br>"
        "<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Nom:"+nomSponsor+"</p2>"
             "<br>"
"<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Prenom:"+nomSponsor2+"</p2>"
"<br>"
"<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Adresse:"+nomSponsor3+"</p2>"
                                                                                                                                                                                                                                                                                                                                                                                                                           "<br>"
                                                                                                                                                                                                                                                                                                                                                                                                                           "<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Numero:"+en+"</p2>"
          "</body>"
          "</html>";


/* "<div style=\"position: absolute; left:50px;top:-30px; font-size: 40px;width:300px;height:150px;\">"+s+"</>"*/
     QString html("<html><head><meta charset='utf-8' /><style>img{width:50px; height:50px;} ul{list-style-type: none;font-size:1.5em; width:22%; height:200px; float:right; margin-right:100px; margin-bottom:10px; margin-top:25px;}#p{margin-top:100px; margin-bottom:0px;} #titre_principal{color:blue; width:30%; margin-right:68%;} #logo{width:20%; height:150px; margin-bottom: 0px;} h1{font-size:2.2em; font-weight:normal; margin-left:-17px; width:20%;} h2{font-size:4.3em; font-weight:normal; margin-top:200px; margin-bottom:500px; margin-left:500px;} header{font-family: Helvetica, Arial, serif;}</style><title>Premiers tests du CSS</title></head><body><header><nav><ul><li> Douala, le .............</li><li><div id='p'>Le Principal</li></ul></nav><div id='titre_principal'><img src='C:/Users/Gaël/Pictures/modif/logo.jpg' alt='Logo college' id='logo' /><h1>I.P.G.</h1><h2>"+s+"</h2></div></header></body></html>");
     texte->setHtml(text);
     if(ui->comboBox_5->currentText()=="1" || ui->comboBox_5->currentText()=="2" || ui->comboBox_5->currentText()=="3")
    {
     client_b v;
     QSqlQueryModel * modeleav=v.chercher_vehi(ui->lineEdit_19->text());
     QString nomv=modeleav->record(0).value("MATRICULE").toString();
      QString nomveh=modeleav->record(0).value("MODELE").toString();
      QString nomveh2=modeleav->record(0).value("MARQUE").toString();
      QString ane=modeleav->record(0).value("ANNEE_FABRICATION").toString();
      QString type=modeleav->record(0).value("TYPE_CARBURANT").toString();





     text+="<!DOCTYPE html>"
           "<html >"
           "<head>"
  "  <style>"

            " h2{font-size: 40px; font-weight:normal; margin-top:300px; margin-bottom:0px; margin-left:200px;}"
    " p2{font-size: 15px; }"

             " d{font-size: 28px; font-weight:normal; margin-top:35px; margin-bottom:0px; margin-left:500px;}"


  " c{font-size: 28px; font-weight:normal; margin-top:3px; margin-bottom:0px; margin-left:0px;}"
             " p2{font-size: 25px; font-weight:normal;margin-top:95px; margin-bottom:50px; margin-left:600px;}"

                "</style>"





           "</head>"
             "<body>"





      "<br>"
              "<br>"
              "<br>"
              "<br>"
              "<br>"
             "<br>"
             "<br>"
 "<p2>&nbsp;&nbsp;&nbsp;"+nomv+"</p2>"
             "<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+nomveh2+"</p2>"
"<p2>&nbsp;&nbsp;"+nomveh+"</p2>"
             "<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+ane+"</p2>"

                      "<p2>&nbsp;"+type+"</p2>"

    "<p2>&nbsp;"+prix+"</p2>"
             "<p2>&nbsp;&nbsp;&nbsp;"+tvaf+"</p2>"
           "</body>"
           "</html>";
      texte->setHtml(text);


      if(ui->comboBox_5->currentText()=="1")
      {
        //  tvaa2=(tvaa2)-(prixx2);
 tvaa2=tvaa2;
          tvaa=(tvaa-prixx)*3;
     prixx=prix.toFloat();
          prixx2=prixx2*1;
          float prixf=prixx2+tvaa2;
          QString ta= QString::number(prixx2);
    QString prixff= QString::number(prixf);
           QString tav= QString::number(tvaa2);
          text+="<!DOCTYPE html>"
                "<html >"
                "<head>"
       "  <style>"

                 " h2{font-size: 40px; font-weight:normal; margin-top:300px; margin-bottom:0px; margin-left:200px;}"
         " p{font-size: 20px; font-weight:normal; margin-top:35px; margin-bottom:40px; margin-left:550px;}"

                  " d{font-size: 28px; font-weight:normal; margin-top:35px; margin-bottom:0px; margin-left:500px;}"


       " c{font-size: 28px; font-weight:normal; margin-top:3px; margin-bottom:0px; margin-left:0px;}"
                  " p2{font-size: 25px; font-weight:normal;margin-top:95px; margin-bottom:50px; margin-left:600px;}"

                     "</style>"





                "</head>"
                "<body>"



     "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                  "<br>""<br>"








"<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+ta+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+tav+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+prixff+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+prixff+"&nbsp;&nbsp;&nbsp;&nbsp;Payment:"+ad+"</p2>"                                                                                                                                                                                                                                                                                                                        "<br>"

"<p2> </p2>"
              "</body>"
                "</html>";
        texte->setHtml(text);
      }
     }
     if(ui->comboBox_5->currentText()=="2" || ui->comboBox_5->currentText()=="3")
    {
     client_b v;
     QSqlQueryModel * modeleav=v.chercher_vehi(ui->lineEdit_20->text());
     QString nomv=modeleav->record(0).value("MATRICULE").toString();
      QString nomveh=modeleav->record(0).value("MODELE").toString();
      QString nomveh2=modeleav->record(0).value("MARQUE").toString();
      QString ane=modeleav->record(0).value("ANNEE_FABRICATION").toString();
      QString type=modeleav->record(0).value("TYPE_CARBURANT").toString();





     text+="<!DOCTYPE html>"
           "<html >"
           "<head>"
  "  <style>"

            " h2{font-size: 40px; font-weight:normal; margin-top:300px; margin-bottom:0px; margin-left:200px;}"
    " p{font-size: 20px; font-weight:normal; margin-top:35px; margin-bottom:40px; margin-left:550px;}"

             " d{font-size: 28px; font-weight:normal; margin-top:35px; margin-bottom:0px; margin-left:500px;}"


  " c{font-size: 28px; font-weight:normal; margin-top:3px; margin-bottom:0px; margin-left:0px;}"
             " p2{font-size: 25px; font-weight:normal;margin-top:95px; margin-bottom:50px; margin-left:600px;}"

                "</style>"





           "</head>"
           "<body>"





            "<br>"
           "<br>"
           "<br>"
"<p2>&nbsp;&nbsp;&nbsp;"+nomv+"</p2>"
           "<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+nomveh2+"</p2>"
"<p2>&nbsp;&nbsp;"+nomveh+"</p2>"
           "<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+ane+"</p2>"

                    "<p2>&nbsp;"+type+"</p2>"

  "<p2>&nbsp;"+prix+"</p2>"
           "<p2>&nbsp;&nbsp;&nbsp;"+tvaf+"</p2>"
         "</body>"
           "</html>";
      texte->setHtml(text);
      prixx=prixx*2;
      tvaa=tvaa*2;

      if(ui->comboBox_5->currentText()=="2")
      {

          tvaa2=tvaa2*2;

          tvaa=(tvaa-prixx)*2;
     prixx=prix.toFloat();
          prixx2=prixx2*2;
          float prixf=prixx2+tvaa2;
          QString ta= QString::number(prixx2);
    QString prixff= QString::number(prixf);
           QString tav= QString::number(tvaa2);
          text+="<!DOCTYPE html>"
                "<html >"
                "<head>"
       "  <style>"

                 " h2{font-size: 40px; font-weight:normal; margin-top:300px; margin-bottom:0px; margin-left:200px;}"
         " p{font-size: 20px; font-weight:normal; margin-top:35px; margin-bottom:40px; margin-left:550px;}"

                  " d{font-size: 28px; font-weight:normal; margin-top:35px; margin-bottom:0px; margin-left:500px;}"


       " c{font-size: 28px; font-weight:normal; margin-top:3px; margin-bottom:0px; margin-left:0px;}"
                  " p2{font-size: 25px; font-weight:normal;margin-top:95px; margin-bottom:50px; margin-left:600px;}"

                     "</style>"





                "</head>"
                "<body>"



     "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"
                "<br>"







"<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+ta+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+tav+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+prixff+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+prixff+"&nbsp;&nbsp;&nbsp;&nbsp;Payment:"+ad+"</p2>"
              "</body>"
                "</html>";
        texte->setHtml(text);
      }





     }
     if(ui->comboBox_5->currentText()=="3")
    {
     client_b v;
     QSqlQueryModel * modeleav=v.chercher_vehi(ui->lineEdit_21->text());
     QString nomv=modeleav->record(0).value("MATRICULE").toString();
      QString nomveh=modeleav->record(0).value("MODELE").toString();
      QString nomveh2=modeleav->record(0).value("MARQUE").toString();
      QString ane=modeleav->record(0).value("ANNEE_FABRICATION").toString();
      QString type=modeleav->record(0).value("TYPE_CARBURANT").toString();





     text+="<!DOCTYPE html>"
           "<html >"
           "<head>"
  "  <style>"

            " h2{font-size: 40px; font-weight:normal; margin-top:300px; margin-bottom:0px; margin-left:200px;}"
    " p{font-size: 20px; font-weight:normal; margin-top:35px; margin-bottom:40px; margin-left:550px;}"

             " d{font-size: 28px; font-weight:normal; margin-top:35px; margin-bottom:0px; margin-left:500px;}"


  " c{font-size: 28px; font-weight:normal; margin-top:3px; margin-bottom:0px; margin-left:0px;}"
             " p2{font-size: 25px; font-weight:normal;margin-top:95px; margin-bottom:50px; margin-left:600px;}"

                "</style>"





           "</head>"
           "<body>"





           "<br>"
           "<br>"
"<p2>&nbsp;&nbsp;&nbsp;"+nomv+"</p2>"
           "<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+nomveh2+"</p2>"
"<p2>&nbsp;&nbsp;"+nomveh+"</p2>"
           "<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+ane+"</p2>"

                    "<p2>&nbsp;"+type+"</p2>"

  "<p2>&nbsp;"+prix+"</p2>"
           "<p2>&nbsp;&nbsp;&nbsp;"+tvaf+"</p2>"
         "</body>"
           "</html>";
      texte->setHtml(text);
      tvaa2=tvaa2*3;
      tvaa=(tvaa-prixx)*3;
 prixx=prix.toFloat();
      prixx2=prixx2*3;
      float prixf=prixx2+tvaa2;
      QString ta= QString::number(prixx2);
QString prixff= QString::number(prixf);
       QString tav= QString::number(tvaa2);
      text+="<!DOCTYPE html>"
            "<html >"
            "<head>"
   "  <style>"

             " h2{font-size: 40px; font-weight:normal; margin-top:300px; margin-bottom:0px; margin-left:200px;}"
     " p{font-size: 20px; font-weight:normal; margin-top:35px; margin-bottom:40px; margin-left:550px;}"

              " d{font-size: 28px; font-weight:normal; margin-top:35px; margin-bottom:0px; margin-left:500px;}"


   " c{font-size: 28px; font-weight:normal; margin-top:3px; margin-bottom:0px; margin-left:0px;}"
              " p2{font-size: 25px; font-weight:normal;margin-top:95px; margin-bottom:50px; margin-left:600px;}"

                 "</style>"





            "</head>"
            "<body>"



 "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"
            "<br>"




            "<p2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+ta+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+tav+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+prixff+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+prixff+"&nbsp;&nbsp;&nbsp;&nbsp;Payment:"+ad+"</p2>"
          "</body>"
            "</html>";
    texte->setHtml(text);

     }
}

     QPrinter imprimer;
    imprimer.setOrientation(QPrinter::Portrait);
    QPrintPreviewDialog dialog(&imprimer,this);
    connect(&dialog,SIGNAL(paintRequested(QPrinter*)),this,SLOT(print(QPrinter*)));
    dialog.showMaximized();
    dialog.exec();
    client c;
}



void facture::print(QPrinter *printer)
{

    texte->print(printer);
}
